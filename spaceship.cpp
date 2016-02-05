#include "spaceship.h"

Spaceship::Spaceship(QPoint position):Element(position, QPoint(0,0), QPoint(0,MAX_SPEED))
{
    this->initializeShape();
}

Spaceship::~Spaceship()
{

}

void Spaceship::initializeShape(){
    (*this) << QPoint(getPosition().x()-5, getPosition().y()-5)
            << QPoint(getPosition().x()+5, getPosition().y()-5)
            << QPoint(getPosition().x()+5, getPosition().y()+5)
            << QPoint(getPosition().x(), getPosition().y()+10)
            << QPoint(getPosition().x()-5, getPosition().y()+5);
}
