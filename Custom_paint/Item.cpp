#include "Item.h"

Item::Item(const int& x, const int& y, QObject* parent ) : QObject(parent) {
	_point1 = std::make_shared<Point>(x, y);
	_point2 = std::make_shared<Point>(x, y);
}

Item::Item(const Point& point1, const Point& point2, QObject* parent) : QObject(parent) {
	_point1 = std::make_shared<Point>(point1);
	_point2 = std::make_shared<Point>(point2);
}

Item::Item(std::shared_ptr<Point> point, QObject* parent) : QObject(parent) {
	_point1 = point; 
	_point2 = std::make_shared<Point> (point->getX(), point->getY());
}

Item::~Item() {}

std::shared_ptr<Point> Item::getPoint1()const {
	return _point1;
}
std::shared_ptr<Point> Item::getPoint2()const {
	return _point2;
}

void Item::setPoint1(const int& x, const int& y) {
	_point1->setX(x);
	_point1->setY(y);
}
void Item::setPoint2(const int& x, const int& y) {
	_point2->setX(x);
	_point2->setY(y);
}

std::string Item::getName()const {
	return name;
}
void Item::setName(const std::string& type, const unsigned int& i) {
	name = type + std::to_string(i);
}

void Item::setName(const std::string& newName) {
	name = newName;
}
