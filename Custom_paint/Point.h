#pragma once
#include <cmath>

class Point
{
public:
	Point();
	explicit Point(const int& x, const int& y);
	~Point();
	int getX()const;
	int getY()const;
	void setX(const int& x);
	void setY(const int& y);
	void setPoint(const int& x, const int& y);

	int getMiggleX(const Point& point)const;
	int getMiggleY(const Point& point)const;
private:
	int _x;
	int _y;
};
