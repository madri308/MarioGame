#ifndef MEMORYWINDOW_H
#define MEMORYWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include "gamewindow.h"
#include <QLabel>
namespace Ui {
class MemoryWindow;
}

class MemoryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MemoryWindow(QWidget *parent = nullptr);
    QPushButton *matrix[3][6];
    QPushButton *currentCard = nullptr;
    QPushButton *prevButton = nullptr;
    QString imgs[9][2] = {{":/img/mario.png","2"},
                          {":/img/piranha.png","2"},
                          {":/img/mushroom.png","2"},
                          {":/img/toad.jpg","2"},
                          {":/new/bomber/bomb.png","2"},
                          {":/DKK.png","2"},
                          {":/peach.png","2"},
                          {":/waluigi.png","2"},
                          {":/luigi.png","2"}};
    QString usedImgs[18];
    bool checkIfUsed(QString ar[],QString text);
    GameWindow *g;
    QLabel*player1;
    QLabel*player2;
    int player1Count = 0;
    int player2Count = 0;
    int pairs = 0;
    int turn = 0;
    int counter = 0;
    void generateMatrix();
    ~MemoryWindow();

private:
    Ui::MemoryWindow *ui;
private slots:
    void onClicked();
};

#endif // MEMORYWINDOW_H
