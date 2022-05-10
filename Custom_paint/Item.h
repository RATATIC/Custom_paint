#pragma once

#include <QtWidgets/QGraphicsItem>
#include <QObject>
#include "Point.h"
#include <memory>
#include <string>

class Item : public QObject, public QGraphicsItem
{
	Q_OBJECT
public :
	explicit Item(const int& x, const int& y, QObject* parent = 0);
	explicit Item(const Point& point1, const Point& point2, QObject* parent = 0);
	explicit Item(std::shared_ptr<Point> point, QObject* parent = 0);
	
	virtual ~Item();

	std::shared_ptr<Point> getPoint1()const;
	std::shared_ptr<Point> getPoint2()const;
	
	void setPoint1(const int& x, const int& y);
	void setPoint2(const int& x, const int& y);

	std::string getName()const;

	virtual void move(const int& x, const int& y) = 0;
	virtual void startMove(const int& x, const int& y) = 0;
	virtual std::string getType()const = 0;
	virtual std::string getItemInfo()const = 0;

	void setName(const std::string& newName);

protected :	
	std::string name;
	void setName(const std::string& type, const unsigned int& i);

	std::shared_ptr<Point> _point1;
	std::shared_ptr<Point> _point2;
};