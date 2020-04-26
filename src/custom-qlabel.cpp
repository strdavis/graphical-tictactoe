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
