#include "Triangle.h"

Triangle::Triangle(const int& x, const int& y) : Figura(x, y) {}

Triangle::~Triangle() {}

void Triangle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->drawLine (_point2->getX(), _point2->getY(), _point1->getX(), _point2->getY());
    painter->drawLine (_point2->getX(), _point2->getY(), getMiddleSide_X(), _point1->getY());
    painter->drawLine (getMiddleSide_X(), _point1->getY(), _point1->getX(), _point2->getY());
}

int Triangle::getMiddleSide_X() const {
    return _point1->getX() > _point2->getX() 
        ? _point2->getX() + std::abs(_point1->getX() - _point2->getX()) / 2 
        : _point1->getX() + std::abs(_point2->getX() - _point1->getX()) / 2;
}

bool Triangle::isInFigura(const int& x, const int& y)const {
    int a = (_point2->getX() - x) * (_point2->getY() - _point2->getY()) - (_point1->getX() - _point2->getX()) * (_point2->getY() - y);
    int b = (_point1->getX() - x) * (_point1->getY() - _point2->getY()) - (getMiddleSide_X() - _point1->getX()) * (_point2->getY() - y);
    int c = (getMiddleSide_X() - x) * (_point2->getY() - _point1->getY()) - (_point2->getX() - getMiddleSide_X()) * (_point1->getY() - y);

    return ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0));
}
