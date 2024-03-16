#include "imagefilter.h"
#include <QImage>
#include <QTime>
#include <cmath>
#include <QtAlgorithms>
#include <QRandomGenerator>

// FilterGrayscale

void FilterGrayscale::filter(QImage *img) const
{
    for (int y = 0; y < img->height(); ++y) {
        for (int x = 0; x < img->width(); ++x) {
            const QRgb rgb = img->pixel(x, y);
            const int r = qRed(rgb);
            const int g = qGreen(rgb);
            const int b = qBlue(rgb);
            const int gray = (77 * r + 150 * g + 29 * b) / 256;
            // 正しくは Y = ( 0.298912 * R + 0.586611 * G + 0.114478 * B ) だが整数でやりたくてこう近似した。
            img->setPixel(x, y, qRgb(gray, gray, gray));
        }
    }
}

// FilterTwoLebelByThreshold

FilterTwoLebelByThreshold::FilterTwoLebelByThreshold(int threshold) :
    m_threshold(threshold)
{
}

void FilterTwoLebelByThreshold::filter(QImage *img) const
{
    const QRgb rgbMin = qRgb(0, 0, 0);
    const QRgb rgbMax = qRgb(255, 255, 255);
    FilterGrayscale gs;
    gs.filter(img);
    for (int y = 0; y < img->height(); ++y) {
        for (int x = 0; x < img->width(); ++x) {
            const int value = qRed(img->pixel(x, y));
            const QRgb pixel = (value < m_threshold)
                    ? rgbMin
                    : rgbMax;
            img->setPixel(x, y, pixel);
        }
    }
}

// FilterTwoLebelByErrorDiffusion

void FilterTwoLebelByErrorDiffusion::filter(QImage *img) const
{
    const QRgb rgbMin = qRgb(0, 0, 0);
    const QRgb rgbMax = qRgb(255, 255, 255);
    const int threshold = 128;
    const int dx[] = {1,-1,0,1};
    const int dy[] = {0,1,1,1};  // y が増加するようにしろ (乗算回避のための特殊化)
    const int rate[] = {7,3,5,1};
    FilterGrayscale gs;
    gs.filter(img);
    QVector<int> temp(img->width() * img->height());  // int 型バッファ
    int numY = 0;
    for (int y = 0; y < img->height(); ++y) {  // 画像をバッファに転写
        for (int x = 0; x < img->width(); ++x) {
            temp[numY + x] = qRed(img->pixel(x, y));
        }
        numY += img->width();
    }
    numY = 0;
    for (int y = 0; y < img->height(); ++y) {  // 誤差拡散法
        for (int x = 0; x < img->width(); ++x) {
            const int f = temp[numY + x];
            const int e = (f < threshold)
                ? f
                : f - 255;
            img->setPixel(x, y, (f < threshold) ? rgbMin : rgbMax);  // 画素決定

            int numMY = numY;
            int myBefore = y + dy[0];
            for (int i = 0; i < sizeof(rate) / sizeof(rate[0]); ++i) {
                const int mx = x + dx[i];
                const int my = y + dy[i];
                if (mx >= 0 && mx < img->width() && my >= 0 && my < img->height()) {
                    while (my > myBefore) {
                        numMY += img->width();
                        ++myBefore;
                    }
                    temp[numMY + mx] += ((rate[i] * e) / 16);
                }
            }
        }
        numY += img->width();
    }
}

// LinearFilter

LinearFilter::LinearFilter(const QVector< QVector<int> > &mask, const int denominator, const bool absolute) :
    m_mask(mask),
    m_denominator(denominator),
    m_absolute(absolute),
    m_available(checkMask())
{
}

bool LinearFilter::checkMask() const
{
    if (m_denominator == 0) {
        return false;
    }
    if (m_mask.size() % 2 == 0) {  // 同時に m_mask.size() == 0 の場合も除外している。
        return false;
    }
    const size_t cols = m_mask[0].size();
    if (cols % 2u == 0u) {
        return false;
    }
    for (auto it = m_mask.begin(); it != m_mask.end(); ++it) {
        if (it->size() != cols) {
            return false;
        }
    }
    return true;
}

