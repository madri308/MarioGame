#ifndef BOMBERWINDOW_H
#define BOMBERWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "gamewindow.h"
namespace Ui {
class BomberWindow;
}

class BomberWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BomberWindow(QWidget *parent = nullptr);
    int totalBombs = 10;
    bool won = false;
    QPushButton *matrix10[10][10];
    QPushButton *matrix15[15][15];
    QPushButton *matrix20[20][20];
    int matrixSize  =  0;
    GameWindow *g;
    //int treasureCount;
    void setMatrixSize();
    void generateMatrix();
    ~BomberWindow();

private:
    Ui::BomberWindow *ui;
private slots:
    void onButtonClicked();
};

#endif // BOMBERWINDOW_H
