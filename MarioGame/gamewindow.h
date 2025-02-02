#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "board.h"
#include "player.h"
#include "QPushButton"
#include "QLabel"
#include "QMessageBox"
#include "QGridLayout"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent,Player *players[], int pc);
    ~GameWindow();

    Board *board;
    QPushButton *images[6];
    QLabel *names[6];
    int quantPlayers = 0;
    Player *playerList[6];
    QMessageBox msgBox;

    int pos = 0;
    int select = 0;

    QGridLayout *CImages[26];
    QLabel *CNames[26];
    Node *newWhereIs;
    Player *player;

    void start();
    void move(Player *whereIs,Node *newPos);
    void showMinWin(QString text, QPixmap icon, QString title);
public slots:
    void throwDices();
    void showPlayerInfo(int b);
    void showMatrix();
    void showWays();
    void cola();
private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
