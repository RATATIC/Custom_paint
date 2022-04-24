#include "Item.h"

Item::Item(const int& x, const int& y) {
	x1 = x;
	x2 = x + 1;
	y1 = y;
	y2 = y + 1;
}

Item::~Item() {}

void Item::change_x2_and_y2(const int& x, const int& y) {
	x2 = x;
	y2 = y;
}

int Item::getX1() const {
	return this->x1;
}

int Item::getY1() const {
	return this->y1;
}

int Item::getX2() const {
	return this->x2;
}

int Item::getY2() const {
	return this->y2;
}