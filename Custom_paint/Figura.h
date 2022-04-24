#pragma once

#include "Item.h"

class Figura : public Item 
{
public:
	Figura(const int& x, const int& y);
	~Figura();
protected:
	int getCenter_X() const;
	int getCenter_Y() const;

	QRectF boundingRect() const;
};

