#include "bomberwindow.h"
#include "ui_bomberwindow.h"
#include <QPixmap>
#include <QIcon>
#include <time.h>
#include <QDebug>
#include <QStringList>
#include <QMessageBox>

int globalE = 0;

BomberWindow::BomberWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BomberWindow)
{
    ui->setupUi(this);
    ui->goback->hide();
    ui->cantBombas->setText(QString::number(totalBombs));
    setMatrixSize();
    generateMatrix();

}

void BomberWindow::setMatrixSize()
{
    srand(time(NULL));
    int possibilities[3] = {10,15,20};
    int randSize = rand()%3;
    matrixSize = possibilities[randSize];
    qDebug() << matrixSize;
}

void BomberWindow::generateMatrix()
{
    if(matrixSize == 10)
    {
        for (int row = 0; row < matrixSize; row++)
        {
            for (int column = 0; column < matrixSize; column++)
            {
                matrix10[row][column] = new QPushButton("",ui->bomberFrame);
                matrix10[row][column]->setAccessibleName(QString::number(row)+"."+QString::number(column));
                QPixmap block(":/new/bomber/block.jpg");
                QIcon blockIcon(block);
                matrix10[row][column]->setIcon(blockIcon);
                matrix10[row][column]->setIconSize(QSize(100,170));
                QObject::connect(matrix10[row][column],SIGNAL(clicked()),this,SLOT(onButtonClicked()));
                ui->bomberLayout->addWidget(matrix10[row][column],row,column);
                matrix10[row][column]->show();
            }
        }
        int treasureRow = rand() % matrixSize/2;
        int treasureColumn = rand() % matrixSize/2;
        qDebug() <<"El tesoro esta en: " << treasureRow << "x" << treasureColumn;
        matrix10[treasureRow][treasureColumn]->setAccessibleName("Treasure");
        matrix10[treasureRow+1][treasureColumn]->setAccessibleName("Treasure");
        matrix10[treasureRow][treasureColumn+1]->setAccessibleName("Treasure");
        matrix10[treasureRow+1][treasureColumn+1]->setAccessibleName("Treasure");
    }
    else if (matrixSize==15)
    {
        for (int row = 0; row < matrixSize; row++)
        {
            for (int column = 0; column < matrixSize; column++)
            {
                matrix15[row][column] = new QPushButton("",ui->bomberFrame);
                matrix15[row][column]->setAccessibleName(QString::number(row)+"."+QString::number(column));
                QPixmap block(":/new/bomber/block.jpg");
                QIcon blockIcon(block);
                matrix15[row][column]->setIcon(blockIcon);
                matrix15[row][column]->setIconSize(QSize(100,170));
                QObject::connect(matrix15[row][column],SIGNAL(clicked()),this,SLOT(onButtonClicked()));
                ui->bomberLayout->addWidget(matrix15[row][column],row,column);
                matrix15[row][column]->show();
            }
        }
        int treasureRow = rand() % matrixSize/2;
        int treasureColumn = rand() % matrixSize/2;
        qDebug() <<"El tesoro esta en: " << treasureRow << "x" << treasureColumn;
        matrix15[treasureRow][treasureColumn]->setAccessibleName("Treasure");
        matrix15[treasureRow+1][treasureColumn]->setAccessibleName("Treasure");
        matrix15[treasureRow][treasureColumn+1]->setAccessibleName("Treasure");
        matrix15[treasureRow+1][treasureColumn+1]->setAccessibleName("Treasure");
    }
    else if (matrixSize == 20)
    {
        for (int row = 0; row < matrixSize; row++)
        {
            for (int column = 0; column < matrixSize; column++)
            {
                matrix20[row][column] = new QPushButton("",ui->bomberFrame);
                matrix20[row][column]->setAccessibleName(QString::number(row)+"."+QString::number(column));
                QPixmap block(":/new/bomber/block.jpg");
                QIcon blockIcon(block);
                matrix20[row][column]->setIcon(blockIcon);
                matrix20[row][column]->setIconSize(QSize(100,170));
                QObject::connect(matrix20[row][column],SIGNAL(clicked()),this,SLOT(onButtonClicked()));
                ui->bomberLayout->addWidget(matrix20[row][column],row,column);
                matrix20[row][column]->show();
            }
        }
        int treasureRow = rand() % matrixSize/2;
        int treasureColumn = rand() % matrixSize/2;
        qDebug() <<"El tesoro esta en: " << treasureRow << "x" << treasureColumn;
        matrix20[treasureRow][treasureColumn]->setAccessibleName("Treasure");
        matrix20[treasureRow+1][treasureColumn]->setAccessibleName("Treasure");
        matrix20[treasureRow][treasureColumn+1]->setAccessibleName("Treasure");
        matrix20[treasureRow+1][treasureColumn+1]->setAccessibleName("Treasure");
    }
}
BomberWindow::~BomberWindow()
{
    delete ui;
}

