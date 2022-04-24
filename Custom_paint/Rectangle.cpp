#include "Rectangle.h"

Rectangle::Rectangle(const int& x, const int& y) : Figura(x, y) {
}

Rectangle::~Rectangle() {}

void Rectangle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->drawLine(x1, y1, x2, y1);
    painter->drawLine(x2, y1, x2, y2);
    painter->drawLine(x2, y2, x1, y2);
    painter->drawLine(x1, y2, x1, y1);
}