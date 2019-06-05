#include "choosewindow.h"
#include "ui_choosewindow.h"
#include "iostream"
#include "gamewindow.h"
#include "windows.h"

ChooseWindow::ChooseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseWindow)
{
    ui->setupUi(this);

    images[0] = ui->label;
    images[1] = ui->label_2;
    images[2] = ui->label_3;
    images[3] = ui->label_4;
    images[4] = ui->label_5;
    images[5] = ui->label_6;

    this->textList[0] = ui->textEdit;
    this->textList[1] = ui->textEdit_2;
    this->textList[2] = ui->textEdit_3;
    this->textList[3] = ui->textEdit_4;
    this->textList[4] = ui->textEdit_5;
    this->textList[5] = ui->textEdit_6;
    for(QTextEdit *text:textList){
        text->hide();
    }
    srand(time(NULL));
    connect(ui->order, SIGNAL(released()), this, SLOT(getPlayers()));
    connect(ui->play, SIGNAL(released()), this, SLOT(done()));

    ui->play->hide();
}

ChooseWindow::~ChooseWindow()
{
    delete ui;
}
void ChooseWindow::sort(Player *list[]){
    ui->players->clear();
    srand(time(NULL));
    int numRand = rand() % 1000 + 1;
    this->ui->rand->setNum(numRand);

    for(int player = 0 ; player < playerCount ; player++){
        int diference1 = numRand - list[player]->numbRand;
        if(numRand < list[player]->numbRand){
            diference1 = abs(diference1);
        }
        for(int playerToCompare = player+1 ; playerToCompare < playerCount ; playerToCompare++){
            int diference2 = numRand - list[playerToCompare]->numbRand;
            if(numRand < list[playerToCompare]->numbRand){
                diference2 = abs(diference2);
            }
            if(diference2 < diference1){
                Player *temp = list[player];
                list[player] = list[playerToCompare];
                list[playerToCompare] = temp;
            }else if(diference2 == diference1){
                Player *temp = list[player+1];
                list[player+1] = list[playerToCompare];
                list[playerToCompare] = temp;
            }
        }
    }
    for(int player = 0 ; player < playerCount ; player++){
        this->ui->players->setText(this->ui->players->text()+QString::number(player+1)+". "+list[player]->name+".\n");
    }
}
void ChooseWindow::getPlayers()
{
    for(int p = 0 ; p < playerCount ; p++){
        QTextEdit *text = textList[p];
        QLabel *label = images[p];
        if(!text->isHidden()){
            Player *player = new Player(label->objectName(),*label->pixmap(),text->toPlainText().toInt());
            this->playerList[p] = player;
        }
    }
    sort(this->playerList);
    ui->play->show();
}

void ChooseWindow::done()
{
    GameWindow *g = new GameWindow();
    g->quantPlayers = this->playerCount;
    for(int e = 0 ; e < playerCount ; e++){
        g->playerList[e] = this->playerList[e];

        QPixmap pixmap = g->playerList[e]->icon;
        QString name = g->playerList[e]->name;

        g->images[e]->setEnabled(true);
        g->images[e]->setIcon(pixmap);
        g->images[e]->setObjectName(name);
        g->images[e]->setIconSize(pixmap.rect().size());

        g->names[e]->setText(name);
    }
    g->showMaximized();
    this->close();
}
