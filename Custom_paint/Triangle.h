#pragma once
#include "Figura.h"
#include <QPainter>
#include <cmath>

class Triangle : public Figura
{
public:
	explicit Triangle(const int& x, const int& y);
	~Triangle();

	bool isInFigura(const int& x, const int& y) const override;
protected:
	int getMiddleSide_X() const;

	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

