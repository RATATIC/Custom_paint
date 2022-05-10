#pragma once

#include <QPainter>
#include "Figura.h"

class Rectangle : public Figura
{
public :
	explicit Rectangle(const int& x, const int& y);
	explicit Rectangle(const Point& point1, const Point& point2);

	~Rectangle();

	bool isInFigura(const int& x, const int& y) const override;
	std::string getType()const override;

	static const std::string TYPE;
protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

	static unsigned int count;
};

