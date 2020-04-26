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

#include "custom-qwidget.h"

class Square;
class CustomQLabel;


// Contains the interactive and visual components of the TicTacToe grid.
// Stores the game state.
// --> Displays animations for drawing the grid, X/O moves, and wins.
// --> Contains an array of clickable squares representing the grid.
// Contains the logic for detecting wins.
// Signals computer player to move after each player move.
class Grid : public CustomQWidget
{
    Q_OBJECT

public:
    Grid(QWidget *parent = nullptr);

    void reset();
    void playStrikeThroughAnimation(int winningCombination);
    int getTurn();

public slots:
    void saveMove(int index, char side);
    void enable() override;
    void disable() override;
    char getSquareState(int index);

signals:
    void moveDone();
    void readyForComputerMove();
    void gameOver();

private slots:
    void squareClicked();
    void checkForWin();

private:
    Square *addSquare(int x, int y, int w, int h);
    int getWinningCombination(char side);

    Square *squares[9];

    CustomQLabel *gridLines;
    CustomQLabel *strikeThroughAnimation;
    char lastToMove;
    int turn;
};

