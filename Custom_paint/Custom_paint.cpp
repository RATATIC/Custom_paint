#include "Custom_paint.h"
//#include <QtWidgets/QMainWindow>

Custom_paint::Custom_paint(QWidget *parent)
    : QMainWindow(parent), ui (new Ui::Custom_paintClass ())
{
    ui->setupUi(this);

    scene = new PaintScene ();
    ui->graphicsView->setScene(scene);

    connect(ui->radioButton,   SIGNAL(clicked()), this, SLOT(clicked_button_1()));
    connect(ui->radioButton_2, SIGNAL(clicked()), this, SLOT(clicked_button_2()));
    connect(ui->radioButton_3, SIGNAL(clicked()), this, SLOT(clicked_button_3()));

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Custom_paint::slotTimer);
    timer->start(100);
}

void Custom_paint::clicked_button_1() {
    scene->changeDrawItem(DRAW_RECTANGLE);
}

void Custom_paint::clicked_button_2() {
    scene->changeDrawItem(DRAW_CIRCLE);
}

void Custom_paint::clicked_button_3() {
    scene->changeDrawItem(DRAW_TRIANGLE);
}

Custom_paint::~Custom_paint() {
    delete ui;
    delete scene;
    delete timer;
}

void Custom_paint::slotTimer() {
    timer->stop();
    scene->setSceneRect(0, 0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void Custom_paint::resizeEvent(QResizeEvent *event) {
    timer->start(100);
    QMainWindow::resizeEvent(event);
}
