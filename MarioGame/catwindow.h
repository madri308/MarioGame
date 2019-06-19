#ifndef CATWINDOW_H
#define CATWINDOW_H

#include <QMainWindow>
#include "QPushButton"
#include "player.h"
#include "gamewindow.h"
namespace Ui {
class CatWindow;
}

class CatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CatWindow(QWidget *parent = nullptr);
    ~CatWindow();
    QPushButton *buttons[3][3];
    QString state = "X";
    bool verifyWiner();
    bool isFull();
    QLabel *P1;
    QLabel *P2;
    QLabel *desc;
    GameWindow *g;
private:
    Ui::CatWindow *ui;
public slots:
    void changeState(int row,int column);
};

#endif // CATWINDOW_H
