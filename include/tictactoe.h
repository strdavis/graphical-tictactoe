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

class QLabel;

class ComputerPlayer;
class TitleScreen;
class DiffSelectScreen;
class GameScreen;


// Highest-level widget drawing to the window.
// Defines the interactions of the other high-level widgets.
// --> Contains three "screens" which are sequentially
// --> enabled / disabled by player interaction, in the following order:
//
// Title Screen --> Difficulty Select Screen --> Game Screen
//                            ^                      |
//                            |______________________|
//
// **NOTE**
// Game difficulty is part of computer player's internal state.
// It is set by the difficulty select screen, and used by
// the game screen, so they both need a reference to computerPlayer.
class TicTacToe : public QWidget
{
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = nullptr);

signals:
    void toTitleScreen();

private:
    ComputerPlayer *computerPlayer;
    TitleScreen *titleScreen;
    DiffSelectScreen *diffSelectScreen;
    GameScreen *gameScreen;
};
