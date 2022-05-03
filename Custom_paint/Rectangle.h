#pragma once

#include <QPainter>
#include "Figura.h"

class Rectangle : public Figura
{
public :
	explicit Rectangle(const int& x, const int& y);
	~Rectangle();

	bool isInFigura(const int& x, const int& y) const override;

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

