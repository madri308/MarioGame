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

    this->board = new Board();  //Crea el tablero y lo setea como atributo

    for(int i = 0 ; i<10 ; i++){
        QCheckBox *item = listItem[i];
        if(item->checkState() == 2){
            std::cout<<item->objectName().toStdString()<<std::endl;
        }
    }}

GameWindow::~GameWindow()
{
    delete ui;
}
