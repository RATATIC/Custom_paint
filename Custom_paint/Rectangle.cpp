#include "Rectangle.h"

Rectangle::Rectangle(const int& x, const int& y) : Figura(x, y) {
}

Rectangle::~Rectangle() {}

void Rectangle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->drawLine(_point1->getX(), _point1->getY(), _point2->getX(), _point1->getY());
    painter->drawLine(_point2->getX(), _point1->getY(), _point2->getX(), _point2->getY());
    painter->drawLine(_point2->getX(), _point2->getY(), _point1->getX(), _point2->getY());
    painter->drawLine(_point1->getX(), _point2->getY(), _point1->getX(), _point1->getY());
}

bool Rectangle::isInFigura(const int& x, const int& y) const {
    return (_point1->getX() > _point2->getX() ? x >= _point2->getX() && x <= _point1->getX() : x >= _point1->getX() && x <= _point2->getX()) &&
           (_point1->getY() > _point2->getY() ? y >= _point2->getY() && y <= _point1->getY() : y >= _point1->getY() && y <= _point2->getY());
}