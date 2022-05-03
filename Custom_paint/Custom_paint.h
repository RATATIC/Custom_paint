#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGraphicsSceneEvent>
#include <QTimer>
#include <QFileDialog>
#include <QBuffer>
#include <QImage>

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
    QString path;

    void resizeEvent (QResizeEvent* event);
    void slotTimer ();
private slots:
    void clicked_button_rectangle();
    void clicked_button_circle();
    void clicked_button_triangle();
    void clicked_button_line();
    void clicked_button_move();
    void clicked_button_save();
};
