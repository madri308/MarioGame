#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "iostream"
#include "QSignalMapper"
#include "matrixwindow.h"
#include "QStandardItemModel"
#include "QListView"

GameWindow::GameWindow(QWidget *parent,Player *players[], int pc) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    this->quantPlayers = pc;
    for(int p = 0 ; p < this->quantPlayers ; p++){
        this->playerList[p] = players[p];
    }
    //PONE EL BACKGROUND
    QPixmap bkgnd(":/BackGround1.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    //GUARDA LOS LABELS PARA LAS IMAGENES
    images[0] = ui->pushButton;
    images[1] = ui->pushButton_2;
    images[2] = ui->pushButton_3;
    images[3] = ui->pushButton_4;
    images[4] = ui->pushButton_5;
    images[5] = ui->pushButton_6;
    names[0] = ui->label;
    names[1] = ui->label_2;
    names[2] = ui->label_3;
    names[3] = ui->label_4;
    names[4] = ui->label_5;
    names[5] = ui->label_6;
    //CONEXIONES CON BOTONES
    connect(ui->matriz, SIGNAL(released()), this, SLOT(showMatrix()));
    int b = 0;
    for(QPushButton *button:images){
        connect(button, &QPushButton::released, [=]{
            showPlayerInfo(b);
        });
        b++;
    }
    //CREA EL TABLERO Y LO SETEA COMO ATRIBUTO
    this->board = new Board();
    //MUESTRA LOS CAMINOS ENTRE NODOS
    showWays();
    //GUARDA LOS LABELS DE CADA CASILLA
    this->boxes[0] = ui->C1_1;
    this->boxes[1] = ui->C1_2;
    this->boxes[2] = ui->C1_3;
    this->boxes[3] = ui->C1_4;
    this->boxes[4] = ui->C1_5;
    this->boxes[5] = ui->C1_6;
    this->boxes[6] = ui->C1_7;
    this->boxes[7] = ui->C1_8;
    this->boxes[8] = ui->C1_9;
    this->boxes[9] = ui->C1_10;
    this->boxes[10] = ui->C1_11;
    this->boxes[11] = ui->C1_12;
    this->boxes[12] = ui->C1_13;
    this->boxes[13] = ui->C1_14;
    this->boxes[14] = ui->C1_15;
    this->boxes[15] = ui->C1_16;
    this->boxes[16] = ui->C1_17;
    this->boxes[17] = ui->C1_18;
    this->boxes[18] = ui->C1_19;
    this->boxes[19] = ui->C1_20;
    this->boxes[20] = ui->C1_21;
    this->boxes[21] = ui->C1_22;
    this->boxes[22] = ui->C1_23;
    this->boxes[23] = ui->C1_24;
    this->boxes[24] = ui->C1_25;
    this->boxes[25] = ui->C1_26;
    start();
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::start()
{
    srand(time(NULL));
    for(int p = 0 ; p < this->quantPlayers ; p++){
        Player *player = this->playerList[p];
        int numRand = rand() % 26;
        QLabel *label = this->boxes[numRand];
        label->setText(label->text()+player->name+"\n");
        player->nodesVisited[numRand] = true;
        player->whereIs = this->board->totalNodes[numRand];
    }

}

void GameWindow::showPlayerInfo(int b)
{
    msgBox.setText("");
    Player *player = playerList[b];
    msgBox.setWindowTitle(player->name);
    msgBox.setWindowIcon(player->icon);
    msgBox.setText(msgBox.text()+"Casilla Actual: "+QString::number(player->whereIs->id+1)+"\n");
    msgBox.setText(msgBox.text()+"Casillas visitadas: ");
    for(int b = 0 ; b < 26 ; b++){
        bool visited = player->nodesVisited[b];
        if(visited){
            msgBox.setText(msgBox.text()+QString::number(this->board->totalNodes[b]->id+1)+"-");
        }
    }
    msgBox.setText(msgBox.text()+"\n");
    msgBox.exec();
}

void GameWindow::showMatrix()
{
    const int numRows = 26;
    const int numColumns = 26;

    QStandardItemModel* model = new QStandardItemModel(numRows, numColumns);
    for (int row = 0; row < numRows; ++row){
        for (int column = 0; column < numColumns; ++column){
            QString numb = QString::number(this->board->adjMatrix[row][column]);
            QStandardItem* item = new QStandardItem(numb);
            item->setBackground(QColor(Qt::green));
            if(this->board->adjMatrix[row][column] == 0){
                item->setBackground(QColor(Qt::red));
            }
            model->setItem(row, column, item);
        }
    }
    MatrixWindow *m = new MatrixWindow();
    m->matrix->setModel(model);
    m->show();
}

void GameWindow::showWays()
{
    QListWidget *wayss = this->ui->wayss;
    for(int n = 0 ; n<26 ; n++){
        Node *node = board->totalNodes[n];
        wayss->addItem("Desde la casilla "+QString::number(node->id+1));
        wayss->addItem("hasta la casilla:");
        for(int w = 0 ; w<node->ways ; w++){
            wayss->addItem("          "+QString::number(node->nodes[w]->id+1)+" necesitas sacar "+QString::number(node->values[w]));
        }
    }
}

