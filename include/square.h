#pragma once

#include "button.h"


// Specialized button used for the grid.
// --> Stores its position on the grid.
// --> Stores its state as a char: X, O, or unplayed ('X', 'O', '.').
// --> Displays animations for X/O moves.
class Square : public Button
{
    Q_OBJECT

public:
    Square(QWidget *parent = nullptr);

    void setPosition(int p);
    void setState(char s);
    void reset();
    int getPosition();
    char getState();

public slots:
    void playMoveAnimation(char side);
    void playXAnimation();
    void playOAnimation();

private:
    int position;
    char state;
};

