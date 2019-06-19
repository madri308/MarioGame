#ifndef PATHWINDOW_H
#define PATHWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "gamewindow.h"
namespace Ui {
class PathWindow;
}

class PathWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PathWindow(QWidget *parent = nullptr);
    QPushButton *matrix[8][3];
    int counter = 0;
    void generateMatrix();
    void randomize();
    GameWindow *g;
    ~PathWindow();

private:
    Ui::PathWindow *ui;
private slots:
    void onButtonClicked();
};

#endif // PATHWINDOW_H
