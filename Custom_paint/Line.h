#pragma once

#include "Item.h"
#include <QPainter>
#include <memory>

class Line : public Item
{
public:
	explicit Line(const int& x, const int& y);
	explicit Line(std::shared_ptr <Point> point, const std::string& figuraName);
	explicit Line(const Point& point1, const Point& point2);

	~Line();

	void move(const int& x, const int& y) override {}
	void startMove(const int& x, const int& y) override {}

	void boundPoint1(std::shared_ptr <Point> point, const std::string& figuraName);
	void boundPoint2(std::shared_ptr <Point> point, const std::string& figuraName);

	void swapPoints();

	std::string getType()const override;

	std::string getBoundingFigura_1()const;
	std::string getBoundingFigura_2()const;

	virtual std::string getItemInfo()const override;

	static const std::string TYPE;
protected :
	QRectF boundingRect() const;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

	static unsigned int count;
	std::string boundingFigura_1;
	std::string boundingFigura_2;
};

