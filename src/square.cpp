#include "square.h"

#include <iostream>

#include "custom-qmovie.h"


Square::Square(QWidget *parent) : Button(parent), state('.')
{

}


void Square::playMoveAnimation(char side)
{
    if (side == 'X')
    {
        setAnimation(":/draw-red-X.gif");
    }
    else // side == 'O'
    {
        setAnimation(":/draw-blue-O.gif");
    }

    playAnimationOnce();
}


void Square::reset()
{
    setState('.');
    stopAnimation();
}


void Square::setState(char s)
{
    state = s;
}


char Square::getState()
{
    return state;
}


void Square::setPosition(int p)
{
    position = p;
}


int Square::getPosition()
{
    return position;
}
