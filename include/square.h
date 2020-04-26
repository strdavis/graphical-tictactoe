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

private:
    int position;
    char state;
};

