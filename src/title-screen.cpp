#include "title-screen.h"

#include <iostream>

#include "custom-qlabel.h"
#include "button.h"


TitleScreen::TitleScreen(QWidget *parent) : CustomQWidget(parent)
{
    background = addLabel(0, 0, 300, 300);
    background->setAnimation(":/title-screen.gif");

    play = addButton(0, 200, 100, 100);

    connect(play, SIGNAL (released()), this, SLOT (playClicked()));
}


void TitleScreen::playClicked()
{
    disable();

    emit disabled();
    // Signal detected by:
    //     DiffSelectScreen->enable()
}


void TitleScreen::enable()
{
    setEnabled(true);

    background->startAnimation();

    raise();
}

void TitleScreen::disable()
{
    setEnabled(false);

    background->stopAnimation();

    lower();
}



