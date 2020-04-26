#pragma once

#include <QLabel>

class CustomQMovie;


// Provides streamlined handling of animations on QLabels.
class CustomQLabel : public QLabel
{
    Q_OBJECT

public:
    CustomQLabel(QWidget *parent = nullptr);

    void setAnimation(const char *path);
    void startAnimation();
    void stopAnimation();
    void pauseAnimation();
    int getAnimationDuration();

public slots:
    void playAnimationOnce();

protected:
    CustomQMovie *animation;

private slots:
    void enableGlobalInput();

private:
    void disableGlobalInputFor(int duration);
};
