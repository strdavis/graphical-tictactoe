#pragma once

#include "custom-qwidget.h"

class ComputerPlayer;
class CustomQLabel;
class Button;


// Graphical menu widget.
// Displayed after the title screen, and again after each game over.
class DiffSelectScreen : public CustomQWidget
{
    Q_OBJECT

public:
    DiffSelectScreen(QWidget *parent = nullptr, ComputerPlayer *comp = nullptr);

public slots:
    void enable() override;

private slots:
    void easyClicked();
    void hardClicked();

private:
    void disable() override;

    ComputerPlayer *computerPlayer;
    CustomQLabel *background;
    Button *easy;
    Button *hard;
};
