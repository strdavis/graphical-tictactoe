#pragma once

#include <QWidget>

class QLabel;

class ComputerPlayer;
class TitleScreen;
class DiffSelectScreen;
class GameScreen;


// Highest-level widget drawing to the window.
// Defines the interactions of the other high-level widgets.
// --> Contains three "screens" which are sequentially
// --> enabled / disabled by player interaction, in the following order:
//
// Title Screen --> Difficulty Select Screen --> Game Screen
//                            ^                      |
//                            |______________________|
//
// **NOTE**
// Game difficulty is part of computer player's internal state.
// It is set by the difficulty select screen, and used by
// the game screen, so they both need a reference to computerPlayer.
class TicTacToe : public QWidget
{
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = nullptr);

signals:
    void toTitleScreen();

private:
    ComputerPlayer *computerPlayer;
    TitleScreen *titleScreen;
    DiffSelectScreen *diffSelectScreen;
    GameScreen *gameScreen;
};
