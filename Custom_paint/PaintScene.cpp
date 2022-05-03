#include "PaintScene.h"
#include <iostream>

PaintScene::PaintScene(QObject* parent) : QGraphicsScene(parent) {
	currentFigura = nullptr;
}

PaintScene::~PaintScene() {
	for (auto* it : figura_array) {
		delete it;
	}
	for (auto* it : line_array) {
		delete it;
	}
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {

	if (this->action == UNKNOW)
		return;

	if (this->action == MOVING) {
		startMoveItem(event->scenePos().x(), event->scenePos().y());
	}
	else if (this->action >= DRAW_RECTANGLE && this->action <= DRAW_TRIANGLE) {
		addFigura(event);
	}
	else if (this->action == DRAW_LINE) {
		addLine(event);
	}
	this->update();
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
	if (this->action == UNKNOW)
		return;

	if (this->action == MOVING) {
		moveItem(event->scenePos().x(), event->scenePos().y());
	}
	else if (this->action == DRAW_LINE) {
		draw_line_in_center(event->scenePos().x(), event->scenePos().y());
	}
	else if (this->action >= DRAW_RECTANGLE && this->action <= DRAW_TRIANGLE) {
		if (currentFigura != nullptr)
			currentFigura->changeSize(event->scenePos().x(), event->scenePos().y());
	}
	this->update();
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
	if (this->action == DRAW_LINE)
		bindLine(event->scenePos().x(), event->scenePos().y());
	
	currentFigura = nullptr;
	this->update();
}

void PaintScene::addFigura(QGraphicsSceneMouseEvent* event) {

	if (this->action == DRAW_RECTANGLE) {
		figura_array.push_back(new Rectangle(event->scenePos().x(), event->scenePos().y()));
	}
	else if (this->action == DRAW_CIRCLE) {
		figura_array.push_back(new Circle(event->scenePos().x(), event->scenePos().y()));
	}
	else if (this->action == DRAW_TRIANGLE) {
		figura_array.push_back(new Triangle(event->scenePos().x(), event->scenePos().y()));
	}

	this->addItem(figura_array.back());
	currentFigura = figura_array.back();
}

void PaintScene::addLine(QGraphicsSceneMouseEvent* event) {
	for (const auto& it : figura_array) {
		if (it->isInFigura(event->scenePos().x(), event->scenePos().y()) == true) {
			line_array.push_back(new Line(it->getCenterPoint()));
			this->addItem(line_array.back());

			currentFigura = it;
			return;
		}
	}
	line_array.push_back(new Line(event->scenePos().x(), event->scenePos().y()));
	this->addItem(line_array.back());
}

void PaintScene::draw_line_in_center(const int& x, const int& y) {
	for (const auto& it : figura_array) {
		if (it->isInFigura(x, y) && currentFigura != it) {
			line_array.back()->setPoint2(it->getCenter_X(), it->getCenter_Y());
			return;
		}
	}
	line_array.back()->setPoint2(x, y);
}

void PaintScene::bindLine(const int& x, const int& y) {
	for (const auto& it : figura_array) {
		if (it->isInFigura(x, y) && currentFigura != it) {
			line_array.back()->bindPoint (it->getCenterPoint());
			return;
		}
	}
}

void PaintScene::startMoveItem(const int& x, const int& y) {
	for (auto& it : figura_array) {
		if (it->isInFigura(x, y) == true) {
			it->startMove(x, y);
			currentFigura = it;
			return;
		}
	}
}

void PaintScene::moveItem(const int& x, const int& y) {
	if (currentFigura != nullptr)
		currentFigura->move(x, y);
}

void PaintScene::changeAction(const Action& new_action) {
	if (new_action >= DRAW_RECTANGLE || new_action <= UNKNOW)
		this->action = new_action;
}