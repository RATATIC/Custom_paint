#pragma once

#include <QPainter>
#include <cmath>
#include "Figura.h"

class Circle : public Figura
{
public:
	explicit Circle(const int& x, const int& y);
	~Circle();

	bool isInFigura(const int& x, const int& y) const override;
protected:
	int getRadius_X() const;
	int getRadius_Y() const;

	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

