#include "Circle.h"

unsigned int Circle::count = 1;
const std::string Circle::TYPE = "Circle";


Circle::Circle(const int& x, const int& y) : Figura(x, y) {
    setName(getType (), count++);
}

Circle::Circle(const Point& point1, const Point& point2) : Figura(point1, point2) {
    setName(getType(), count++);
}

Circle::~Circle() {}

void Circle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->drawEllipse( QPoint(getCenter_X(), getCenter_Y()), getRadius_X(), getRadius_Y());
}

int Circle::getRadius_X() const {
    return std::abs(_point1->getX() - _point2->getX()) / 2;
}

int Circle::getRadius_Y() const {
    return std::abs(_point1->getY() - _point2->getY()) / 2;
}

bool Circle::isInFigura(const int& x, const int& y)const {
    return  ( static_cast<double>(std::abs(x - getCenter_X()) * std::abs(x - getCenter_X()) ) / (getRadius_X() * getRadius_X()) +
              static_cast<double>(std::abs(y - getCenter_Y()) * std::abs(y - getCenter_Y()) ) / (getRadius_Y() * getRadius_Y()) ) <= 1;
}

std::string Circle::getType()const {
    return TYPE;
}