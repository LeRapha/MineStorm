#ifndef ELEMENT_H
#define ELEMENT_H

#include <QPolygon>
#include <iostream>

using namespace std;

class Element : public QPolygon
{
protected:
    virtual void initializeShape() = 0;
    int _x_pos;
    int _y_pos;
    int _dX;
    int _dY;
public:
    Element(int x, int y, int dX, int dY);
    ~Element();
    int getSpeed();
    int getDX();
    int getDY();
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    void setSpeed(int speed);
    void setDirection(int dx, int dy);
    void updatePosition();
};

#endif // ELEMENT_H
