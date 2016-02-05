#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "element.h"

#define SPACESHIP_SIZE 26

class Spaceship : public Element
{
protected:
    void initializeShape();
public:
    Spaceship(QPoint position);
    ~Spaceship();
};

#endif // SPACESHIP_H
