#ifndef CHOOSECARDWINDOW_H
#define CHOOSECARDWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <gamewindow.h>
#include "card.h"

namespace Ui {
class ChooseCardWindow;
}

class ChooseCardWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseCardWindow(QWidget *parent = nullptr);
    GameWindow *g;
    QString names[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    QString types[4] = {"corazon", "trebol", "picas","diamantes"};
    int cantPlayers = 6;
    int getPos(QString array[4], QString text);
    void checkCards(Card*array[6]);
    void chooseCards();
    void sortCards(Card*array[6]);
    ~ChooseCardWindow();

private:
    Ui::ChooseCardWindow *ui;
private slots:
    void onClicked();
};

#endif // CHOOSECARDWINDOW_H
