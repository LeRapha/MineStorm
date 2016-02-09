#ifndef SHOT_H
#define SHOT_H

#include "element.h"

#define SHOT_SIZE 30

class Shot : public Element
{
private:
    void initializeShape();
public:
    Shot(QPoint position, QPoint speed);
    ~Shot();
};

#endif // SHOT_H
