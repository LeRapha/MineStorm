#include "gameoflife.h"
#include <QKeyEvent>

GameOfLife::GameOfLife(const QSize &size, QObject *parent):Game(size,parent)
{
    this->initialize();
    this->createRandomPopulation();
}

GameOfLife::~GameOfLife()
{

}

void GameOfLife::initialize(){
    int cellHeightCount =  (size().height()/CELL_HEIGHT) + 2;
    int cellWidthCount =  (size().width()/CELL_WIDTH) + 2;

    cells.resize(cellHeightCount);
    for(auto& col : cells) {
        col.resize(cellWidthCount);
        for (auto& c: col) {
            c = None;
        }
    }
}

void GameOfLife::createRandomPopulation()
{
    for(int i = 1; i < cells.size()-1; ++i) {
        for (int j = 1; j < cells[i].size()-1; ++j) {
            cells[i][j] = (rand() % 10 > SEUIL_ALIVE_CELL) ? Alive : None;
        }
    }
}

int GameOfLife::countLivingNeighbors(int i, int j) const
{
    int count = 0;
    for(int row = i-1 ; row <= i+1; ++row) {
        for (int col = j-1 ; col <= j+1; ++col) {
            if(!((row == i) and (col == j))){
                if(cells[row][col] == Alive || cells[row][col] == Born){
                    count++;
                }
            }
        }
    }
    return count;
}

void GameOfLife::step(){
    vector< vector<CellState> > tmpCells;
    tmpCells = cells;
    for(int x = 1; x < cells.size()-1; ++x) {
        for (int y = 1; y < cells[y].size()-1; ++y) {
            int livingNeighbors = countLivingNeighbors(x,y);
            switch(cells[x][y]){
                case None:
                case Dead:
                    if(livingNeighbors == 3)
                        tmpCells[x][y] = Born;
                    else
                        tmpCells[x][y] = cells[x][y];
                    break;
                case Born:
                case Alive:
                    if(livingNeighbors == 3 || livingNeighbors == 2)
                        tmpCells[x][y] = Alive;
                    else
                        tmpCells[x][y] = Dead;
                    break;
            }
        }
    }
    cells = tmpCells;
}

void GameOfLife::draw(QPainter &painter, QRect &rect){
    QColor green(50,205,50);
    QColor red(205,50,50);
    QColor white(255,255,255);
    QColor yellow(250,215,0);
    QColor color;
    for(int i = 1; i < cells.size()-1; ++i) {
        for (int j = 1; j < cells[i].size()-1; ++j) {
            switch(cells[i][j]){
            case Alive:
                color = green;
                break;
            case None:
                color = white;
                break;
            case Dead:
                color = red;
                break;
            case Born:
                color = yellow;
                break;
            }
            QBrush brush(color);
            painter.setBrush(brush);
            painter.drawRect(j*CELL_HEIGHT-CELL_HEIGHT,i*CELL_WIDTH-CELL_WIDTH,CELL_HEIGHT,CELL_WIDTH);
        }
    }
}

void GameOfLife::mousePressed( int x, int y){
    int j = (x / CELL_WIDTH) +1;
    int i = (y / CELL_HEIGHT) +1;
    switch(cells[i][j]){
        break;
    case None:
    case Dead:
        cells[i][j] = Alive;
        break;
    case Born:
    case Alive:
        cells[i][j] = Dead;
        break;
    }
    emit changed();
}

void GameOfLife::keyPressed( int key ){
    if(key == Qt::Key_R){
        this->reset();
        this->createRandomPopulation();
    }
}

void GameOfLife::keyReleased( int key ){

}

void GameOfLife::mouseReleased( int x, int y){

}

void GameOfLife::mouseMoved(int x, int y){

}


