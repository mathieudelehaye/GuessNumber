#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    // Stylize widget
    w.setStyleSheet("background-color:#d0e8f2;"); // set widget background color

    w.show();
    return a.exec();
}
