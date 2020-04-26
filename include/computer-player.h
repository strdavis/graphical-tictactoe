#pragma once

#include <QWidget>

class Grid;
class Square;


// Generates moves based on state of the TicTacToe grid.
// --> Contains reference to the grid.
// Stores difficulty setting.
class ComputerPlayer : public QWidget
{
    Q_OBJECT

public:
    ComputerPlayer(QWidget *parent = nullptr);

    void setDifficulty(std::string diff);
    void setGrid(Grid *grid);

public slots:
    void move();

private:
    int generateMove();
    int getWinningMove(char side);
    int getSimpleMove();
    int getCleverMove();
    int getCleverFirstMove();
    int getCleverSecondMove();
    int getAdjacentMove();
    int getRandomMove();
    std::vector <int> getAvailableMoves();

    Grid *grid;
    int winningCombinations[8][3];
    std::string difficulty;
};
