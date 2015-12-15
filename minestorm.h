#ifndef MINESTORM_H
#define MINESTORM_H

#include "game.h"

using namespace std;

class MineStorm : public Game
{
public:
    Q_OBJECT
    MineStorm(const QSize &size,QObject *parent = nullptr);
    virtual void draw(QPainter &painter, QRect &rect) override;
    void mousePressed( int x, int y) override;
    void keyPressed( int key ) override;
    void keyReleased( int key ) override;
    void mouseReleased( int x, int y) override;
    void mouseMoved(int x, int y) override;
    ~MineStorm();

private:
    virtual void step();
    void initialize();
};

#endif // MINESTORM_H
