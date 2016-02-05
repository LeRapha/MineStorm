#include "spaceship.h"

Spaceship::Spaceship(QPoint position):Element(position, QPoint(0,0), QPoint(0,MAX_SPEED))
{
    this->initializeShape();
}

Spaceship::~Spaceship()
{

}

void Spaceship::initializeShape(){
    (*this) << QPoint(getPosition().x()-SPACESHIP_SIZE, getPosition().y()-SPACESHIP_SIZE)
            << QPoint(getPosition().x()+SPACESHIP_SIZE, getPosition().y()-SPACESHIP_SIZE)
            << QPoint(getPosition().x()+SPACESHIP_SIZE, getPosition().y()+SPACESHIP_SIZE)
            << QPoint(getPosition().x(), getPosition().y()+SPACESHIP_SIZE*2)
            << QPoint(getPosition().x()-SPACESHIP_SIZE, getPosition().y()+SPACESHIP_SIZE);
}
