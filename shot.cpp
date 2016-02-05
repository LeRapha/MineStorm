#include "shot.h"

Shot::Shot(QPoint position, QPoint speed, QPoint direction):Element(position, speed, direction)
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

