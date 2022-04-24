#include "PaintScene.h"
#include <iostream>

PaintScene::PaintScene(QObject* parent) : QGraphicsScene(parent) {

}

PaintScene::~PaintScene() {
	for (auto* it : item_array) {
		delete it;
	}
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {

	if (this->item == DRAW_UNKNOW)
		return;

	if (this->item == DRAW_RECTANGLE) {
		item_array.push_back(new Rectangle(event->scenePos().x(), event->scenePos().y()));
	}
	else if (this->item == DRAW_CIRCLE) {
		item_array.push_back(new Circle(event->scenePos().x(), event->scenePos().y()));
	}
	else if (this->item == DRAW_TRIANGLE) {
		item_array.push_back(new Triangle(event->scenePos().x(), event->scenePos().y()));
	}

	this->addItem(item_array.back());
	
	item_array.back()->setPos(0, 0);
	previousPoint = event->scenePos();
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
	if (this->item == DRAW_UNKNOW)
		return;

	item_array.back()->change_x2_and_y2(event->scenePos().x(), event->scenePos().y());
	previousPoint = event->scenePos();
	this->update();
}

void PaintScene::changeDrawItem(const draw_item& new_item) {
	if (new_item >= DRAW_RECTANGLE || new_item <= DRAW_UNKNOW)
		this->item = new_item;
}