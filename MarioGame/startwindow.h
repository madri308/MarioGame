#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include "qcheckbox.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();
    int playersCount = 0;
    QCheckBox *itemList[10];
private slots:
    void checkPlayers(int s);
    void play();
private:
    Ui::StartWindow *ui;
};

#endif // STARTWINDOW_H
