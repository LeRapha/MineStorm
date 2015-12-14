#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#define CELL_WIDTH 5
#define CELL_HEIGHT 5
#define SEUIL_ALIVE_CELL 7

#include "game.h"

#include <vector>
#include <QPainter>

using namespace std;

class GameOfLife : public Game
{
    Q_OBJECT
public:
    GameOfLife(const QSize &size,QObject *parent = nullptr);
    virtual void draw(QPainter &painter, QRect &rect) override;
    void mousePressed( int x, int y) override;
    void keyPressed( int key ) override;
    void keyReleased( int key ) override;
    void mouseReleased( int x, int y) override;
    void mouseMoved(int x, int y) override;
    void createRandomPopulation();
    int countLivingNeighbors(int i, int j) const;
    ~GameOfLife();

private:
    virtual void step();
    void initialize();
    enum CellState{None, Born, Alive, Dead};
    vector< vector<CellState> > cells;
};

#endif // GAMEOFLIFE_H
