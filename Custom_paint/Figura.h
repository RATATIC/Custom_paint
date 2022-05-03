#pragma once

#include "Item.h"
#include <QGraphicsSceneMouseEvent>
#include <memory>

class Figura : public Item 
{
public:
	explicit Figura(const int& x, const int& y);
	~Figura();

	virtual bool isInFigura(const int& x, const int& y) const = 0;

	void move(const int& x, const int& y) override;
	void startMove(const int& x, const int& y) override;

	void changeSize(const int& x, const int& y);
	
	std::shared_ptr<Point> getCenterPoint()const;

	int getCenter_X() const;
	int getCenter_Y() const;
protected:
	void changeCenterPoint();

	std::shared_ptr <Point> center_point;
	Point previous_point;

	QRectF boundingRect() const;
};