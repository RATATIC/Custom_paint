#pragma once

#include <QPainter>
#include <cmath>
#include "Figura.h"

class Circle : public Figura
{
public:
	Circle(const int& x, const int& y);
	~Circle();

protected:
	int getRadius_X() const;
	int getRadius_Y() const;

	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

