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



