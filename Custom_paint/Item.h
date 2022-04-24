#pragma once

#include <QtWidgets/QGraphicsItem>

class Item : public QGraphicsItem
{
public :
	Item(const int& x, const int& y);
	virtual ~Item();

	int getX1()const;
	int getY1()const;
	int getX2()const;
	int getY2()const;

	void change_x2_and_y2(const int& x, const int& y);
protected :
	int x1;
	int x2;
	int y1;
	int y2;
};

