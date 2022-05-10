#pragma once
#include "Figura.h"
#include <QPainter>
#include <cmath>

class Triangle : public Figura
{
public:
	explicit Triangle(const int& x, const int& y);
	explicit Triangle(const Point& point1, const Point& point2);

	~Triangle();

	bool isInFigura(const int& x, const int& y) const override;
	std::string getType()const override;

	static const std::string TYPE;
protected:
	int getMiddleSide_X() const;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

	static unsigned int count;
};

