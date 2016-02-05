#include "mine.h"

Mine::Mine(QPoint position, QPoint speed, MineSize size):Element(position, speed, QPoint(0,0))
{
    switch(size){
    case SMALL:
        _size = SMALL_MINE_SIZE;
        break;
    case MEDIUM:
        _size = MEDIUM_MINE_SIZE;
        break;
    case LARGE:
        _size = LARGE_MINE_SIZE;
        break;
    }
    initializeShape();
}

Mine::~Mine()
{

}

void Mine::initializeShape()
{
    (*this) << QPoint(getPosition().x()-_size, getPosition().y()-_size)
            << QPoint(getPosition().x()-_size, getPosition().y()+_size)
            << QPoint(getPosition().x()+_size, getPosition().y()+_size)
            << QPoint(getPosition().x()+_size, getPosition().y()-_size);
}
