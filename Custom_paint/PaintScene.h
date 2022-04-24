#pragma once

#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsSceneEvent>
#include <QtWidgets/QGraphicsSceneMouseEvent>
#include <QTimer>
#include <vector>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

typedef enum {
	DRAW_RECTANGLE,
	DRAW_CIRCLE,
	DRAW_TRIANGLE,
	DRAW_UNKNOW
} draw_item;


class PaintScene : public QGraphicsScene
{
	Q_OBJECT
public :
	explicit PaintScene(QObject *parent = 0);
	~PaintScene();

//public slots:
	void changeDrawItem(const draw_item& new_item);
private:
	QPointF		previousPoint;
	std::list<Item*> item_array;

	draw_item item = DRAW_UNKNOW;

	void mousePressEvent(QGraphicsSceneMouseEvent*);
	void mouseMoveEvent(QGraphicsSceneMouseEvent*);
//private slots:
};