void LinearFilter::filter(QImage *img) const
{
    if (!m_available) {
        return;
    }
    struct AfterProcess {  // 3色共通の後処理用ローカル関数
        inline int operator()(const int x) const
        {
            int y = x / m_denominator;
            if (y < 0) {
                y = m_absolute ? abs(y) : 0;
            }
            return (y > 255) ? 255 : y;
        }
        AfterProcess(const int denominator, const bool absolute) :
            m_denominator(denominator),
            m_absolute(absolute) { }
    private:
        const int m_denominator;
        const bool m_absolute;
    } afterProcess(m_denominator, m_absolute);
    const int centerY = static_cast<int>(m_mask.size() / 2);
    const int centerX = static_cast<int>(m_mask.begin()->size() / 2);
    QImage temp(img->width(), img->height(), img->format());  // バッファ
    for (int y = 0; y < img->height(); ++y) {
        for (int x = 0; x < img->width(); ++x) {
            int sumR = 0, sumG = 0, sumB = 0;
            for (int dy = -centerY; dy <= centerY; ++dy) {
                const int my = ((y + dy) < 0)
                    ? 0
                    : ((y + dy) >= img->height())
                        ? img->height() - 1
                        : (y + dy);
                for (int dx = -centerX; dx <= centerX; ++dx) {
                    const int mx = ((x + dx) < 0)
                        ? 0
                        : ((x + dx) >= img->width())
                            ? img->width() - 1
                            : (x + dx);
                    const QRgb rgb = img->pixel(mx, my);
                    const int coefficient = m_mask[dy + centerY][dx + centerX];
                    sumR += coefficient * qRed(rgb); sumG += coefficient * qGreen(rgb); sumB += coefficient * qBlue(rgb);
                }
            }
            temp.setPixel(x, y, qRgb(afterProcess(sumR), afterProcess(sumG), afterProcess(sumB)));
        }
    }
    *img = temp;  // バッファから転写
}

// MedianFilter

MedianFilter::MedianFilter(int size) :
    m_size(size), m_available(checkSize())
{
}

bool MedianFilter::checkSize() const
{
    return m_size > 0 && m_size % 2 != 0;
}

void MedianFilter::filter(QImage *img) const
{
    if (!m_available) {
        return;
    }

    const int centerXY = m_size / 2;
    const size_t centerFilter = m_size * m_size / 2;
    QVector<int> neighborListR(m_size * m_size);
    QVector<int> neighborListG(m_size * m_size);
    QVector<int> neighborListB(m_size * m_size);
    QImage temp(img->width(), img->height(), img->format());  // バッファ
    for (int y = 0; y < img->height(); ++y) {
        for (int x = 0; x < img->width(); ++x) {
            int index = 0;
            for (int dy = -centerXY; dy <= centerXY; ++dy) {
                const int my = ((y + dy) < 0)
                    ? 0
                    : ((y + dy) >= img->height())
                        ? img->height() - 1
                        : (y + dy);
                for (int dx = -centerXY; dx <= centerXY; ++dx) {
                    const int mx = ((x + dx) < 0)
                        ? 0
                        : ((x + dx) >= img->width())
                            ? img->width() - 1
                            : (x + dx);
                    const QRgb rgb = img->pixel(mx, my);
                    neighborListR[index] = qRed(rgb);
                    neighborListG[index] = qGreen(rgb);
                    neighborListB[index] = qBlue(rgb);
                    ++index;
                }
            }
            std::sort(neighborListR.begin(), neighborListR.end());
            std::sort(neighborListG.begin(), neighborListG.end());
            std::sort(neighborListB.begin(), neighborListB.end());
            temp.setPixel(x, y, qRgb(neighborListR[centerFilter], neighborListG[centerFilter], neighborListB[centerFilter]));
        }
    }
    *img = temp;  // バッファから転写
}

