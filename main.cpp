#include "mainwindow.h"
#include "gameoflife.h"
#include "dummygame.h"

#include <QSize>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameOfLife game(QSize(400,400));
    MainWindow w(&game);
    return a.exec();
}
