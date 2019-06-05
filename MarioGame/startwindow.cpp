#include "startwindow.h"
#include "gamewindow.h"
#include "ui_startwindow.h"
#include "iostream"
#include "choosewindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    this->itemList[0] = ui->toad;
    this->itemList[1] = ui->daisy;
    this->itemList[2] = ui->koopa;
    this->itemList[3] = ui->luigi;
    this->itemList[4] = ui->mario;
    this->itemList[5] = ui->peach;
    this->itemList[6] = ui->wario;
    this->itemList[7] = ui->yoshi;
    this->itemList[8] = ui->shyguy;
    this->itemList[9] = ui->donkey_kong;


    for(QCheckBox *item:this->itemList){
        connect(item, SIGNAL(stateChanged(int)), this, SLOT(checkPlayers(int)));
    }
    connect(ui->play, SIGNAL(released()), this, SLOT(play()));

    ui->play->hide();

}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::checkPlayers(int s)
{
    if(s == 2){
        this->playersCount++;
        if(playersCount == 6){
            for(QCheckBox *item:this->itemList){
                if(item->checkState() == 0){
                    item->setEnabled(false);
                }
            }
        }
    }else{
        if(playersCount == 6){
            for(QCheckBox *item:this->itemList){
                if(item->checkState() == 0){
                    item->setEnabled(true);
                }
            }
        }
        this->playersCount--;

    }
    if(playersCount > 1){
        ui->play->show();
    }else{
        ui->play->hide();
    }
}

void StartWindow::play()
{
    this->close();
    ChooseWindow *c = new ChooseWindow();
    int quantPlayers = 0;
    for(int i = 0 ; i<10 ; i++){
        QCheckBox *item = itemList[i];
        if(item->checkState() == 2){ //SI FUE SELECCIONADO
            QIcon icon = item->icon(); //SACA EL ICONO
            QPixmap pixmap = icon.pixmap(icon.actualSize(QSize(50, 50)));//LO CONVIERTE EN PIXMAP

            c->images[quantPlayers]->setPixmap(pixmap);
            c->images[quantPlayers]->setObjectName(item->objectName());
            c->textList[quantPlayers]->show();

            quantPlayers++;//AUMENTA LA CANTIDAD DE JUGADORES
        }
    }
    c->playerCount = this->playersCount;
    c->show();
}
