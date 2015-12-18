#include "mainwindow.h"
#include "gameoflife.h"
#include "dummygame.h"
#include "minestorm.h"

#include <QSize>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MineStorm game(QSize(400,400));
    MainWindow w(&game);
    return a.exec();
}
