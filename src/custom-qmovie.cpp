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


#include "custom-qmovie.h"

#include <iostream>


CustomQMovie::CustomQMovie(QObject *parent) : QMovie (parent)
{

}


void CustomQMovie::playOnce()
{
    // Track frame numbers, pause on last frame
    connect (this, &CustomQMovie::frameChanged, [this] (int frame)
    {
        if (frame == frameCount() - 1)
        {
            setPaused(true);
        }
    });

    start();
}


void CustomQMovie::pause()
{
    setPaused(true);
}


void CustomQMovie::stopAndHide()
{
    stop();

    // Workaround that forces QMovie to become invisible when stopped.
    // QMovie otherwise continues to display last-played frame until started again.

    // Get path to current file.
    QString path = fileName();
    QByteArray ba = path.toLocal8Bit();
    const char *pathCStr = ba.data();

    // Set file to a single, transparent frame.
    // --> Start/stop is required to stop displaying last-played frame.
    setFileName(":/transparent-frame.gif");
    start();
    stop();

    // Set file back to original.
    // --> CustomQMovie is now ready to play from beginning, but is not visible.
    // --> It will become visible when started.
    setFileName(pathCStr);
}


int CustomQMovie::getDuration()
{
    return frameCount() * nextFrameDelay();
}
