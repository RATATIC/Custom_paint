#include "Triangle.h"

Triangle::Triangle(const int& x, const int& y) : Figura(x, y) {}

Triangle::~Triangle() {}

void Triangle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->drawLine (x2, y2, x1, y2);
    painter->drawLine (x2, y2, getMiddleSide_X (), y1);
    painter->drawLine (getMiddleSide_X (), y1, x1, y2);
}

int Triangle::getMiddleSide_X() const {
    return x1 > x2 ? x2 + std::abs(x1 - x2) / 2 : x1 + std::abs(x2 - x1) / 2;
}
