#pragma once

#include <QPainter>
#include "Figura.h"

class Rectangle : public Figura
{
public :
	Rectangle(const int& x, const int& y);
	~Rectangle();

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

