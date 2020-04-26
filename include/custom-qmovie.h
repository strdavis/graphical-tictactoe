#pragma once

#include <QMovie>


// Provides more options for controlling QMovie playback.
class CustomQMovie : public QMovie
{
public:
    CustomQMovie(QObject *parent);

    void playOnce();
    void pause();
    void stopAndHide();
    int getDuration();
};
