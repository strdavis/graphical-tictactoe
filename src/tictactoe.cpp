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


#include "tictactoe.h"

#include <iostream>

#include "title-screen.h"
#include "diff-select-screen.h"
#include "game-screen.h"
#include "computer-player.h"


TicTacToe::TicTacToe(QWidget *parent) : QWidget(parent)
{
    // Fit widget to window.
    setGeometry(parent->rect());

    // Initialize high-level components.
    computerPlayer = new ComputerPlayer(this);

    titleScreen = new TitleScreen(this);

    diffSelectScreen = new DiffSelectScreen(this, computerPlayer);

    gameScreen = new GameScreen(this, computerPlayer);

    // Connect signals and slots.
    connect(titleScreen, SIGNAL (disabled()), diffSelectScreen, SLOT (enable()));
    connect(diffSelectScreen, SIGNAL (disabled()), gameScreen, SLOT (enable()));
    connect(gameScreen, SIGNAL (disabled()), diffSelectScreen, SLOT (enable()));

    // Start game.
    titleScreen->enable();
}

