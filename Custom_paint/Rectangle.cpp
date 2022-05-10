#include "Rectangle.h"

unsigned int Rectangle::count = 1;
const std::string Rectangle::TYPE = "Rectangle";

Rectangle::Rectangle(const int& x, const int& y) : Figura(x, y) {
    setName(getType(), count++);
}

Rectangle::Rectangle(const Point& point1, const Point& point2) : Figura(point1, point2) {
    setName(getType(), count++);
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

std::string Rectangle::getType()const {
    return TYPE;
}