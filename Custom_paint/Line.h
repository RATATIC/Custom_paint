#pragma once

#include "Item.h"
#include <QPainter>
#include <memory>

class Line : public Item
{
public:
	explicit Line(const int& x, const int& y);
	explicit Line(std::shared_ptr <Point> point);
	~Line();

	void move(const int& x, const int& y) override {}
	void startMove(const int& x, const int& y) override {}

	void bindPoint(std::shared_ptr <Point> point);

protected :
	QRectF boundingRect() const;

	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

