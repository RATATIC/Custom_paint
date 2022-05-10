#include "Line.h"

unsigned int Line::count = 1;
const std::string Line::TYPE = "Line";


Line::Line(const int& x, const int&  y) : Item(x, y) {
    setName(getType(), count++);
}

Line::Line(std::shared_ptr <Point> point, const std::string& figuraName) : Item(point) {
    setName(getType(), count++);
    boundingFigura_1 = figuraName;
}

Line::Line(const Point& point1, const Point& point2) : Item(point1, point2) {
    setName(getType(), count++);
}

Line::~Line() {}

QRectF Line::boundingRect() const {
    return QRectF(_point1->getX(), _point1->getY(), _point2->getX(), _point2->getY());
}

void Line::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->drawLine(_point1->getX(), _point1->getY(), _point2->getX(), _point2->getY());
}

void Line::boundPoint1(std::shared_ptr <Point> point, const std::string& figuraName) {
    _point1 = point;
    boundingFigura_1 = figuraName;
}

void Line::boundPoint2(std::shared_ptr <Point> point, const std::string& figuraName) {
    _point2 = point;
    boundingFigura_2 = figuraName;
}

std::string Line::getBoundingFigura_1()const {
    if (!boundingFigura_1.empty())
        return boundingFigura_1;
    else
        return "";
}

std::string Line::getBoundingFigura_2()const {
    if (!boundingFigura_2.empty())
        return boundingFigura_2;
    else
        return "";
}

std::string Line::getType()const {
    return TYPE;
}
std::string Line::getItemInfo()const {
    return std::string (this->getType() + " " + std::to_string(this->getPoint1()->getX())
        + " " + std::to_string(this->getPoint1()->getY()) + " " + std::to_string(this->getPoint2()->getX())
        + " " + std::to_string(this->getPoint2()->getY()) + " " + this->getName() + " " + this->getBoundingFigura_1() + " " + this->getBoundingFigura_2());
}

void Line::swapPoints() {
    Point tmp;
    tmp.setPoint(_point1->getX(), _point1->getY());
    _point1->setPoint(_point2->getX(), _point2->getY());
    _point2->setPoint(tmp.getX(), tmp.getY());
}