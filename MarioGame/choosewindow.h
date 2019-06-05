#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H

#include <QMainWindow>
#include "QLabel"
#include "qtextedit.h"
#include "player.h"

namespace Ui {
class ChooseWindow;
}

class ChooseWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseWindow(QWidget *parent = nullptr);
    ~ChooseWindow();
    QLabel *images[6];
    QTextEdit *textList[6];
    Player *playerList[6];
    int playerCount = 0;
    void sort(Player *list[]);

private:
    Ui::ChooseWindow *ui;
public slots:
    void getPlayers();
    void done();
};

#endif // CHOOSEWINDOW_H
