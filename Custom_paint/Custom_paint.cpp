#include "Custom_paint.h"

Custom_paint::Custom_paint(QWidget *parent)
    : QMainWindow(parent), ui (new Ui::Custom_paintClass ())
{
    ui->setupUi(this);

    scene = new PaintScene ();
    ui->graphicsView->setScene(scene);

    connect(ui->radioButton_1, SIGNAL(clicked()), this, SLOT(clicked_button_rectangle()));
    connect(ui->radioButton_2, SIGNAL(clicked()), this, SLOT(clicked_button_circle()));
    connect(ui->radioButton_3, SIGNAL(clicked()), this, SLOT(clicked_button_triangle()));
    connect(ui->radioButton_4, SIGNAL(clicked()), this, SLOT(clicked_button_line()));
    connect(ui->radioButton_5, SIGNAL(clicked()), this, SLOT(clicked_button_move()));
    connect(ui->pushButton_1,  SIGNAL(clicked()), this, SLOT(clicked_button_save()));
    connect(ui->pushButton_2,  SIGNAL(clicked()), this, SLOT(clicked_button_open()));

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Custom_paint::slotTimer);
    timer->start(100);
}

void Custom_paint::clicked_button_rectangle() {
    scene->changeAction(DRAW_RECTANGLE);
}

void Custom_paint::clicked_button_circle() {
    scene->changeAction(DRAW_CIRCLE);
}

void Custom_paint::clicked_button_triangle() {
    scene->changeAction(DRAW_TRIANGLE);
}

void Custom_paint::clicked_button_line() {
    scene->changeAction(DRAW_LINE);
}

void Custom_paint::clicked_button_move() {
    scene->changeAction(MOVING);
}

void Custom_paint::clicked_button_save() {
    std::vector<std::string> vec_str;
    scene->getVectorItems(vec_str);

    QString newPath = QFileDialog::getSaveFileName(this, QString("Save"), path, tr("TXT files (*.txt)"));

    if (newPath.isEmpty())
        return;
    path = newPath;

    /*
    QPixmap pixmap(scene->width() - 5, scene->height() - 40);
    pixmap.fill(Qt::white);
    QPainter painter;

    painter.begin(&pixmap);
    scene->render(&painter);
    painter.drawRect(5, 40, scene->width(), scene->height());
    painter.end();

    pixmap.save(&file, "PNG");    
    */
    QFile file(path);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        for ( auto& it : vec_str)
            stream << it.c_str () << "\n";
        file.close();
    }
}

void Custom_paint::clicked_button_open() {
    QString newPath = QFileDialog::getOpenFileName(this, QString("Save"), path, tr("TXT files (*.txt)"));
    
    std::vector<std::string> vec_str;
    
    if (newPath.isEmpty())
        return;
    path = newPath;

    QFile file(path);
    
    QString buffer;

    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            buffer = stream.readLine();
            
            qDebug() << buffer;
            
            vec_str.push_back(buffer.toStdString());
        }
        file.close();
    }

    scene->createNewScene(vec_str);
}

Custom_paint::~Custom_paint() {
    delete ui;
    delete scene;
    delete timer;
}

void Custom_paint::slotTimer() {
    timer->stop();
    ui->graphicsView->setGeometry(5, 40, ui->centralWidget->width() - 20, ui->centralWidget->height() - 50);
    scene->setSceneRect(5, 40, ui->graphicsView->width() - 10, ui->graphicsView->height() - 10);
}

void Custom_paint::resizeEvent(QResizeEvent *event) {
    timer->start(100);
    QMainWindow::resizeEvent(event);
}
