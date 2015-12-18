#include "element.h"

Element::Element(int x, int y, int dX, int dY)
{
    _x_pos = x;
    _y_pos = y;
    _dX = dX;
    _dX = dY;
}

Element::~Element()
{

}

int Element::getDX(){
    return _dX;
}

int Element::getDY(){
    return _dY;
}

int Element::getX(){
    return _x_pos;
}

void Element::setX(int x)
{
    _x_pos = x;
}

int Element::getY(){
    return _y_pos;
}

void Element::setY(int y)
{
    _y_pos = y;
}

void Element::setDirection(int dx, int dy){
    _dX = dx;
    _dY = dy;
}

void Element::updatePosition()
{
    translate(_dX, _dY);
    setX(_x_pos + _dX);
    setY(_y_pos + _dY);
}

