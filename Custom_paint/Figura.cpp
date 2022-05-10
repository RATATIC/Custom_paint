#include "Figura.h"

Figura::Figura(const int& x, const int& y) : Item (x, y) {
    center_point = std::make_shared<Point>(getCenter_X(), getCenter_Y());
}

Figura::Figura(const Point& point1, const Point& point2) :Item (point1, point2) {
    center_point = std::make_shared<Point>(getCenter_X(), getCenter_Y());
}

Figura::~Figura() {}

int Figura::getCenter_X() const {
    return _point1->getMiggleX(*_point2);
}

int Figura::getCenter_Y() const {
    return _point1->getMiggleY(*_point2);
}

std::shared_ptr<Point> Figura::getCenterPoint()const {
    return center_point;
}

QRectF Figura::boundingRect() const {
    return QRectF(_point1->getX(), _point1->getY(), _point2->getX(), _point2->getY());
}

void Figura::startMove(const int& x, const int& y) {
    previous_point.setPoint(x, y);
}

void Figura::move(const int& x, const int& y) {
    _point1->setPoint(_point1->getX() + (x - previous_point.getX()), _point1->getY() + (y - previous_point.getY()));
    _point2->setPoint(_point2->getX() + (x - previous_point.getX()), _point2->getY() + (y - previous_point.getY()));
    previous_point.setPoint(x, y);
    center_point->setPoint(getCenter_X(), getCenter_Y());
}

void Figura::changeSize(const int& x, const int& y) {
    this->setPoint2(x, y);
    changeCenterPoint();
}

void Figura::changeCenterPoint() {
    center_point->setPoint(getCenter_X(), getCenter_Y());
}

std::string Figura::getItemInfo()const {
    return this->getType() + " " + std::to_string(this->getPoint1()->getX())
        + " " + std::to_string(this->getPoint1()->getY()) + " " + std::to_string(this->getPoint2()->getX())
        + " " + std::to_string(this->getPoint2()->getY()) + " " + this->getName();
}