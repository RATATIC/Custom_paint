#include "Line.h"

Line::Line(const int& x, const int&  y) : Item(x, y) {}

Line::Line(std::shared_ptr <Point> point) : Item(point) {}

Line::~Line() {}

QRectF Line::boundingRect() const {
    return QRectF(_point1->getX(), _point1->getY(), _point2->getX(), _point2->getY());
}

void Line::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->drawLine(_point1->getX(), _point1->getY(), _point2->getX(), _point2->getY());
}

void Line::bindPoint(std::shared_ptr <Point> point) {
    _point2 = point;
}