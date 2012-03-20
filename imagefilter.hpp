#ifndef IMAGEFILTER_HPP
#define IMAGEFILTER_HPP

#include <QVector>

class QImage;

class IImageFilter	// interface
{
public:
	virtual void filter(QImage *img) const = 0;	// abstract method
};

class FilterGrayscale : public IImageFilter
{
public:
	void filter(QImage *img) const;
};

class FilterTwoLebelByThreshold : public IImageFilter
{
public:
	FilterTwoLebelByThreshold(int threshold);
	void filter(QImage *img) const;
private:
	int m_threshold;
};

class FilterTwoLebelByErrorDiffusion : public IImageFilter
{
public:
	void filter(QImage *img) const;
};

class LinearFilter : public IImageFilter
{
public:
	LinearFilter(const QVector< QVector<int> > &mask, const int denominator = 1, const bool absolute = false);
	void filter(QImage *img) const;
private:
	const QVector< QVector<int> > m_mask;
	const int m_denominator;
	const bool m_absolute;
	const bool m_available;
	bool checkMask() const;
};

class MedianFilter : public IImageFilter
{
public:
	MedianFilter(int size = 3);
	void filter(QImage *img) const;
private:
	int m_size;
	bool m_available;
	bool checkSize() const;
};

class NormFilter : public IImageFilter
{
public:
	NormFilter(const QVector< QVector<int> > &maskX, const QVector< QVector<int> > &maskY);
	void filter(QImage *img) const;
private:
	const QVector< QVector<int> > m_maskX, m_maskY;
	const bool m_available;
	static bool checkMask(const QVector< QVector<int> > &mask);
};

#endif // IMAGEFILTER_HPP
