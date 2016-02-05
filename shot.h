#ifndef SHOT_H
#define SHOT_H

#include "Element.h"

#define SHOT_SIZE 3

class Shot : public Element
{
private:
    void initializeShape();
public:
    Shot(QPoint position, QPoint speed, QPoint direction);
    ~Shot();
};

#endif // SHOT_H
