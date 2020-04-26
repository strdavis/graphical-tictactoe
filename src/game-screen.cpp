#include "game-screen.h"

#include <iostream>

#include "button.h"
#include "grid.h"
#include "computer-player.h"


GameScreen::GameScreen(QWidget *parent, ComputerPlayer *comp)
    : CustomQWidget(parent), computerPlayer(comp)
{
    grid = new Grid(this);

    computerPlayer->setGrid(grid);

    reset = addButton(0, 0, 300, 300);

    // Connect signals and slots.
    connect (grid, SIGNAL (readyForComputerMove()), computerPlayer, SLOT (move()));
    connect (grid, SIGNAL (gameOver()), this, SLOT (promptForReset()));
    connect (reset, SIGNAL (released()), this, SLOT (resetClicked()));
}


void GameScreen::promptForReset()
{
    reset->raise();

    reset->setAnimation(":/reset-grey.gif");
    reset->startAnimation();
}


void GameScreen::resetClicked()
{
    grid->reset();

    disable();
}


void GameScreen::enable()
{
    grid->enable();

    setEnabled(true);

    raise();
}


void GameScreen::disable()
{
    reset->stopAnimation();

    setEnabled(false);

    lower();

    emit disabled();
    // Signal detected by:
    //     DiffSelectScreen->enable()
}



