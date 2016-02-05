#include "minestorm.h"

MineStorm::MineStorm(const QSize &size, QObject *parent):Game(size,parent)
{
    this->initialize();
}

void MineStorm::draw(QPainter &painter, QRect &rect)
{
    painter.drawPolygon(*spaceship);
    painter.drawLine(spaceship->getPosition(),
                     spaceship->getPosition() + spaceship->getDirection());
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
    if(element->getPosition().x() > size().width()){
        element->setPosition(QPoint(0,element->getPosition().y()));
        element->translate(-size().width(), 0);
    }
    if(element->getPosition().x() < 0){
        element->setPosition(QPoint(size().width(),element->getPosition().y()));
        element->translate(size().width(), 0);
    }
    if(element->getPosition().y() < 0){
        element->setPosition(QPoint(element->getPosition().x(), size().height()));
        element->translate(0, size().height());
    }
    if(element->getPosition().y() > size().height()){
        element->setPosition(QPoint(element->getPosition().x(), 0));
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
    spaceship = new Spaceship(QPoint(size().width()/2, size().height()/2));
}

