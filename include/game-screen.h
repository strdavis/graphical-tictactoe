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

class Grid;
class ComputerPlayer;
class Button;


// This is where the game is played.
// Contains all game components.
// --> an interactive grid, computer player, and reset button.
// Displayed after the difficulty select screen.
class GameScreen : public CustomQWidget
{
    Q_OBJECT

public:
    GameScreen(QWidget *parent = nullptr, ComputerPlayer *computerPlayer = nullptr);

public slots:
    void enable() override;

private slots:
    void promptForReset();
    void resetClicked();

private:
    void disable() override;

    Grid *grid;
    ComputerPlayer *computerPlayer;
    Button *reset;
};
