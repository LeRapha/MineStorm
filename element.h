#ifndef ELEMENT_H
#define ELEMENT_H

#define MAX_SPEED 2
#define PI 3.14

#include <QPolygon>
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
    int getDX();
    int getDY();
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    void updatePosition();
    void accelerate();
    void rotate(int);
    virtual void reshape() = 0;
};

#endif // ELEMENT_H