NormFilter::NormFilter(const QVector<QVector<int> > &maskX, const QVector<QVector<int> > &maskY) :
    m_maskX(maskX), m_maskY(maskY), m_available(checkMask(maskX) && checkMask(maskY))
{
}

bool NormFilter::checkMask(const QVector<QVector<int> > &mask)
{
    if (mask.size() % 2 == 0) {
        return false;
    }
    const size_t cols = mask[0].size();
    if (cols % 2u == 0u) {
        return false;
    }
    for (auto it = mask.begin(); it != mask.end(); ++it) {
        if (it->size() != cols) {
            return false;
        }
    }
    return true;
}

void NormFilter::filter(QImage *img) const
{
    if (!m_available) {
        return;
    }
    struct MyFilter {
        int r, g, b;
        MyFilter(const QImage &img, const QVector< QVector<int> > &mask, int x, int y, int cx, int cy)
            : r(0), g(0), b(0)
        {
            for (int dy = -cy; dy <= cy; ++dy) {
                const int my = ((y + dy) < 0) ? 0
                    : ((y + dy) >= img.height()) ? img.height() - 1
                        : (y + dy);
                for (int dx = -cx; dx <= cx; ++dx) {
                    const int mx = ((x + dx) < 0) ? 0
                        : ((x + dx) >= img.width()) ? img.width() - 1
                            : (x + dx);
                    const QRgb rgb = img.pixel(mx, my);
                    const int coefficient = mask[dy + cy][dx + cx];
                    r += coefficient * qRed(rgb);
                    g += coefficient * qGreen(rgb);
                    b += coefficient * qBlue(rgb);
                }
            }
        }
    };
    auto afterProcess = [](int x, int y) {
        const double x_f = static_cast<double>(x);
        const double y_f = static_cast<double>(y);
        const int z = static_cast<int>(sqrt(x_f * x_f + y_f * y_f) + 0.5);
        return (z > 255) ? 255 : z;
    };
    const int maskXCenterY = static_cast<int>(m_maskX.size() / 2);
    const int maskXCenterX = static_cast<int>(m_maskX.begin()->size() / 2);
    const int maskYCenterY = static_cast<int>(m_maskY.size() / 2);
    const int maskYCenterX = static_cast<int>(m_maskY.begin()->size() / 2);
    QImage temp(img->width(), img->height(), img->format());  // バッファ
    for (int y = 0; y < img->height(); ++y) {
        for (int x = 0; x < img->width(); ++x) {
            MyFilter dx(*img, m_maskX, x, y, maskXCenterX, maskXCenterY);
            MyFilter dy(*img, m_maskY, x, y, maskYCenterX, maskYCenterY);
            temp.setPixel(x, y, qRgb(
                afterProcess(dx.r, dy.r),
                afterProcess(dx.g, dy.g),
                afterProcess(dx.b, dy.b) ));
        }
    }
    *img = temp;
}

// FilterInsertNoise

FilterInsertRandomNoise::FilterInsertRandomNoise(const double noiseDensity) :
    m_noiseDensity(noiseDensity)
{
}

void FilterInsertRandomNoise::filter(QImage *img) const
{
    const int w = img->width();
    const int h = img->height();
    const qint64 noiseNum = static_cast<qint64>(static_cast<double>(w) * static_cast<double>(h) * m_noiseDensity);
    QRandomGenerator::global()->securelySeeded();
    for (qint64 i = 0; i < noiseNum; ++i) {
        const int x = QRandomGenerator::global()->generate() % w;
        const int y = QRandomGenerator::global()->generate() % h;
        img->setPixel(x, y, qRgb(
            QRandomGenerator::global()->generate() % 256,
            QRandomGenerator::global()->generate() % 256,
            QRandomGenerator::global()->generate() % 256));
    }
}