void BomberWindow::onButtonClicked()
{
    qDebug() << globalE;

    if(totalBombs >= 0)
    {
        totalBombs--;
        ui->cantBombas->setText(QString::number(totalBombs));
        QPixmap bomb(":/new/bomber/bomb.png");
        QIcon bombIcon(bomb);

        QPixmap treasure(":/new/bomber/coin.png");
        QIcon treasureIcon(treasure);

        ((QPushButton*)sender())->setIcon(bomb);

        QStringList number = ((QPushButton*)sender())->accessibleName().split(".");

        qDebug() << number;
        if( ((QPushButton*)sender())->accessibleName() == "Treasure")
        {
            ((QPushButton*)sender())->setIcon(treasureIcon);
            globalE++;
        }
        else{
            if(matrixSize == 10)
            {
                int row = number[0].toInt();
                int column = number[1].toInt();
                if(column+1 < 10)
                {
                    if(matrix10[row][column+1]->accessibleName() == "Treasure")
                    {
                        matrix10[row][column+1]->setIcon(treasure);
                        globalE++;
                    }
                    else{
                        matrix10[row][column+1]->hide();
                    }

                }
                if(row+1 < 10)
                {
                    if(matrix10[row+1][column]->accessibleName() == "Treasure")
                    {
                        matrix10[row+1][column]->setIcon(treasure);
                        globalE++;
                    }
                    else{
                        matrix10[row+1][column]->hide();
                    }
                }
                if(row+1 < 10 && column+1 < 10)
                {
                    if(matrix10[row+1][column+1]->accessibleName() == "Treasure")
                    {
                        matrix10[row+1][column+1]->setIcon(treasure);
                        globalE++;
                    }
                    else{
                        matrix10[row+1][column+1]->hide();
                    }
                }
                if(globalE == 4)
                {
                    g->msgBox.setWindowTitle("Ganaste");
                    g->msgBox.setText("Has encontrado el tesoro");
                    g->msgBox.setIconPixmap(g->player->icon);
                    g->msgBox.exec();
                    g->move(g->player,g->newWhereIs);
                    g->pos--;
                    g->showMaximized();
                    this->hide();
                }
            }
            else if(matrixSize == 15)
            {
                int row = number[0].toInt();
                int column = number[1].toInt();
                if(column+1 < 15)
                {
                    if(matrix15[row][column+1]->accessibleName() == "Treasure")
                    {
                        matrix15[row][column+1]->setIcon(treasure);
                        globalE++;
                    }
                    else{
                        matrix15[row][column+1]->hide();
                    }

                }
                if(row+1 < 15)
                {
                    if(matrix15[row+1][column]->accessibleName() == "Treasure")
                    {
                        matrix15[row+1][column]->setIcon(treasure);
                        globalE++;
                    }
                    else{
                        matrix15[row+1][column]->hide();
                    }
                }
                if(row+1 < 15 && column+1 < 15)
                {
                    if(matrix15[row+1][column+1]->accessibleName() == "Treasure")
                    {
                        matrix15[row+1][column+1]->setIcon(treasure);
                        globalE++;
                    }
                    else{
                        matrix15[row+1][column+1]->hide();
                    }
                }
                if(globalE == 4)
                {
                    g->msgBox.setWindowTitle("Ganaste");
                    g->msgBox.setText("Has encontrado el tesoro");
                    g->msgBox.setIconPixmap(g->player->icon);
                    g->msgBox.exec();
                    g->move(g->player,g->newWhereIs);
                    g->pos--;
                    g->showMaximized();
                    this->hide();
                }
            }
            else if(matrixSize == 20)
            {
                int row = number[0].toInt();
                int column = number[1].toInt();
                if(column+1 < 20)
                {
                    if(matrix20[row][column+1]->accessibleName() == "Treasure")
                    {
                        matrix20[row][column+1]->setIcon(treasure);
                        globalE++;
                    }
                    else{
                        matrix20[row][column+1]->hide();
                    }

                }
                if(row+1 < 20)
                {
                    if(matrix20[row+1][column]->accessibleName() == "Treasure")
                    {
                        matrix20[row+1][column]->setIcon(treasure);
                        globalE++;
                    }
                    else{
                        matrix20[row+1][column]->hide();
                    }
                }
                if(row+1 < 15 && column+1 < 15)
                {
                    if(matrix20[row+1][column+1]->accessibleName() == "Treasure")
                    {
                        matrix20[row+1][column+1]->setIcon(treasure);
                        globalE++;
                    }
                    else{
                        matrix20[row+1][column+1]->hide();
                    }
                }
                if(globalE == 4)
                {
                    g->msgBox.setWindowTitle("Ganaste");
                    g->msgBox.setText("Has encontrado el tesoro");
                    g->msgBox.setIconPixmap(g->player->icon);
                    g->msgBox.exec();
                    g->move(g->player,g->newWhereIs);
                    g->pos--;
                    g->showMaximized();
                    this->hide();
                }
            }
        }

    }
    else{
        QMessageBox::information(this,tr(""),tr("Te has quedado sin bombas"));
        if(globalE == 4)
        {
            g->msgBox.setWindowTitle("Ganaste");
            g->msgBox.setText("Has encontrado el tesoro");
            g->msgBox.setIconPixmap(g->player->icon);
            g->msgBox.exec();
            g->move(g->player,g->newWhereIs);
            g->pos--;
            g->showMaximized();
            this->hide();
        }
        else {
            g->msgBox.setWindowTitle("Perdiste");
            g->msgBox.setText("No has encontrado el tesoro");
            g->msgBox.setIconPixmap(g->player->icon);
            g->msgBox.exec();
            g->showMaximized();
            this->hide();
        }
    }
}
