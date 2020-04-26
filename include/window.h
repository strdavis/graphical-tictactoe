#pragma once

#include <QWidget>

class QMenuBar;
class QMenu;
class QAction;

class TicTacToe;


// Top-level widget.
// --> All graphical widgets draw to this window.
// Controls menu-bar.
class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);

private slots:
    void newGame();

private:
    void centerWindow();

    QMenuBar *menuBar;
    QMenu *menu;
    QAction *selectNewGame;
    TicTacToe *tictactoe;
};
