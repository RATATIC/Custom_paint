#include "Circle.h"

Circle::Circle(const int& x, const int& y) : Figura(x, y) {
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