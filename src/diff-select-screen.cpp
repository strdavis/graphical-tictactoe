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
