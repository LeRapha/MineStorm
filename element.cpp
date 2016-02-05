#include "element.h"

Element::Element(QPoint position, QPoint speed, QPoint direction)
{
    _position = position;
    _speed = speed;
    _direction = direction;
}

Element::~Element()
{

}

void Element::updatePosition()
{
    translate(_speed);
    setPosition(_position + _speed);
}

void Element::moveForward(){
    if(_direction.x() > _speed.x()){
        _speed.setX(_speed.x()+1);
    }
    else if(_direction.x() < _speed.x()){
        _speed.setX(_speed.x()-1);
    }

    if(_direction.y() > _speed.y()){
        _speed.setY(_speed.y()+1);
    }
    if(_direction.y() < _speed.y()){
        _speed.setY(_speed.y()-1);
    }
}

void Element::rotate(int angle){
    double theta = (angle * PI) / 180.0;
    int tmpX = _direction.x();
    int tmpY = _direction.y();
    _direction.setX(cos(theta)*(tmpX) - sin(theta)*(tmpY));
    _direction.setY(sin(theta)*(tmpX) + cos(theta)*(tmpY));
    cout << "[ROTATION][" << theta << "]" << endl;
    cout << "[DIRECTION][" << _direction.x() << "][" << _direction.y() << "]" << endl;
}

/*Getters and setters*/
QPoint Element::getSpeed(){return _speed;}
QPoint Element::getDirection(){return _direction;}
QPoint Element::getPosition(){return _position;}
void Element::setPosition(QPoint position){_position = position;}
