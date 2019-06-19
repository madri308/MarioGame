#include "pathwindow.h"
#include "ui_pathwindow.h"
#include <time.h>
#include <QDebug>

int tries = 3;
PathWindow::PathWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PathWindow)
{
    ui->setupUi(this);
    generateMatrix();
    ui->label_2->setText(QString::number(tries));
}

void PathWindow::generateMatrix()
{
    srand(time(NULL));
    for(int row = 0; row < 8;row++)
    {
        for(int column = 0; column < 3; column++)
        {
            matrix[row][column] = new QPushButton("",ui->pathFrame);
            QPixmap icon(":/new/coins/block.jpg");
            QIcon block(icon);
            matrix[row][column]->setIcon(icon);
            matrix[row][column]->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
            matrix[row][column]->setIconSize(QSize(100,170));
            QObject::connect(matrix[row][column],SIGNAL(clicked()),this,SLOT(onButtonClicked()));
            ui->pathLayout->addWidget(matrix[row][column],row,column);
            matrix[row][column]->show();
        }
    }
    randomize();
}

void PathWindow::randomize()
{
    qDebug() << "-----------------------------------------";
    int randI = rand() % 3;
    qDebug() << randI;
    matrix[0][randI]->setAccessibleName("Good");
    randI = rand() % 3;
    qDebug() << randI;
    matrix[1][randI]->setAccessibleName("Good");
    randI = rand() % 3;
    qDebug() << randI;
    matrix[2][randI]->setAccessibleName("Good");
    randI = rand() % 3;
    qDebug() << randI;
    matrix[3][randI]->setAccessibleName("Good");
    randI = rand() % 3;
    qDebug() << randI;
    matrix[4][randI]->setAccessibleName("Good");
    randI = rand() % 3;
    qDebug() << randI;
    matrix[5][randI]->setAccessibleName("Good");
    randI = rand() % 3;
    qDebug() << randI;
    matrix[6][randI]->setAccessibleName("Good");
    randI = rand() % 3;
    qDebug() << randI;
    matrix[7][randI]->setAccessibleName("Good");
}

PathWindow::~PathWindow()
{
    delete ui;
}

void PathWindow::onButtonClicked()
{
    if(tries > 0)
    {
        if(counter < 7)
        {
            if( ((QPushButton*)sender())->accessibleName() == "Good")
            {
                QPixmap pix(":/img/check.png");
                QIcon ico(pix);
                ((QPushButton*)sender())->setIcon(ico);
                counter++;
            }
            else{
                QPixmap pix(":/new/coins/redcoin.png");
                QIcon ico(pix);
                ((QPushButton*)sender())->setIcon(ico);
                counter = 0;
                tries--;
                ui->label_2->setText(QString::number(tries));
                QPixmap block(":/new/coins/block.jpg");
                QIcon bl(block);
                for(int i = 0; i < 8; i++)
                {
                    for(int j = 0; j < 3; j++)
                    {
                        matrix[i][j]->setIcon(bl);
                    }
                }
            }
        }
        else {
            g->msgBox.setWindowTitle("Ganaste");
            g->msgBox.setText("¡Has adivinado el camino correctamente!");
            g->msgBox.setIconPixmap(g->player->icon);
            g->msgBox.exec();
            g->move(g->player,g->newWhereIs);
            //g->pos--;
            g->showMaximized();
            this->hide();
        }
    }
    else {
        g->msgBox.setWindowTitle("Perdiste");
        g->msgBox.setText("No has adivinado correctamente");
        g->msgBox.setIconPixmap(g->player->icon);
        g->msgBox.exec();
        g->showMaximized();
        this->hide();
    }
}

