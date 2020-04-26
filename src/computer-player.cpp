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


#include "computer-player.h"

#include <ctime>
#include <iostream>

#include "grid.h"
#include "square.h"


ComputerPlayer::ComputerPlayer(QWidget *parent)
    : QWidget(parent),

      // Intialize 2D array storing the 8 winning combinations,
      // as represented by the positions of their constituent squares.
      winningCombinations{ {0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6} }
{
    // Seed RNG
    srand(time(0));
}


void ComputerPlayer::move()
{
    grid->saveMove(generateMove(), 'O');
}


int ComputerPlayer::generateMove()
{
    int winningMove = getWinningMove('O');

    if (winningMove > -1)
    {
        return winningMove;
    }

    int blockingMove = getWinningMove('X');

    if (blockingMove > -1)
    {
        return blockingMove;
    }

    if (difficulty == "easy")
    {
        return getSimpleMove();
    }

    return getCleverMove(); // difficulty == "hard"
}


int ComputerPlayer::getSimpleMove()
{
    int adjMove = getAdjacentMove();

    if (adjMove > -1)
    {
        return adjMove;
    }

    return getRandomMove();
}


int ComputerPlayer::getCleverMove()
{
    if (grid->getTurn() == 0)
    {
        return getCleverFirstMove();
    }

    if (grid->getTurn() == 1)
    {
        return getCleverSecondMove();
    }

    return getSimpleMove();
}


int ComputerPlayer::getCleverFirstMove()
{
    // If player played center square
    if (grid->getSquareState(4) == 'X')
    {
        // Play a corner
        std::vector <int> corners = {0, 2, 6, 8};

        int randomIndex = rand() % corners.size();

        int corner = corners[randomIndex];

        return corner;
    }

    // Else play center
    return 4;
}


int ComputerPlayer::getCleverSecondMove()
{
    // Get state of corners and center
    char topLeft = grid->getSquareState(0);
    char topRight = grid->getSquareState(2);
    char bottomLeft = grid->getSquareState(6);
    char bottomRight = grid->getSquareState(8);
    char center = grid->getSquareState(4);

    // If player played a pair of diagonal corners,
    // play a side, since center must have been played by computer,
    // so player will be forced to block.
    if ( (topLeft == 'X' && bottomRight == 'X')
         || (topRight == 'X' && bottomLeft == 'X') )
    {
        std::vector <int> sides = {1, 3, 5, 7};

        int randomIndex = rand() % sides.size();
        int side = sides[randomIndex];

        return side;
    }

    // Else if player has played center and a corner,
    // then computer must have also played a corner.
    // Block an adjacent corner, preventing a double-bind.
    if (center == 'X')
    {
        std::vector <int> adjCorners;

        if (topLeft == 'X' || bottomRight == 'X') adjCorners = {2, 6};
        if (topRight == 'X' || bottomLeft == 'X') adjCorners = {0, 8};

        int randomIndex = rand() % adjCorners.size();
        int corner = adjCorners[randomIndex];

        return corner;
    }

    // Else clever move is not necessary.
    // Player already cannot win.
    return getSimpleMove();
}


int ComputerPlayer::getWinningMove(char side)
{
    // Generate random sequence of digits 0 - 7.
    std::vector <int> sequence = {0, 1, 2, 3, 4, 5, 6, 7};
    random_shuffle(sequence.begin(), sequence.end());

    // Iterate through winning combinations in random order.
    // If any can be completed in a single move,
    // return the index corresponding to that square.
    for (int i = 0; i < (int) sequence.size(); i++)
    {
        // Get indices of each square in one winning combination.
        int firstindex = winningCombinations[i][0];
        int secondindex = winningCombinations[i][1];
        int thirdindex = winningCombinations[i][2];

        // Get state of each square in combination.
        char first = grid->getSquareState(firstindex);
        char second = grid->getSquareState(secondindex);
        char third = grid->getSquareState(thirdindex);

        // Return winning move if found.
        if (first == '.' && second == side && third == side )
        {
            return firstindex;
        }

        if (first == side && second == '.' && third == side )
        {
            return secondindex;
        }

        if (first == side && second == side && third == '.')
        {
            return thirdindex;
        }
    }

    // If no winning move found. . .
    return -1;
}


int ComputerPlayer::getAdjacentMove()
{
    // Generate random sequence of digits 0 - 7.
    std::vector <int> sequence = {0, 1, 2, 3, 4, 5, 6, 7};
    random_shuffle(sequence.begin(), sequence.end());

    // Iterate through winning combinations in random order.
    // If any have one square completed,
    // return the index corresponding to an adjacent square.
    for (int i = 0; i < (int) sequence.size(); i++)
    {
        // Get indices of each square in one winning combination.
        int firstindex = winningCombinations[i][0];
        int secondindex = winningCombinations[i][1];
        int thirdindex = winningCombinations[i][2];

        // Get state of each square in combination.
        char first = grid->getSquareState(firstindex);
        char second = grid->getSquareState(secondindex);
        char third = grid->getSquareState(thirdindex);

        // Return adjacent move if found.
        if (first == '.' && second == 'O' && third == '.' )
        {
            return firstindex;
        }

        if ( (first == 'O' && second == '.' && third == '.' )
                  || (first == '.' && second == '.' && third == 'O') )
        {
            return secondindex;
        }
    }

    // If no adjacent move found. . .
    return -1;
}


int ComputerPlayer::getRandomMove()
{
    std::vector <int> availableMoves = getAvailableMoves();

    int randomIndex = rand() % availableMoves.size();
    int move = availableMoves[randomIndex];

    return move;
}


std::vector <int> ComputerPlayer::getAvailableMoves()
{
    std::vector <int> availableMoves;

    for (int i = 0; i < 9; i++)
    {
        if (grid->getSquareState(i) == '.')
        {
            availableMoves.push_back(i);
        }
    }

    return availableMoves;
}


void ComputerPlayer::setGrid(Grid *g)
{
    grid = g;
}


void ComputerPlayer::setDifficulty(std::string diff)
{
    difficulty = diff;
}



