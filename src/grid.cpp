#include "grid.h"

#include <iostream>
#include <QTimer>

#include "square.h"
#include "custom-qlabel.h"


Grid::Grid(QWidget *parent) : CustomQWidget(parent), turn(0)
{
    strikeThroughAnimation = addLabel(0, 0, 300, 300);

    gridLines = addLabel(0, 0, 300, 300);
    gridLines->setAnimation(":/draw-grid.gif");

    // Initialize squares.
    // Squares are stored in a 1D array.
    // Array indices correspond to on-screen positions as follows:
    //
    //                                            [0][1][2]
    //  [0][1][2][3][4][5][6][7][8]   ========>   [3][4][5]
    //                                            [6][7][8]
    //
    //
    int squareSize = 100;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int index = (3 * i) + j;
            int xPos = j * squareSize;
            int yPos = i * squareSize;

            squares[index] = addSquare(xPos, yPos, squareSize, squareSize);
            squares[index]->setPosition(index);
        }
    }

    // Connect signals and slots.
    for (int i = 0; i < 9; i++)
    {
        connect (squares[i], SIGNAL (released()), this, SLOT (squareClicked()));
    }

    connect (this, SIGNAL (moveDone()), this, SLOT (checkForWin()));
}


void Grid::squareClicked()
{
    // Get pointer to square that was clicked
    Square *square = dynamic_cast <Square*> (QObject::sender());

    // If square has not been played, save player move.
    if (square->getState() == '.')
    {
        int index = square->getPosition();
        saveMove(index, 'X');
    }
}


void Grid::saveMove(int index, char side)
{
    squares[index]->setState(side);
    squares[index]->playMoveAnimation(side);

    int duration = squares[index]->getAnimationDuration();

    if (turn > 3)
    {
        // Game is a draw.
        // Wait for animation to finish then signal game over.
        QTimer::singleShot(duration + 200, this, SIGNAL (gameOver()));
        // Signal detected by:
        //     gameScreen->promptForReset();
    }
    else
    {
        // Wait for animation to finish then check for win.
        QTimer::singleShot(duration, this, SIGNAL (moveDone()));
        // Signal detected by:
        //     this->checkForWin();
    }

    lastToMove = side;
    if (lastToMove == 'O')
    {
        turn++;
    }
}


void Grid::checkForWin()
{
    int winningCombination = getWinningCombination(lastToMove);

    if (winningCombination > -1)
    {
        playStrikeThroughAnimation(winningCombination);
    }
    else if (lastToMove == 'X')
    {
        emit readyForComputerMove();
    }
}


int Grid::getWinningCombination(char side)
{
    // Intialize 2D array storing the 8 winning combinations,
    // as represented by the positions of their constituent squares.
    int winningCombinations[8][3] =
        { {0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6} };

    // Iterate through winning combinations.
    // If any have been completed,
    // return the index corresponding to that combination.
    for (int i = 0; i < 8; i++)
    {
        // Get index of each square in one winning combination.
        int firstindex = winningCombinations[i][0];
        int secondindex = winningCombinations[i][1];
        int thirdindex = winningCombinations[i][2];

        // Get state of each square in combination.
        char first = squares[firstindex]->getState();
        char second = squares[secondindex]->getState();
        char third = squares[thirdindex]->getState();

        // Return index of winning combination if found.
        if (first == side && second == side && third == side )
        {
            return i;
        }
    }

    return -1;
}


void Grid::playStrikeThroughAnimation(int winningCombination)
{
    strikeThroughAnimation->raise();

    switch(winningCombination)
    {
        case 0: strikeThroughAnimation->setAnimation(":/draw-strikethrough-0.gif"); break;

        case 1: strikeThroughAnimation->setAnimation(":/draw-strikethrough-1.gif"); break;

        case 2: strikeThroughAnimation->setAnimation(":/draw-strikethrough-2.gif"); break;

        case 3: strikeThroughAnimation->setAnimation(":/draw-strikethrough-3.gif"); break;

        case 4: strikeThroughAnimation->setAnimation(":/draw-strikethrough-4.gif"); break;

        case 5: strikeThroughAnimation->setAnimation(":/draw-strikethrough-5.gif"); break;

        case 6: strikeThroughAnimation->setAnimation(":/draw-strikethrough-6.gif"); break;

        case 7: strikeThroughAnimation->setAnimation(":/draw-strikethrough-7.gif"); break;
    }

    strikeThroughAnimation->playAnimationOnce();

    // Wait for animation to finish, then signal game over.
    // A 500 ms delay improves UX pacing.
    int duration = strikeThroughAnimation->getAnimationDuration() + 500;
    QTimer::singleShot(duration, this, SIGNAL (gameOver()));
    // Signal detected by:
    //     gameScreen->promptForReset();
}


void Grid::reset()
{
    gridLines->stopAnimation();

    for (int i = 0; i < 9; i++)
    {
        squares[i]->reset();
    }

    strikeThroughAnimation->stopAnimation();
    strikeThroughAnimation->lower();

    turn = 0;
}


Square *Grid::addSquare(int x, int y, int w, int h)
{
    Square *square = new Square(this);
    square->setGeometry(x, y, w, h);

    return square;
}


void Grid::enable()
{
    setEnabled(true);

    gridLines->playAnimationOnce();

    raise();
}


void Grid::disable()
{
    setEnabled(false);
}


int Grid::getTurn()
{
    return turn;
}


char Grid::getSquareState(int index)
{
    return squares[index]->getState();
}
