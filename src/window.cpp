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

    // Create TicTacToe widget.
    newGame();


    // (Test for memory leaks)
    for (int i = 0; i < 250; i++)
    {
        //newGame();
    }
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



