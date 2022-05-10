#include "PaintScene.h"
#include <iostream>

PaintScene::PaintScene(QObject* parent) : QGraphicsScene(parent) {
	currentFigura = nullptr;
}

PaintScene::~PaintScene() {
	deleteAllItems();
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
			line_array.push_back(new Line(it->getCenterPoint(), it->getName()));
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
			line_array.back()->boundPoint2 (it->getCenterPoint(), it->getName());
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

void PaintScene::getVectorItems(std::vector<std::string>& vec_str) const{
	for (const auto& it : figura_array)
		vec_str.push_back(it->getItemInfo());

	for (const auto& it : line_array)
		vec_str.push_back(it->getItemInfo());
}

void PaintScene::createNewScene(const std::vector<std::string>& vec_str) {
	deleteAllItems();

	std::stringstream ss;
	std::string word;
	std::vector <std::string> item_info;

	for (const auto& it : vec_str) {
		{	
			std::stringstream ss (it);
			while (ss >> word)
				item_info.push_back(word);
		}
		if (item_info[0].compare(Line::TYPE) != 0)
			addFigura(item_info);
		item_info.clear();
		ss.clear();
	}

	qDebug() << "1";
	
	for (const auto& it : vec_str) {
		{
			std::stringstream ss(it);
			while (ss >> word) {
				item_info.push_back(word);
				qDebug() << QString(word.c_str());
			}
		}

		if (item_info[0].compare(Line::TYPE) == 0) {
			qDebug() << "4";
			addLine(item_info);
			qDebug() << "2";
		}
		item_info.clear();
	}
	qDebug() << "3";
	this->update();
}

void PaintScene::addLine(const std::vector<std::string>& item_info) {

	line_array.push_back(new Line(Point(std::stoi(item_info[1]), std::stoi(item_info[2])), Point(std::stoi(item_info[3]), std::stoi(item_info[4]))));
	line_array.back()->setName(item_info[5]);
	this->addItem(line_array.back());

	if (item_info.size() < 6)
		return;

	for (const auto& it : figura_array) {
		if (it->getName().compare(item_info[item_info.size() - 1]) == 0) {
			if (it->getCenterPoint()->getX() == line_array.back()->getPoint1()->getX() && it->getCenterPoint()->getY() == line_array.back()->getPoint1()->getY()) {
				line_array.back()->swapPoints();
			}
			line_array.back()->boundPoint2(it->getCenterPoint(), it->getName());
		}
	}

	if (item_info.size() < 7)
		return;

	for (const auto& it : figura_array) {
		if (it->getName().compare(item_info[item_info.size() - 2]) == 0) {
			line_array.back()->boundPoint1(it->getCenterPoint(), it->getName());
		}
	}
}

void PaintScene::addFigura(const std::vector<std::string>& item_info) {
	if (item_info.empty())
		return;

	if (item_info[0].compare(Rectangle::TYPE) == 0) {
		figura_array.push_back(new Rectangle(Point(std::stoi(item_info[1]), std::stoi(item_info[2])), Point(std::stoi(item_info[3]), std::stoi(item_info[4])) ));
	}
	else if (item_info[0].compare(Circle::TYPE) == 0) {
		figura_array.push_back(new Circle(Point(std::stoi(item_info[1]), std::stoi(item_info[2])), Point(std::stoi(item_info[3]), std::stoi(item_info[4])) ));
	}
	else if (item_info[0].compare(Triangle::TYPE) == 0) {
		figura_array.push_back(new Triangle(Point(std::stoi(item_info[1]), std::stoi(item_info[2])), Point(std::stoi(item_info[3]), std::stoi(item_info[4])) ));
	}
	figura_array.back()->setName(item_info[5]);
	this->addItem(figura_array.back());
}

void PaintScene::deleteAllItems() {
	for (auto* it : figura_array) {
		this->removeItem(it);
		delete it;
	}
	std::list<Figura*>().swap(figura_array);
	for (auto* it : line_array) {
		this->removeItem(it);
		delete it;
	}
	std::list<Line*>().swap(line_array);
}