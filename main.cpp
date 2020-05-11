#include "minesweeper.h"
#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget wgt;
    Minesweeper w;

    w.setWindowTitle("Hello world");
    w.show();
    return app.exec();
}



