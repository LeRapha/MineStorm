#include "minestorm.h"

MineStorm::MineStorm(const QSize &size, QObject *parent):Game(size,parent)
{
    this->initialize();
}

void MineStorm::draw(QPainter &painter, QRect &rect)
{
    painter.drawPolygon(*spaceship);
    painter.drawLine(spaceship->getX(),spaceship->getY(),
                     spaceship->getX() + spaceship->getDxDirection(),spaceship->getY() + spaceship->getDyDirection());
}

void MineStorm::mousePressed(int x, int y)
{

}

void MineStorm::keyPressed(int key)
{
    switch(key){
        case Qt::Key_Up:
            spaceship->moveForward();
            break;
        case Qt::Key_Left:
            spaceship->rotate(-5);
            break;
        case Qt::Key_Right:
            spaceship->rotate(5);
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
        element->translate(-size().width(), 0);
    }
    if(element->getX() < 0){
        element->setX(size().width());
        element->translate(size().width(), 0);
    }
    if(element->getY() < 0){
        element->setY(size().height());
        element->translate(0, size().height());
    }
    if(element->getY() > size().height()){
        element->setY(0);
        element->translate(0, -size().height()-5);
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
    //cout << "[POSITION] : [" << spaceship->getX() <<"]\t[" << spaceship->getY() << "]" << endl;
}

void MineStorm::initialize()
{
    spaceship = new Spaceship(size().width()/2, size().height()/2);
}

