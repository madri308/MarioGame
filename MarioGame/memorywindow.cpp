#include "memorywindow.h"
#include "ui_memorywindow.h"
#include <QPixmap>
#include <QIcon>
#include <QDebug>
#include <time.h>
MemoryWindow::MemoryWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MemoryWindow)
{
    ui->setupUi(this);
    ui->player1 = player1;
    ui->player1 = player2;
    generateMatrix();
}

bool MemoryWindow::checkIfUsed(QString ar[], QString text)
{
    int c = 0;
    for(int i = 0; i < 18;i++)
    {
        if(ar[i] == text)
        {
            c++;
        }
    }

    if(c >= 2)
    {
        return true;
    }
    else {
        return false;
    }
}

void MemoryWindow::generateMatrix()
{
    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 6;column++)
        {
            matrix[row][column] = new QPushButton("", ui->memoryFrame);
            QPixmap pix(":/img/block.jpg");
            QIcon ico(pix);
            matrix[row][column]->setIcon(pix);
            matrix[row][column]->setIconSize(QSize(100,190));
            connect(matrix[row][column],SIGNAL(clicked()),this,SLOT(onClicked()));
            ui->memoryLayout->addWidget(matrix[row][column],row,column);
            matrix[row][column]->show();
        }
    }
    srand(time(NULL));
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(matrix[i][j]->accessibleName() == "")
            {
                int random = rand()%9;
                QString pic = imgs[random][0];
                while(imgs[random][1] == "0"){
                    random = rand()%9;
                    pic = imgs[random][0];
                }
                imgs[random][1] = QString::number(imgs[random][1].toInt()-1);
                //qDebug() << pic;
                int randC = rand()%6;
                int randR = rand()%3;
                //qDebug() << randR << "x" << randC;
                matrix[i][j]->setAccessibleName(pic);
            }
            else {
                continue;
            }
        }
    }
}

MemoryWindow::~MemoryWindow()
{
    delete ui;
}

void MemoryWindow::onClicked()
{
    QPixmap block( ":/new/bomber/block.jpg" );
    QIcon bl(block);
    QPixmap pix( ((QPushButton*)sender())->accessibleName() );
    QIcon ico(pix);
    if(pairs<9)
    {
        if(currentCard == nullptr)
        {
            currentCard = (QPushButton*)sender();
            ((QPushButton*)sender())->setIcon(ico);
            counter++;
        }
        else {
            qDebug() << counter;
            if(counter < 2)
            {
                turn++;
                qDebug()<<"Turno: " << turn;
                prevButton = currentCard;
                currentCard = (QPushButton*)sender();
                ((QPushButton*)sender())->setIcon(ico);
                counter++;
                if(prevButton->accessibleName() == currentCard->accessibleName()){
                    pairs++;
                    prevButton->hide();
                    currentCard->hide();
                    if(turn%2 == 1)
                    {
                        player1Count++;
                        ui->player1score->setText(QString::number(player1Count));

                    }
                    else {
                        player2Count++;
                        ui->player2score->setText(QString::number(player2Count));
                    }
                }

            }
            else {
                currentCard->setIcon(bl);
                prevButton->setIcon(bl);
                currentCard = (QPushButton*)sender();
                ((QPushButton*)sender())->setIcon(ico);
                counter = 1;
            }
        }
    }
    else {
        if(player1Count > player2Count)
        {
            g->msgBox.setWindowTitle("Ganaste");
            g->msgBox.setText("Has ganado");
            g->msgBox.setIconPixmap(g->player->icon);
            g->msgBox.exec();
            g->move(g->player,g->newWhereIs);
            g->pos--;
            g->showMaximized();
            this->hide();
        }
        else {
            g->msgBox.setWindowTitle("Perdiste");
            g->msgBox.setText("Perdiste");
            g->msgBox.setIconPixmap(g->player->icon);
            g->msgBox.exec();
            g->move(g->player,g->newWhereIs);
            g->pos--;
            g->showMaximized();
            this->hide();
        }
    }
}
