#include "Figura.h"

Figura::Figura(const int& x, const int& y) : Item (x, y) {}

Figura::~Figura() {}

int Figura::getCenter_X() const {
    return x1 > x2 ? x2 + std::abs(x1 - x2) / 2 : x1 + std::abs(x2 - x1) / 2;
}

int Figura::getCenter_Y() const {
    return y1 > y2 ? y2 + std::abs(y1 - y2) / 2 : y1 + std::abs(y2 - y1) / 2;
}

QRectF Figura::boundingRect() const {
    return QRectF(x1, y1, x2, y2);
}