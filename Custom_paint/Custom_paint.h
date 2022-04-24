#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGraphicsSceneEvent>
#include <QTimer>
#include "ui_Custom_paint.h"
#include "PaintScene.h"

class Custom_paint : public QMainWindow
{
    Q_OBJECT
public:
    explicit Custom_paint(QWidget *parent = Q_NULLPTR);
    ~Custom_paint ();

private:
    Ui::Custom_paintClass *ui;
    QTimer* timer;
    PaintScene *scene;

    void resizeEvent (QResizeEvent* event);
    void slotTimer ();
private slots:
    void clicked_button_1();
    void clicked_button_2();
    void clicked_button_3();
};
