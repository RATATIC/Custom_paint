#pragma once
#include "Figura.h"
#include <QPainter>
#include <cmath>

class Triangle : public Figura
{
public:
	Triangle(const int& x, const int& y);
	~Triangle();
protected:
	int getMiddleSide_X() const;

	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

