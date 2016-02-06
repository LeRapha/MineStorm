#ifndef MINE_H
#define MINE_H

#include "element.h"

#define SMALL_MINE_SIZE 2
#define MEDIUM_MINE_SIZE 3
#define LARGE_MINE_SIZE 4

#define SMALL_MINE_NUMBER 5
#define MEDIUM_MINE_NUMBER 20
#define LARGE_MINE_NUMBER 5

enum MineSize{
    SMALL,
    MEDIUM,
    LARGE
};

enum MineState{
    NEW,
    BORN,
    DYING
};

class Mine : public Element
{
private:
    void initializeShape();
    MineSize _mineSize;
    MineState _mineState;
public:
    Mine(QPoint position, QPoint speed, MineSize size, MineState state);
    ~Mine();
};

#endif // MINE_H
