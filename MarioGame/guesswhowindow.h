#ifndef GUESSWHOWINDOW_H
#define GUESSWHOWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "gamewindow.h"
namespace Ui {
class GuessWhoWindow;
}

class GuessWhoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GuessWhoWindow(QWidget *parent = nullptr);
    void fillWithBoxes();
    void setLimit();
    QPushButton *matrix[10][10];
    QString characters[15] = {":/char/birdo.jpg",":/char/boo.png",":/char/bowser.png",":/char/floruga.png",":/char/goomba.png",":/char/greenturtle.jpg",
                              ":/char/kingboo.png",":/char/koopa.png",":/char/luigi.png",":/char/mario.png",":/char/peach.png",":/char/redkoopa.png",
                              ":/char/toad.jpg",":/char/yoshi.jpg",":/char/magikoopa.jpg"};
    QString currentCharacter;
    int counter = 0;
    int limit = 0;
    int limitToText = 0;
    bool won;
    GameWindow *g;
    ~GuessWhoWindow();

private:
    Ui::GuessWhoWindow *ui;
private slots:
    void onButtonClicked();
    void on_luigi_clicked();
    void on_peach_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_Boo_clicked();
    void on_toad_clicked();
    void on_yoshi_clicked();
    void on_bowser_clicked();
    void on_koopa_clicked();
    void on_birdo_clicked();
    void on_KingBoo_clicked();
    void on_mario_clicked();
    void on_goomba_clicked();
    void on_Floruga_clicked();
    void on_magikoopa_clicked();
};

#endif // GUESSWHOWINDOW_H
