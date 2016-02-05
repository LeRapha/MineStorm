#include "shot.h"

Shot::Shot(QPoint position, QPoint speed):Element(position, speed, QPoint(0,0))
{
    initializeShape();
}

void Shot::initializeShape()
{
    (*this) << QPoint(getPosition().x()-SHOT_SIZE, getPosition().y()-SHOT_SIZE)
            << QPoint(getPosition().x()-SHOT_SIZE, getPosition().y()+SHOT_SIZE)
            << QPoint(getPosition().x()+SHOT_SIZE, getPosition().y()+SHOT_SIZE)
            << QPoint(getPosition().x()+SHOT_SIZE, getPosition().y()-SHOT_SIZE);
}

Shot::~Shot()
{

}

