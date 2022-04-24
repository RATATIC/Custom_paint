#include "Line.h"

Line::Line(const int& x, const int&  y) : Item(x, y) {}

Line::~Line() {}

QRectF Line::boundingRect() const {
    return QRectF(x1, y1, x2, y2);
}

void Line::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->drawLine(x1, y1, x2, y2);
}