#include "choosecardwindow.h"
#include "ui_choosecardwindow.h"
#include <QLabel>
#include <QtDebug>
#include<time.h>
#include <QMessageBox>
ChooseCardWindow::ChooseCardWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseCardWindow)
{
    ui->setupUi(this);
    connect(ui->playButton,SIGNAL(clicked()),this,SLOT(onClicked()));
}

int ChooseCardWindow::getPos(QString array[], QString text)
{
    int i;
    for(i = 0; i < 4; i++)
    {
        if(array[i] == text)
        {
            break;
        }
    }
    return i;
}

void ChooseCardWindow::checkCards(Card *array[])
{
    bool allGood = true;
    for(int i = 0; i < 6; i++)
    {
        for(int c = i+1; c < 6; c++)
        {
            if(array[i]->name == array[c]->name && array[i]->type == array[c]->type)
            {
                srand(time(NULL));
                allGood = false;
                int randType = rand()%4;
                int randName = rand()%14;
                array[c] = new Card(names[randName],types[randType]);
            }
        }
    }

    if (!allGood)
    {
        checkCards(array);
    }
}

void ChooseCardWindow::chooseCards()
{
    srand(time(NULL));
    Card *cards[cantPlayers];
    for (int i = 0; i < cantPlayers; i++)
    {
        int randomName = rand()%13;
        int randomType = rand()%4;
        cards[i] = new Card(names[randomName], types[randomType]);
        qDebug() << cards[i]->intValue << "-" << cards[i]->name <<"-"<< cards[i]->type << randomName;
    }

    checkCards(cards);

    sortCards(cards);
    qDebug() << "----------------------------------";
    for(int k = 0; k < 6; k++)
    {
        qDebug() << cards[k]->intValue << "-" << cards[k]->name <<"-"<< cards[k]->type;
    }
    int randCard = rand()%6;
    Card *playerCard = cards[randCard];
    qDebug() << playerCard->name;
    if(playerCard->name == cards[0]->name && playerCard->type == cards[0]->type)
    {
        g->msgBox.setWindowTitle("Ganaste");
        g->msgBox.setText("Tu carta fue un "+playerCard->name+" de "+playerCard->type+" y la carta mayor fue un "+cards[0]->name+" de "+cards[0]->type);
        g->msgBox.setIconPixmap(g->player->icon);
        g->msgBox.exec();
        g->player->won = true;
        g->move(g->player,g->newWhereIs);
        g->pos--;
        g->showMaximized();
        this->hide();
    }
    else{
        g->msgBox.setWindowTitle("Perdiste");
        g->msgBox.setText("Tu carta fue un "+playerCard->name+" de "+playerCard->type+" y la carta mayor fue un "+cards[0]->name+" de "+cards[0]->type);
        g->msgBox.setIconPixmap(g->player->icon);
        g->msgBox.exec();
        g->player->won = false;
        g->move(g->player,g->newWhereIs);
        g->showMaximized();
        this->hide();
    }
}

void ChooseCardWindow::sortCards(Card *cards[])
{
    bool allGood = true;
    for(int c= 0; c < 6; c++)
    {
        for(int s = c+1; s < 6; s++)
        {
            if(cards[s]->intValue > cards[c]->intValue)
            {
                Card *tmp = cards[c];
                cards[c] = cards[s];
                cards[s] = tmp;
                allGood = false;
            }
            else if(cards[s]->intValue == cards[c]->intValue)
            {
                int firstElementPos = getPos(this->types, cards[c]->type);
                int secondElementPos = getPos(this->types, cards[s]->type);

                if(secondElementPos > firstElementPos)
                {
                    Card *tmp = cards[c];
                    cards[c] = cards[s];
                    cards[s] = tmp;
                    allGood = false;
                }
            }
        }
    }

    if(!allGood)
    {
        sortCards(cards);
    }
}

ChooseCardWindow::~ChooseCardWindow()
{
    delete ui;
}

void ChooseCardWindow::onClicked()
{
    chooseCards();
}
