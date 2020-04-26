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

