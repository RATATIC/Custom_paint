#include "Point.h"

Point::Point() : _x(0), _y(0) {

}

Point::Point(const int& x, const int& y) : _x(x), _y(y) {

}

Point::~Point() {

}
int Point::getX()const {
	return _x;
}
int Point::getY()const {
	return _y;
}
void Point::setX(const int& x) {
	this->_x = x;
}
void Point::setY(const int& y) {
	this->_y = y;
}

void Point::setPoint(const int& x, const int& y) {
	this->_x = x;
	this->_y = y;
}

int Point::getMiggleX(const Point& point)const {
	return _x > point.getX() ? point.getX() + std::abs(_x - point.getX()) / 2 : _x + std::abs(point.getX() - _x) / 2;
}

int Point::getMiggleY(const Point& point)const {
	return _y > point.getY() ? point.getY() + std::abs(_y - point.getY()) / 2 : _y + std::abs(point.getY() - _y) / 2;
}