#include "element.h"

Element::Element(int x, int y, int xSpeed, int ySpeed, int xDir, int yDir)
{
    _x_pos = x;
    _y_pos = y;
    _dXSpeed = xSpeed;
    _dYSpeed = ySpeed;
    _dXDirection = xDir;
    _dYDirection = yDir;
}

Element::~Element()
{

}

int Element::getDX(){
    return _dXSpeed;
}

int Element::getDY(){
    return _dYSpeed;
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

void Element::updatePosition()
{
    translate(_dXSpeed, _dYSpeed);
    setX(_x_pos + _dXSpeed);
    setY(_y_pos + _dYSpeed);
}

void Element::accelerate(){
    if(_dXDirection > _dXSpeed){
        _dXSpeed++;
    }
    else if(_dXDirection < _dXSpeed){
        _dXSpeed--;
    }
    if(_dYDirection > _dYSpeed){
        _dYSpeed++;
    }
    else if(_dYDirection < _dYSpeed){
        _dYSpeed--;
    }
}

void Element::rotate(int angle){
    float rad = angle * PI / 180.0;
    int tmpX = _dXDirection;
    int tmpY = _dYDirection;
    _dXDirection = cos(rad)*(tmpX - _x_pos) - sin(rad)*(tmpY - _y_pos) + _x_pos;
    _dYDirection = sin(rad)*(tmpX - _x_pos) + cos(rad)*(tmpY - _y_pos) + _y_pos;

}
