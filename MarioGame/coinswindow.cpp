#include "coinswindow.h"
#include "ui_coinswindow.h"
#include <QDebug>
#include <time.h>
#include <QPixmap>
#include <QIcon>
#include <QMessageBox>
CoinsWindow::CoinsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CoinsWindow)
{
    ui->setupUi(this);
    ui->goBack->hide();
    gameTimer = new QTimer;
    connect(this->gameTimer,SIGNAL(timeout()),this,SLOT(updateCountdown()));
    setTime();
    generateMatrix();
    gameTimer->start(1000);
}

void CoinsWindow::setTime()
{
    srand(time(NULL));
    int possibleTime[3] = {30,45,60};
    int randTime = rand() % 3;
    if (possibleTime[randTime] == 60)
    {
        actualTime = QTime(0,1,0);
    }
    else{
        actualTime = QTime(0,0,possibleTime[randTime]);
    }

    qDebug() << possibleTime[randTime];
}

void CoinsWindow::generateMatrix()
{
    for (int row = 0; row < 25; row++)
    {
        for (int column = 0; column < 25;column++)
        {
            matrix[row][column] = new QPushButton("",ui->coinFrame);
            QPixmap icon(":/new/coins/block.jpg");
            QIcon block(icon);
            matrix[row][column]->setIcon(icon);
            matrix[row][column]->setIconSize(QSize(100,170));
            QObject::connect(matrix[row][column],SIGNAL(clicked()),this,SLOT(onButtonClicked()));
            ui->coinLayout->addWidget(matrix[row][column],row,column);
            matrix[row][column]->show();
        }
    }
}
CoinsWindow::~CoinsWindow()
{
    delete ui;
}

void CoinsWindow::updateCountdown()
{
    actualTime = actualTime.addSecs(-1);
    if(actualTime.toString("m:ss") == "0:00")
    {
        ui->timeLabel->setText(actualTime.toString("m:ss"));
        QMessageBox::information(this,tr("Lo siento :("),tr("Se te ha acabado el tiempo"));
        gameTimer->stop();
        if (playerCoinCount > 0)
        {
            g->msgBox.setWindowTitle("Ganaste");
            g->msgBox.setText("Has ganado, tu cuenta de monedas es: " + QString::number(playerCoinCount));
            g->msgBox.setIconPixmap(g->player->icon);
            g->msgBox.exec();
            g->move(g->player,g->newWhereIs);
            g->showMaximized();
            this->hide();
        }
        else {
            g->msgBox.setWindowTitle("Perdiste");
            g->msgBox.setText("Has ganado, tu cuenta de monedas es: " + QString::number(playerCoinCount));
            g->msgBox.setIconPixmap(g->player->icon);
            g->msgBox.exec();
            g->showMaximized();
            this->hide();
        }
    }
    else {
        ui->timeLabel->setText(actualTime.toString("m:ss"));
    }

}

void CoinsWindow::onButtonClicked()
{
    int goodOrBad = rand()%2;
    QPixmap coin;

    if(goodOrBad == 0)
    {
        if(goodCoinCount <= 312)
        {
            int value = (rand()%10)+1;
            qDebug() << value;
            playerCoinCount += value;
            coin = QPixmap(":/new/coins/coin.png");
            QIcon newIcon(coin);
            ((QPushButton*)sender())->setIcon(newIcon);
            goodCoinCount++;
        }
        else if (badCoinCount <= 312){
            int value = (rand()%10)+1;
            qDebug() << "-" <<value;
            playerCoinCount -= value;
            coin = QPixmap(":/new/coins/redcoin.png");
            QIcon newIcon(coin);
            ((QPushButton*)sender())->setIcon(newIcon);
            badCoinCount++;
        }
        else if (badCoinCount == 312 && goodCoinCount == 312)
        {
            QMessageBox::information(this,tr("No mas intentos"),tr("Ya no hay más monedas"));
        }
    }
    else {
        if(badCoinCount <= 312)
        {
            int value = (rand()%10)+1;
            qDebug() << "-" <<value;
            playerCoinCount -= value;
            coin = QPixmap(":/new/coins/redcoin.png");
            QIcon newIcon(coin);
            ((QPushButton*)sender())->setIcon(newIcon);
            badCoinCount++;
        }
        else if(goodCoinCount <= 312) {
            int value = (rand()%10)+1;
            qDebug() << value;
            playerCoinCount += value;
            coin = QPixmap(":/new/coins/coin.png");
            QIcon newIcon(coin);
            ((QPushButton*)sender())->setIcon(newIcon);
            goodCoinCount++;
        }
        else if (badCoinCount == 312 && goodCoinCount == 312)
        {
            QMessageBox::information(this,tr("No mas intentos"),tr("Ya no hay más monedas"));
        }
    }
}
