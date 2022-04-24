#pragma once

#include "Item.h"
#include <QPainter>

class Line : public Item
{
public:
	Line(const int& x, const int& y);
	~Line();
protected :
	QRectF boundingRect() const;

	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

