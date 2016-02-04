#ifndef ELEMENT_H
#define ELEMENT_H

#define MAX_SPEED 5
#define SIZE_FACTOR 5

#define PI 3.14

#include <QPolygon>
#include <QMatrix>
#include <iostream>

using namespace std;

class Element : public QPolygon
{
protected:
    virtual void initializeShape() = 0;
    int _x_pos;
    int _y_pos;
    int _dXSpeed;
    int _dYSpeed;
    int _dXDirection;
    int _dYDirection;
public:
    Element(int x, int y, int xSpeed, int ySpeed, int xDir, int yDir);
    ~Element();
    int getDxSpeed();
    int getDySpeed();
    int getDxDirection();
    int getDyDirection();
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    void updatePosition();
    void moveForward();
    void rotate(int);
};

#endif // ELEMENT_H
