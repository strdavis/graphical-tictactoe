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
