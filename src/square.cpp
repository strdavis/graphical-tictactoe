/*
 * Copyright (C) 2020  Spencer Davis
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


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
