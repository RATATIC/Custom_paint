#pragma once

#include <QPainter>
#include <cmath>
#include "Figura.h"

class Circle : public Figura
{
public:
	explicit Circle(const int& x, const int& y);
	explicit Circle(const Point& point1, const Point& point2);
	~Circle();

	bool isInFigura(const int& x, const int& y) const override;
	std::string getType()const override;

	static const std::string TYPE;
protected:
	int getRadius_X() const;
	int getRadius_Y() const;

	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

	static unsigned int count;
};

