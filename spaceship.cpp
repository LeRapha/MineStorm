#include "spaceship.h"

Spaceship::Spaceship(int x, int y):Element(x, y, 0, 0, 0, MAX_SPEED)
{
    this->initializeShape();
}

Spaceship::~Spaceship()
{

}

void Spaceship::initializeShape(){
    this->putPoints(0, 5,
                    getX()-5,getY()-5,
                    getX()+5,getY()-5,
                    getX()+5,getY()+5,
                    getX(),getY()+10,
                    getX()-5,getY()+5);
}
