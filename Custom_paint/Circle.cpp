#include "Circle.h"

Circle::Circle(const int& x, const int& y) : Figura(x, y) {
}

Circle::~Circle() {}

void Circle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->drawEllipse( QPoint(getCenter_X(), getCenter_Y()), getRadius_X(), getRadius_Y());
}

int Circle::getRadius_X() const {
    return std::abs(x2 - x1) / 2;
}

int Circle::getRadius_Y() const {
    return std::abs(y2 - y1) / 2;
}