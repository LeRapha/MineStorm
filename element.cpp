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
    QMatrix matrix;
    matrix.rotate(angle);
    rotateDirection(matrix);
    rotateShape(matrix);
}

void Element::rotateDirection(QMatrix matrix)
{
    _direction = matrix.map(_direction);
}

void Element::rotateShape(QMatrix matrix)
{
    QPolygon tmp;
    tmp.swap(*this);
    for(int i = 0; i < tmp.size(); i++){
        QPoint p;
        p.setX(tmp.point(i).x()-_position.x());
        p.setY(tmp.point(i).y()-_position.y());
        p = matrix.map(p);
        p.setX(p.x() + _position.x());
        p.setY(p.y() + _position.y());
        tmp.setPoint(i, p);
    }
    tmp.swap(*this);
}

/*Getters and setters*/
QPoint Element::getSpeed(){return _speed;}
QPoint Element::getDirection(){return _direction;}
QPoint Element::getPosition(){return _position;}
void Element::setPosition(QPoint position){_position = position;}
