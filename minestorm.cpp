#include "minestorm.h"

MineStorm::MineStorm(const QSize &size, QObject *parent):Game(size,parent)
{
    this->initialize();
}

void MineStorm::draw(QPainter &painter, QRect &rect)
{
    //Spaceship drawing
    painter.drawPolygon(*spaceship);

    //Shots drawing
    for(int i = 0; i < shots.length(); i++){
        painter.drawPolygon(*shots[i]);
    }

    //Mines drawing
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
        case Qt::Key_Space:
            shots.append(new Shot(spaceship->getPosition(), spaceship->getDirection()/SPEED_FACTOR, QPoint(0,0)));
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
        element->translate(-element->getPosition().x(), 0);
        element->setPosition(QPoint(0,element->getPosition().y()));
    }
    if(element->getPosition().x() < 0){
        element->translate(size().width()-element->getPosition().x(), 0);
        element->setPosition(QPoint(size().width(),element->getPosition().y()));
    }
    if(element->getPosition().y() < 0){
        element->translate(0, size().height()-element->getPosition().y());
        element->setPosition(QPoint(element->getPosition().x(), size().height()));
    }
    if(element->getPosition().y() > size().height()){
        element->translate(0, -element->getPosition().y());
        element->setPosition(QPoint(element->getPosition().x(), 0));
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

    //Shots position
    for(int i = 0; i < shots.length(); i++){
        shots[i]->updatePosition();
    }
}

void MineStorm::initialize()
{
    spaceship = new Spaceship(QPoint(size().width()/2, size().height()/2));
}

