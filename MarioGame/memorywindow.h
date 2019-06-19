#ifndef MEMORYWINDOW_H
#define MEMORYWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MemoryWindow;
}

class MemoryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MemoryWindow(QWidget *parent = nullptr);
    QPushButton *currentCard;
    QPushButton *prevCard;
    QString images[9] = {":/img/banana.png",":/img/goomba.png",":/img/koopa.png",":/img/flower.png",":/img/greenShell.png",
                         ":/img/piranha.png",":/img/shyGuy.png",":/img/coin.png",":/img/mushroom.png"};
    QPushButton *matrix[3][6];
    void generateMatrix();
    ~MemoryWindow();

private slots:


private:
    Ui::MemoryWindow *ui;
};

#endif // MEMORYWINDOW_H
