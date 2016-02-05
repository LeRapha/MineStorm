#ifndef MINESTORM_H
#define MINESTORM_H

#include "game.h"
#include "spaceship.h"
#include "shot.h"
#include <QPainter>

using namespace std;

class MineStorm : public Game
{
    Q_OBJECT
public:
    MineStorm(const QSize &size,QObject *parent = nullptr);
    virtual void draw(QPainter &painter, QRect &rect) override;
    void mousePressed( int x, int y) override;
    void keyPressed( int key ) override;
    void keyReleased( int key ) override;
    void mouseReleased( int x, int y) override;
    void mouseMoved(int x, int y) override;
    void checkForLoop(Element*);
    ~MineStorm();

private:
    Element *spaceship;
    QList<Element*> shots;
    QList<Element*> mines;
    virtual void step();
    void initialize();
};

#endif // MINESTORM_H
