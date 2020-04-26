#pragma once

#include "custom-qwidget.h"

class Grid;
class ComputerPlayer;
class Button;


// This is where the game is played.
// Contains all game components.
// --> an interactive grid, computer player, and reset button.
// Displayed after the difficulty select screen.
class GameScreen : public CustomQWidget
{
    Q_OBJECT

public:
    GameScreen(QWidget *parent = nullptr, ComputerPlayer *computerPlayer = nullptr);

public slots:
    void enable() override;

private slots:
    void promptForReset();
    void resetClicked();

private:
    void disable() override;

    Grid *grid;
    ComputerPlayer *computerPlayer;
    Button *reset;
};
