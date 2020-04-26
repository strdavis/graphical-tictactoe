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

#include <QWidget>

class Grid;
class Square;


// Generates moves based on state of the TicTacToe grid.
// --> Contains reference to the grid.
// Stores difficulty setting.
class ComputerPlayer : public QWidget
{
    Q_OBJECT

public:
    ComputerPlayer(QWidget *parent = nullptr);

    void setDifficulty(std::string diff);
    void setGrid(Grid *grid);

public slots:
    void move();

private:
    int generateMove();
    int getWinningMove(char side);
    int getSimpleMove();
    int getCleverMove();
    int getCleverFirstMove();
    int getCleverSecondMove();
    int getAdjacentMove();
    int getRandomMove();
    std::vector <int> getAvailableMoves();

    Grid *grid;
    int winningCombinations[8][3];
    std::string difficulty;
};
