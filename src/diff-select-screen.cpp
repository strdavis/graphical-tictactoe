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


#include "diff-select-screen.h"

#include <iostream>

#include "custom-qlabel.h"
#include "button.h"
#include "computer-player.h"


DiffSelectScreen::DiffSelectScreen(QWidget *parent, ComputerPlayer *comp) : CustomQWidget(parent), computerPlayer(comp)
{
    background = addLabel(0, 0, 300, 300);
    background->setAnimation(":/difficulty-select-screen.gif");

    easy = addButton(70, 100, 145, 70);
    hard = addButton(70, 170, 145, 70);

    connect (easy, SIGNAL (released()), this, SLOT (easyClicked()));
    connect (hard, SIGNAL (released()), this, SLOT (hardClicked()));
}


void DiffSelectScreen::easyClicked()
{
    computerPlayer->setDifficulty("easy");

    disable();
}


void DiffSelectScreen::hardClicked()
{
    computerPlayer->setDifficulty("hard");

    disable();
}


void DiffSelectScreen::enable()
{
    setEnabled(true);

    background->startAnimation();

    raise();
}

void DiffSelectScreen::disable()
{
    setEnabled(false);

    background->stopAnimation();

    lower();

    emit disabled();
    // Signal detected by:
    //     GameScreen->enable()
}
