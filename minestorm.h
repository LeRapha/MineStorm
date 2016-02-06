#ifndef MINESTORM_H
#define MINESTORM_H

#include "game.h"
#include "spaceship.h"
#include "shot.h"
#include "mine.h"
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
    ~MineStorm();

private:
    //Members
    Element *spaceship;
    QList<Element*> shots;
    QList<Element*> mines;
    int score;
    int lifeNumber;

    //Inherited methods
    virtual void step();
    void initialize();

    //private methods
    void checkForLoop(Element*);
    void checkForCollisions();
    void updateSpaceShip();
    void updateMines();
    void updateShots();
    void generateMines(MineSize type);
};

#endif // MINESTORM_H
