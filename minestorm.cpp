#include "minestorm.h"

MineStorm::MineStorm(const QSize &size, QObject *parent):Game(size,parent)
{
    this->initialize();
}

void MineStorm::draw(QPainter &painter, QRect &rect)
{
    painter.drawPolygon(*spaceship);
}

void MineStorm::mousePressed(int x, int y)
{

}

void MineStorm::keyPressed(int key)
{
    QMatrix matrix;
    switch(key){
        case Qt::Key_Up:
            spaceship->moveForward();
            break;
        case Qt::Key_Left:

            break;
        default:
            break;
    }
}

void MineStorm::keyReleased(int key)
{

}

void MineStorm::mouseReleased(int x, int y)
{

}

void MineStorm::mouseMoved(int x, int y)
{

}

void MineStorm::checkForLoop(Element *element)
{
    if(element->getX() > size().width()){
        element->setX(0);
    }
    if(element->getX() < 0){
        element->setX(size().width());
    }
    if(element->getY() < 0){
        element->setY(size().height());
    }
    if(element->getY() > size().height()){
        element->setY(0);
    }
}

MineStorm::~MineStorm()
{
    delete spaceship;
}

void MineStorm::step()
{
    spaceship->updatePosition();
    checkForLoop(spaceship);
}

void MineStorm::initialize()
{
    spaceship = new Spaceship(size().width()/2, size().height()/2);
}

