#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "element.h"

class Spaceship : public Element
{
protected:
    void initializeShape();
public:
    Spaceship(QPoint position);
    ~Spaceship();
};

#endif // SPACESHIP_H
