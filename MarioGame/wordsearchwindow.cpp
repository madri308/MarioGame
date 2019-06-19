#include "wordsearchwindow.h"
#include "ui_wordsearchwindow.h"
#include <QPushButton>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <QDebug>
#include <QLabel>
#include <QMessageBox>
WordSearchWindow::WordSearchWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WordSearchWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    timer = new QTimer();
    connect(this->timer,SIGNAL(timeout()),this,SLOT(updateCountdown()));
    connect(ui->hola,SIGNAL(clicked()),this,SLOT(OnClicked()));
    generateMatrix();
    timer->start(1000);
}

void WordSearchWindow::generateMatrix()
{
         srand(time(NULL));

        int sizes[3] = {10,15,20};
        int random = rand()%3;
        int matrixSize = sizes[random];
        qDebug() << "Matrix size: " << matrixSize << "x" << matrixSize;

        QLabel *matrix[matrixSize][matrixSize];
        int randomWord = rand() % 100;
        int randomWord2 = rand() % 100;
        int randomWord3 = rand() % 100;
        int randomWord4 = rand() % 100;
        QString selectedWords[4] = {this->diccionary[randomWord],this->diccionary[randomWord2],this->diccionary[randomWord3],this->diccionary[randomWord4]};
        checkWords(selectedWords,matrixSize);

        for(int i = 0; i < 4;i++)
        {
            wordsToHide[i] = selectedWords[i];
        }
        for(int i = 0; i < 4;i++)
        {
            qDebug() << wordsToHide[i];
        }
        //LLENA LA MATRIZ DE LETRAS RANDOM
        for (int i = 0; i < matrixSize; i++)
        {
            for(int j = 0; j < matrixSize; j++)
            {
                int randIndex = rand() % 26;
                matrix[i][j] = new QLabel( alphabet[randIndex] , ui->frame);
                matrix[i][j]->setMaximumSize(31,31);

                ui->gridLayout->addWidget(matrix[i][j],i,j);
                matrix[i][j]->show();
            }
        }

        //INSERTAR LAS PALABRAS EN LA MATRIZ

        QStringList separatedWord = selectedWords[0].split("");
        QStringList separatedWord2 = selectedWords[1].split("");
        QStringList separatedWord3 = selectedWords[2].split("");
        QStringList separatedWord4 = selectedWords[3].split("");

        int randomRow = (rand() % 3)+1;
        int randomColumn = (rand() % matrixSize) + 4;
        qDebug() << "Row: " << randomRow;
        qDebug() << "Column: " << randomColumn;
        /*qDebug() << "Word:" << separatedWord;

        */
        randomColumn=0;
        for (int c = 1; c < separatedWord.length()-1;c++)
        {
            if(randomRow < matrixSize)
            {
                matrix[randomRow][randomColumn]->setText(separatedWord[c]);
                randomRow++;
            }
        }

        int randomRow2 = (rand() % 4)+1;
        int randomColumn2 = rand() % 3;

        qDebug() << "Row: " << randomRow2+1;
        qDebug() << "Column: " << randomColumn2+1;
        randomColumn2 = 1;
        for (int c = 1; c < separatedWord2.length()-1;c++)
        {
            if(randomColumn2 < matrixSize)
            {
                matrix[matrixSize-randomRow2][randomColumn2]->setText(separatedWord2[c]);
                randomColumn2++;
            }
        }


        int randomRow3 = rand() % 2;
        int randomColumn3 = rand() % 2;

        qDebug() << "Row: " << randomRow3+1;
        qDebug() << "Column: " << randomColumn3+1;
        randomRow3=0;
        randomColumn3=0;
        for (int c = 1; c < separatedWord3.length()-1;c++)
        {
            if(randomColumn3 < matrixSize && randomRow3 < matrixSize)
            {
                matrix[randomRow3][randomColumn3]->setText(separatedWord3[c]);
                randomColumn3++;
                randomRow3++;
            }
        }

        int randomRow4 = matrixSize-1;
        int randomColumn4 = matrixSize-1;

        qDebug() << "Row: " << randomRow3+1;
        qDebug() << "Column: " << randomColumn3+1;
        for (int c = 1; c < separatedWord4.length()-1;c++)
        {
            if(randomColumn4 < matrixSize && randomRow4 < matrixSize)
            {
                matrix[randomRow4][randomColumn4]->setText(separatedWord4[c]);
                randomColumn4--;
                randomRow4--;
            }
        }
}

void WordSearchWindow::checkWords(QString words[4], int size)
{
    bool allGood = true;
    for(int i = 0; i < 4; i++)
    {
        if (words[i].length() > size)
        {
            allGood = false;
            srand(time(NULL));
            int random = rand()%100;
            words[i] = diccionary[random];
        }
        else{
            continue;
        }
    }

    if (!allGood)
    {
        checkWords(words,size);
    }
}

WordSearchWindow::~WordSearchWindow()
{
    delete ui;
}

void WordSearchWindow::updateCountdown()
{
    actualTime = actualTime.addSecs(-1);
        if(actualTime.toString("m:ss") == "0:00")
        {
            ui->timer->setText(actualTime.toString("m:ss"));
            g->msgBox.setWindowTitle("Lo siento");
            g->msgBox.setText("Se te ha acabado el tiempo");
            g->msgBox.setIconPixmap(g->player->icon);
            g->msgBox.exec();
            g->showMaximized();
            this->hide();
            timer->stop();
        }
        else {
            ui->timer->setText(actualTime.toString("m:ss"));
        }
}

void WordSearchWindow::OnClicked()
{
    bool firstWordFound = false;
        bool secondWordFound = false;
        bool thirdWordFound = false;
        bool fourthWordFound = false;

        qDebug() << ui->wordEntry->text();
        for(int i = 0; i < 4; i++)
        {
            if(ui->wordEntry->text() == wordsToHide[i])
            {
                firstWordFound = true;
            }
        }
        for(int i = 0; i < 4; i++)
        {
            if(ui->wordEntry2->text() == wordsToHide[i])
            {
                secondWordFound = true;
            }
        }
        for(int i = 0; i < 4; i++)
        {
            if(ui->wordEntry3->text() == wordsToHide[i])
            {
                thirdWordFound = true;
            }
        }
        for(int i = 0; i < 4; i++)
        {
            if(ui->wordEntry4->text() == wordsToHide[i])
            {
                fourthWordFound = true;
            }
        }

        if(firstWordFound == true && secondWordFound == true && thirdWordFound == true && fourthWordFound == true)
        {
            g->msgBox.setWindowTitle("Ganaste");
            g->msgBox.setText("Has ganado");
            g->msgBox.setIconPixmap(g->player->icon);
            g->msgBox.exec();
            g->move(g->player,g->newWhereIs);
            g->pos--;
            g->showMaximized();
            this->hide();
            timer->stop();
        }
        else{
            g->msgBox.setWindowTitle("Lo siento");
            g->msgBox.setText("Has perdido");
            g->msgBox.setIconPixmap(g->player->icon);
            g->msgBox.exec();
            g->showMaximized();
            this->hide();
            timer->stop();
        }
}

