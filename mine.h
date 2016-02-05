#ifndef MINE_H
#define MINE_H

#include "element.h"

#define SMALL_MINE_SIZE 5
#define MEDIUM_MINE_SIZE 10
#define LARGE_MINE_SIZE 20

enum MineSize{
    SMALL,
    MEDIUM,
    LARGE
};

class Mine : public Element
{
private:
    void initializeShape();
    int _size;
public:
    Mine(QPoint position, QPoint speed, MineSize size);
    ~Mine();
};

#endif // MINE_H
