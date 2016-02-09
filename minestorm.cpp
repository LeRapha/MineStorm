#include "minestorm.h"

MineStorm::MineStorm(const QSize &size, QObject *parent):Game(size,parent)
{
    spaceship = nullptr;
    this->initialize();
}

void MineStorm::draw(QPainter &painter, QRect &rect)
{
    QBrush red(QColor(205,50,50));
    QBrush white(QColor(255,255,255));
    QBrush black(QColor(0,0,0));
    QBrush yellow(QColor(250,215,0));

    QPen whitePen(QColor(white.color()));

    //Background color
    painter.fillRect(rect, black);

    //Spaceship drawing
    painter.setBrush(white);
    painter.drawPolygon(*spaceship);
    painter.drawLine(spaceship->getPosition(),
                     spaceship->getPosition() + spaceship->getDirection());

    //Shots drawing
    painter.setBrush(yellow);
    for(int i = 0; i < shots.length(); i++){
        painter.drawPolygon(*shots[i]);
    }

    //Mines drawing
    painter.setBrush(red);
    for(int i = 0; i < mines.length(); i++){
        painter.drawPolygon(*mines[i]);
    }

    //Score drawing
    painter.setPen(whitePen);
    painter.drawText(QPoint(1,10), QString("Score : ") + QString::number(score));

    //Life number drawing
    painter.drawText(QPoint(1,20), QString("Lives : ") + QString::number(lifeNumber));
}

void MineStorm::mousePressed(int x, int y)
{

}

void MineStorm::keyPressed(int key)
{
    if(keysPressed.count(key) == 0) {
        keysPressed.append(key);
    }

    int nbKeysPressed = keysPressed.length();

    for(int i=0;i < nbKeysPressed;i++) {

        switch(keysPressed.at(i)){
            case Qt::Key_Up:
                spaceship->moveForward();
                break;
            case Qt::Key_Left:
                spaceship->rotate(-5);
                break;
            case Qt::Key_Right:
                spaceship->rotate(5);
                break;
            case Qt::Key_Space:
                shots.append(new Shot(spaceship->getPosition(), (spaceship->getDirection()/SPEED_FACTOR)*2));
                break;
            default:
                break;
        }
    }

}

void MineStorm::keyReleased(int key)
{
    keysPressed.removeOne(key);
}

void MineStorm::mouseReleased(int x, int y)
{

}

void MineStorm::mouseMoved(int x, int y)
{

}

void MineStorm::checkForLoop(Element *element)
{
    if(element->getPosition().x() > size().width()){
        element->translate(-element->getPosition().x(), 0);
        element->setPosition(QPoint(0,element->getPosition().y()));
    }
    if(element->getPosition().x() < 0){
        element->translate(size().width()-element->getPosition().x(), 0);
        element->setPosition(QPoint(size().width(),element->getPosition().y()));
    }
    if(element->getPosition().y() < 0){
        element->translate(0, size().height()-element->getPosition().y());
        element->setPosition(QPoint(element->getPosition().x(), size().height()));
    }
    if(element->getPosition().y() > size().height()){
        element->translate(0, -element->getPosition().y());
        element->setPosition(QPoint(element->getPosition().x(), 0));
    }
}

MineStorm::~MineStorm()
{
    delete spaceship;
}

void MineStorm::step()
{
    updateSpaceShip();
    updateMines();
    updateShots();
    checkForCollisions();
    checkForRemainingMines();
}

void MineStorm::checkForCollisions(){
    //check for spaceship and mines collision
    for(int i = 0; i < mines.size(); i++){
        if(!mines.at(i)->intersected(*spaceship).isEmpty()){
            mines.removeAt(i);
            lose();
        }
        for(int j = 0; j < shots.size(); j++){
            if(!mines.at(i)->intersected(*shots.at(j)).isEmpty()){
                mines.removeAt(i);
                shots.removeAt(j);
                score += 10;
            }
        }
    }
}

void MineStorm::checkForRemainingMines()
{
    if(mines.isEmpty()){
        QMessageBox msgBox;
        msgBox.setText("You won !\n Score : " + QString::number(score));
        msgBox.exec();
        clearElements();
        reset();
    }
}

void MineStorm::updateSpaceShip(){
    //Spaceship position
    spaceship->updatePosition();
    checkForLoop(spaceship);
}

void MineStorm::updateMines(){
    //Mines position
    for(int i = 0; i < mines.length(); i++){
        mines[i]->updatePosition();
        checkForLoop(mines[i]);
    }
}

void MineStorm::updateShots(){
    //Shots position
    for(int i = 0; i < shots.length(); i++){
        shots[i]->updatePosition();
        checkForLoop(shots[i]);
    }
}

void MineStorm::generateMines(MineSize type)
{
    int number;
    if(type == SMALL)number = SMALL_MINE_NUMBER;
    else if(type == MEDIUM)number = MEDIUM_MINE_NUMBER;
    else if(type == LARGE)number = LARGE_MINE_NUMBER;

    for(int i = 0; i < number; i++){
        int xPos = rand()%size().width();
        int yPos = rand()%size().height();
        int xSpeed = ((rand()%MAX_SPEED*2)-MAX_SPEED)/(SPEED_FACTOR*2);
        int ySpeed = ((rand()%MAX_SPEED*2)-MAX_SPEED)/(SPEED_FACTOR*2);
        mines.append(new Mine(QPoint(xPos,yPos), QPoint(xSpeed,ySpeed), type, NEW));
    }
}

void MineStorm::lose()
{
    lifeNumber--;
    if(lifeNumber <= 0){
        QMessageBox msgBox;
        msgBox.setText("You lost !\n Score : " + QString::number(score));
        msgBox.exec();
        clearElements();
        reset();
    }
}

void MineStorm::clearElements()
{
    if(spaceship != nullptr)delete spaceship;
    for(int i = 0; i < shots.size(); i++)delete shots[i];
    for(int i = 0; i < mines.size(); i++)delete mines[i];
    shots.clear();
    mines.clear();
}

void MineStorm::initialize()
{
    clearElements();
    spaceship = new Spaceship(QPoint(size().width()/2, size().height()/2));
    generateMines(SMALL);
    generateMines(MEDIUM);
    generateMines(LARGE);
    score = 0;
    lifeNumber = 4;
}

