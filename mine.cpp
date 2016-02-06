#include "mine.h"

Mine::Mine(QPoint position, QPoint speed, MineSize size, MineState state):Element(position, speed, QPoint(0,0))
{
    _mineSize = size;
    _mineState = state;
    initializeShape();
}

Mine::~Mine()
{

}

void Mine::initializeShape()
{
    int size;
    switch(_mineSize){
    case SMALL:
        size = SMALL_MINE_SIZE;
        break;
    case MEDIUM:
        size = MEDIUM_MINE_SIZE;
        break;
    case LARGE:
        size = LARGE_MINE_SIZE;
        break;
    }
    (*this) << QPoint(getPosition().x()-size, getPosition().y()-size)
            << QPoint(getPosition().x()-size, getPosition().y()+size)
            << QPoint(getPosition().x()+size, getPosition().y()+size)
            << QPoint(getPosition().x()+size, getPosition().y()-size);
}
