#include "Custom_paint.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Custom_paint w;
    w.show();
    return a.exec();
}
