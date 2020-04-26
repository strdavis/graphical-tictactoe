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


#include "window.h"

#include <iostream>

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QRect>
#include <QDesktopWidget>

#include "tictactoe.h"


Window::Window(QWidget *parent) : QWidget(parent)
{
    // Set up window.
    setWindowTitle("TicTacToe");
    setFixedSize(300, 300);
    centerWindow();

    // Set up menu bar.
    menuBar = new QMenuBar;

    menu = new QMenu("File");

    selectNewGame = new QAction("New Game", this);

    menuBar->addMenu(menu);

    menu->addAction(selectNewGame);

    connect(selectNewGame, SIGNAL (triggered()), this, SLOT (newGame()));

    // Initialize TicTacToe widget.
    newGame();
}


void Window::newGame()
{
    if (tictactoe)
    {
        delete tictactoe;
    }

    tictactoe = new TicTacToe(this);
    tictactoe->show();
}


void Window::centerWindow()
{
    QRect position = frameGeometry();
    position.moveCenter(QDesktopWidget().availableGeometry().center());
    this->move(position.topLeft());
}



