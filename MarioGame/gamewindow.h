#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "board.h"
#include "QCheckBox"
#include "QLabel"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent, QCheckBox *playerList[10]);
    ~GameWindow();

    Board *board;
    QLabel *images[6];
    int quantPlayers = 0;

private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
