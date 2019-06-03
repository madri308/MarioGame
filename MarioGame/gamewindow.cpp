#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "iostream"

GameWindow::GameWindow(QWidget *parent, QCheckBox *listItem[10]) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/BackGround1.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    images[0] = ui->label;
    images[1] = ui->label_2;
    images[2] = ui->label_3;
    images[3] = ui->label_4;
    images[4] = ui->label_5;
    images[5] = ui->label_6;

    this->board = new Board();  //Crea el tablero y lo setea como atributo
    for(int i = 0 ; i<10 ; i++){
        QCheckBox *item = listItem[i];
        if(item->checkState() == 2){
            QIcon icon = item->icon();
            QPixmap pixmap = icon.pixmap(icon.actualSize(QSize(32, 32)));
            images[quantPlayers]->setPixmap(pixmap);
            quantPlayers++;
        }
    }}

GameWindow::~GameWindow()
{
    delete ui;
}
