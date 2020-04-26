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


#include "custom-qlabel.h"

#include <QTimer>
#include <iostream>

#include "custom-qmovie.h"


CustomQLabel::CustomQLabel(QWidget *parent) : QLabel(parent)
{
    animation = new CustomQMovie(this);
}


void CustomQLabel::startAnimation()
{
    animation->start();
}


void CustomQLabel::stopAnimation()
{
    animation->stopAndHide();
}


void CustomQLabel::pauseAnimation()
{
    animation->pause();
}


void CustomQLabel::playAnimationOnce()
{
    animation->playOnce();

    disableGlobalInputFor(animation->getDuration());
}


void CustomQLabel::disableGlobalInputFor(int duration)
{
    // Disable global input
    window()->setEnabled(false);

    // Wait for animation to finish, then re-enable global input.
    QTimer::singleShot(duration, this, SLOT(enableGlobalInput()));
}


void CustomQLabel::enableGlobalInput()
{
    window()->setEnabled(true);
}


int CustomQLabel::getAnimationDuration()
{
    return animation->getDuration();
}


void CustomQLabel::setAnimation(const char *path)
{
    animation->setFileName(path);
    animation->setScaledSize(this->size());
    setMovie(animation);
}
