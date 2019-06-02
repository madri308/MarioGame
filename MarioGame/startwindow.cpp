#include "startwindow.h"
#include "gamewindow.h"
#include "ui_startwindow.h"
#include "iostream"

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
    std::cout<<this->playersCount<<std::endl;
}

void StartWindow::play()
{
    this->close();
    GameWindow *gm = new GameWindow(nullptr,this->itemList);
    gm->showMaximized();
}
