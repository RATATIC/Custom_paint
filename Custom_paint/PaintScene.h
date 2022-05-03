#pragma once

#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsSceneEvent>
#include <QtWidgets/QGraphicsSceneMouseEvent>
#include <QTimer>
#include <list>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Line.h"

typedef enum {
	DRAW_RECTANGLE,
	DRAW_CIRCLE,
	DRAW_TRIANGLE,
	DRAW_LINE,
	MOVING,
	UNKNOW
} Action;


class PaintScene : public QGraphicsScene
{
	Q_OBJECT
public :
	explicit PaintScene(QObject *parent = 0);
	~PaintScene();

	void changeAction(const Action& new_item);
private:
	std::list<Figura*> figura_array;
	std::list<Line*> line_array;

	Action action = UNKNOW;

	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

	void draw_line_in_center(const int& x, const int& y);
	
	void addFigura(QGraphicsSceneMouseEvent* event);
	void addLine(QGraphicsSceneMouseEvent* event);

	void moveItem(const int& x, const int& y);
	void startMoveItem(const int& x, const int& y);
	void bindLine(const int& x, const int& y);

	Figura* currentFigura;
};

