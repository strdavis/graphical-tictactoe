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



