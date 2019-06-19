#ifndef COINSWINDOW_H
#define COINSWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <QTime>
#include "gamewindow.h"
using namespace std;

namespace Ui {
class CoinsWindow;
}

class CoinsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CoinsWindow(QWidget *parent = nullptr);
    QPushButton *matrix[25][25];
    int redCoinCounter = 0;
    int gooodCoinCounter = 0;
    bool won = false;
    QTimer *gameTimer;
    QTime actualTime = QTime(0,0,0);
    int playerCoinCount = 0;
    int goodCoinCount = 0;
    int badCoinCount = 0;
    void setTime();
    void generateMatrix();
    GameWindow *g;
    ~CoinsWindow();

private:
    Ui::CoinsWindow *ui;
private slots:
    void updateCountdown();
    void onButtonClicked();
};

#endif // COINSWINDOW_H
