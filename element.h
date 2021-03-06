#ifndef ELEMENT_H
#define ELEMENT_H

#define MAX_SPEED 50
#define SPEED_FACTOR 5
#define PI 3.14

#include <QPolygon>
#include <QMatrix>
#include <iostream>

using namespace std;

class Element : public QPolygon
{
protected:
    virtual void initializeShape() = 0;
    QPoint _position;
    QPoint _direction;
    QPoint _speed;
public:
    Element(QPoint position, QPoint speed, QPoint direction);
    ~Element();
    QPoint getSpeed();
    QPoint getDirection();
    QPoint getPosition();
    void setPosition(QPoint);
    void updatePosition();
    void moveForward();
    void rotate(int);
    void rotateDirection(QMatrix angle);
    void rotateShape(QMatrix angle);
};

#endif // ELEMENT_H
