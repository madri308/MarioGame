#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "iostream"
#include "QSignalMapper"
#include "matrixwindow.h"
#include "QStandardItemModel"
#include "QListView"
#include "QLineEdit"
#include "QGroupBox"
#include "catwindow.h"
#include "coinswindow.h"
#include "guesswhowindow.h"
#include "bomberwindow.h"
#include "QString"
#include "QtDebug"
#include "pathwindow.h"
#include "wordsearchwindow.h"
#include "choosecardwindow.h"
GameWindow::GameWindow(QWidget *parent,Player *players[], int pc) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    this->quantPlayers = pc;
    for(int p = 0 ; p < this->quantPlayers ; p++){
        this->playerList[p] = players[p];
    }
    ui->select->hide();
    ui->mover->hide();
    ui->cola->hide();
    ui->getCola->hide();
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
    connect(ui->throwB, SIGNAL(released()), this, SLOT(throwDices()));
    connect(ui->mover, SIGNAL(released()), this, SLOT(cola()));
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
    //GUARDA LOS LABELS PARA LOS NOMBRES DE CADA CASILLA
    this->CNames[0] = ui->name1;
    this->CNames[1] = ui->name2;
    this->CNames[2] = ui->name3;
    this->CNames[3] = ui->name4;
    this->CNames[4] = ui->name5;
    this->CNames[5] = ui->name6;
    this->CNames[6] = ui->name7;
    this->CNames[7] = ui->name8;
    this->CNames[8] = ui->name9;
    this->CNames[9] = ui->name10;
    this->CNames[10] = ui->name11;
    this->CNames[11] = ui->name12;
    this->CNames[12] = ui->name13;
    this->CNames[13] = ui->name14;
    this->CNames[14] = ui->name15;
    this->CNames[15] = ui->name16;
    this->CNames[16] = ui->name17;
    this->CNames[17] = ui->name18;
    this->CNames[18] = ui->name19;
    this->CNames[19] = ui->name20;
    this->CNames[20] = ui->name21;
    this->CNames[21] = ui->name22;
    this->CNames[22] = ui->name23;
    this->CNames[23] = ui->name24;
    this->CNames[24] = ui->name25;
    this->CNames[25] = ui->name26;
    for(int type = 0 ; type<26; type++){
        this->CNames[type]->setWordWrap(true);
        this->CNames[type]->setStyleSheet("font-weight: bold; color: white");
        QString part;
        if(this->board->totalNodes[type]->type2 == "Castigo"){
            part = QString("<span style=color:red;>%1</span>").arg(QString::fromStdString(this->board->totalNodes[type]->type2)+": ");
        }else if(this->board->totalNodes[type]->type2 == "Comodin"){
            part = QString("<span style=color:green;>%1</span>").arg(QString::fromStdString(this->board->totalNodes[type]->type2)+": ");
        }else if(this->board->totalNodes[type]->type2 == "Juego"){
            part = QString("<span style=color:yellow;>%1</span>").arg(QString::fromStdString(this->board->totalNodes[type]->type2)+": ");
        }
        this->CNames[type]->setText(part+QString::fromStdString(this->board->totalNodes[type]->type));
    }
    //GUARDA LOS ESPACIOS PARA LAS IMAGENES DE LOS JUGADORES
    this->CImages[0] = ui->C1;
    this->CImages[1] = ui->C2;
    this->CImages[2] = ui->C3;
    this->CImages[3] = ui->C4;
    this->CImages[4] = ui->C5;
    this->CImages[5] = ui->C6;
    this->CImages[6] = ui->C7;
    this->CImages[7] = ui->C8;
    this->CImages[8] = ui->C9;
    this->CImages[9] = ui->C10;
    this->CImages[10] = ui->C11;
    this->CImages[11] = ui->C12;
    this->CImages[12] = ui->C13;
    this->CImages[13] = ui->C14;
    this->CImages[14] = ui->C15;
    this->CImages[15] = ui->C16;
    this->CImages[16] = ui->C17;
    this->CImages[17] = ui->C18;
    this->CImages[18] = ui->C19;
    this->CImages[19] = ui->C20;
    this->CImages[20] = ui->C21;
    this->CImages[21] = ui->C22;
    this->CImages[22] = ui->C23;
    this->CImages[23] = ui->C24;
    this->CImages[24] = ui->C25;
    this->CImages[25] = ui->C26;
    start();

}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::start()
{
    srand(time(NULL));
    QLabel *playerName = this->names[this->pos];
    playerName->setStyleSheet("color:red");
    //COLOCA A LOS JUGADORES EN CASILLAS ALEATORIAS.
    for(int p = 0 ; p < this->quantPlayers ; p++){
        Player *player = this->playerList[p]; //AGARRA EL JUGADOR DE LA LISTA
        int numRand = rand() % 26;
        QGridLayout *gridGroupBox = this->CImages[numRand];
        player->box = numRand;
        QLabel *label =  new QLabel();
        label->setPixmap(player->icon);
        label->setScaledContents(true);
        player->row = this->board->totalNodes[numRand]->row;
        player->column = this->board->totalNodes[numRand]->column;
        gridGroupBox->addWidget(label,this->board->totalNodes[numRand]->row,this->board->totalNodes[numRand]->column);
        this->board->totalNodes[numRand]->column++;
        if(this->board->totalNodes[numRand]->column == 3){
            this->board->totalNodes[numRand]->column = 0;
            this->board->totalNodes[numRand]->row++;
        }
        player->nodesVisited[numRand] = true;
        player->whereIs = player->Start = this->board->totalNodes[numRand];
    }
}

void GameWindow::move(Player *player, Node *newWhereIs)
{

    QWidget *image = this->CImages[player->whereIs->id]->itemAtPosition(player->row,player->column)->widget();
    player->whereIs->column--;
    if(player->whereIs->column == -1){
        player->whereIs->column = 2;
        player->whereIs->row--;
    }
    player->whereIs = newWhereIs;
    if(player->won){
        player->nodesVisited[player->whereIs->id] = true;
    }
    this->CImages[player->whereIs->id]->addWidget(image,player->whereIs->row,player->whereIs->column);
    player->row = player->whereIs->row;
    player->column = player->whereIs->column;
    player->whereIs->column++;
    if(player->whereIs->column == 3){
        player->whereIs->column = 0;
        player->whereIs->row++;
    }
}

void GameWindow::showMinWin(QString text, QPixmap icon, QString title)
{
    msgBox.setWindowTitle(title);
    msgBox.setIconPixmap(icon);
    msgBox.setText(text);
    msgBox.exec();
}

void GameWindow::throwDices()
{
    player = this->playerList[this->pos];
    //SI HA PERDIDO ALGUN TURNO.
    if(player->blocked != 0){
        player->blocked = player->blocked-1;
        showMinWin("Aun no puedes jugar, ahora estas bloqueado por "+QString::number(player->blocked)+" turnos.",player->icon,"Estas Bloqueado");
    }else{
        int dice1 = rand() % 8;  // in the range of 0 - 7
        int dice2 = rand() % 8;  // in the range of 0 - 7int totalDice = dice1+dice2;
        int totalDice = dice1+dice2;
        if(!player->won){
            showMinWin("Aun no has ganado el juego de tu casilla por lo que no puedes tirar los dados hasta que lo ganes ",player->icon,"Estancado");
        }else {
            this->ui->diceResult->wordWrap();
            this->ui->diceResult->setText(QString::number(dice1) + " + " + QString::number(dice2) + " = " + QString::number(totalDice));
        }
        if((dice1 == 7 || dice2 == 7) && player->won){
            if(dice2 == 7 && dice1 == 7){
                showMinWin("Sacaste 7 en un dado por lo que perderas dos turnos",player->icon,"Estas Bloqueado");
                player->blocked = player->blocked+3;
            }else{
                showMinWin("Sacaste 7 en un dado por lo que perderas un turno",player->icon,"Estas Bloqueado");
                player->blocked = player->blocked+1;
            }
        }else{
            if(!player->won){
                totalDice = 0;
            }
            bool canMove = false;
            for(int n = 0 ; n<player->whereIs->ways ; n++){
                if(player->nodesVisited[player->whereIs->nodes[n]->id] == false){
                    canMove = true;
                    break;
                }
            }
            if(canMove){
                for(int n = 0 ; n<player->whereIs->ways ; n++){
                    if(player->whereIs->values[n] == totalDice || !player->won){
                        newWhereIs = this->board->totalNodes[player->whereIs->nodes[n]->id];
                        if(!player->won){
                            newWhereIs = player->whereIs;
                        }
                        if(player->nodesVisited[newWhereIs->id] == true){
                            canMove = false;
                            this->showMinWin("Lo sentimos, la casilla "+QString::number(newWhereIs->id+1) +" ya la visitaste, seguiremos viendo si puedes moverte a otra!",player->icon,"No puedes");
                        }else if( totalDice > 10){
                            this->showMinWin("Lo sentimos, sacaste un numero mayor a 10!",player->icon,"No puedes");
                            break;
                        }else{
                            if(newWhereIs->type2 == "Juego"){ //JUEGO
                                if(newWhereIs->type == "Sopa De Letras"){
                                    //Juega sopa de letras
                                    WordSearchWindow *w = new WordSearchWindow();
                                    w->g = this;
                                    w->show();
                                    this->hide();
                                }else if(newWhereIs->type == "Gato"){
                                    //Juega Gato
                                    int r = rand() % this->quantPlayers;
                                    Player *randPlayer = this->playerList[r];
                                    while(randPlayer->name == player->name){
                                        r = rand() % this->quantPlayers;
                                        randPlayer = this->playerList[r];
                                    }
                                    CatWindow *c = new CatWindow();
                                    c->P1->setPixmap(player->icon);
                                    c->P2->setPixmap(randPlayer->icon);
                                    c->g = this;
                                    c->desc->setText(player->name+"(X) cayo en gato por lo que tendra que jugar contra "+randPlayer->name+"(O)");
                                    c->show();
                                    this->hide();
                                }else if (newWhereIs->type == "Memorizar Direccion"){
                                    //Juega Memorizar direccion
                                    PathWindow *c = new PathWindow();
                                    c->g = this;
                                    c->show();
                                    this->hide();
                                }else if(newWhereIs->type == "Memorizar Items"){
                                    //Juega Memorizar Items
                                }else if (newWhereIs->type == "Atrapar El Gato"){
                                    //Juega Atrapar el gato
                                }else if (newWhereIs->type == "Bomber Mario"){
                                    BomberWindow *c = new BomberWindow();
                                    c->g = this;
                                    c->show();
                                    this->hide();
                                }else if(newWhereIs->type == "Quien Es?"){
                                    GuessWhoWindow *c = new GuessWhoWindow();
                                    c->g = this;
                                    c->show();
                                    this->hide();
                                }else if(newWhereIs->type == "Rejunta Monedas"){
                                    CoinsWindow *c = new CoinsWindow();
                                    c->g = this;
                                    c->show();
                                    this->hide();
                                }else if(newWhereIs->type == "Cartas"){
                                    //Juega cartas
                                    ChooseCardWindow *c = new ChooseCardWindow();
                                    c->g = this;
                                    c->show();
                                    this->hide();
                                }
                            }else {//COMODINES O CASTIGOS
                                move(player,newWhereIs);
                                //CASO TUBOS
                                if(player->whereIs->type == "Tubos1"){
                                    showMinWin(player->name+" ha caido en el "+QString::fromStdString(player->whereIs->type)+" por lo que se ira a la casilla "+QString::number(this->board->tube2->id+1),player->icon,"Tubos");
                                    move(player,this->board->tube2);
                                }else if (player->whereIs->type == "Tubos2") {
                                    showMinWin(player->name+" ha caido en el "+QString::fromStdString(player->whereIs->type)+" por lo que se ira a la casilla "+QString::number(this->board->tube3->id+1),player->icon,"Tubos");
                                    move(player,this->board->tube3);
                                }else if (player->whereIs->type == "Tubos3") {
                                    showMinWin(player->name+" ha caido en el "+QString::fromStdString(player->whereIs->type)+" por lo que se ira a la casilla "+QString::number(this->board->tube1->id+1),player->icon,"Tubos");
                                    move(player,this->board->tube1);
                                }
                                //CASO CARCEL
                                else if (player->whereIs->type == "Carcel") {
                                    showMinWin(player->name+" ha caido en la carcel por lo que perdera 2 turnos",player->icon,"Carcel");
                                    player->blocked = player->blocked+2;
                                }
                                //CASO ESTRELLA
                                else if (player->whereIs->type == "Estrella") {
                                    showMinWin(player->name+" ha caido en Estrella por lo que jugara de nuevo",player->icon,"Estrella");
                                    this->pos--;
                                }
                                //CASO FLOR DE FUEGO.
                                else if (player->whereIs->type == "Flor De Fuego") {
                                    ui->select->show();
                                    this->select = 1;
                                    showMinWin(player->name+" ha caido en Flor De Fuego, puedes escoger a un jugador para que empiece desde cero.",player->icon,"Flor de fuego");
                                    this->ui->throwB->hide();
                                }
                                //CASO FLOR DE HIELO.
                                else if (player->whereIs->type == "Flor De Hielo") {
                                    ui->select->show();
                                    this->select = 2;
                                    showMinWin(player->name+" ha caido en Flor De Hielo, puedes escoger a un jugador para que pierda dos turnos.",player->icon,"Flor De Hielo");
                                    this->ui->throwB->hide();
                                }
                                //CASO COLA.
                                else if (player->whereIs->type == "Cola") {
                                    ui->throwB->hide();
                                    ui->cola->show();
                                    ui->getCola->show();
                                    ui->mover->show();
                                    showMinWin(player->name+" ha caido en Cola, puedes escoger a una casilla a cual ir",player->icon,"Cola");
                                }
                            }
                            bool winner = true;
                            int type = 0;
                            for(bool check:player->nodesVisited){
                                if(check == false && this->board->totalNodes[type]->type2 != "Castigo"){
                                    winner = false;
                                    break;
                                }
                                type++;
                            }
                            if(winner == true){
                                showMinWin(player->name,player->icon,"Ganador");
                            }
                            break;
                        }
                    }
                }
            }else{
                showMinWin("No te puedes mover, debes empezar de nuevo",player->icon,"Lo sentimos");
                Player *newOne = new Player(player->name,player->icon,0);
                newOne->whereIs = newOne->Start = player->Start;
                newOne->row = player->row;
                newOne->column = player->column;
                newOne->nodesVisited[newOne->whereIs->id] = true;
                playerList[this->pos] = newOne;
                move(newOne,newOne->whereIs);

            }
        }
    }
    QLabel *playerName = this->names[this->pos];
    playerName->setStyleSheet("color:white");
    if(this->pos == this->quantPlayers-1){
        this->pos = 0;
    }else{
        this->pos++;
    }
    playerName = this->names[this->pos];
    playerName->setStyleSheet("color:red");
}

void GameWindow::showPlayerInfo(int b)
{
    Player *player = playerList[b];
    if(this->select == 0){
        QString text = "Casilla Actual: "+QString::number(player->whereIs->id+1)+"\nCasillas visitadas: ";
        for(int b = 0 ; b < 26 ; b++){
            bool visited = player->nodesVisited[b];
            if(visited){
                text = text+QString::number(this->board->totalNodes[b]->id+1)+"-";
            }
        }
        text = text+"\nTurnos Bloqueados: "+QString::number(player->blocked)+"\n";
        text = text+this->board->dijkstra(this->board->adjMatrix,player->whereIs->id,player->nodesVisited);
        this->board->floyds(this->board->adjMatrix,player->whereIs->id);
        showMinWin(text,player->icon,player->name);
    }else if(this->select == 1){
        ui->select->hide();
        this->select = 0;
        showMinWin("Empezaras desde cero.",player->icon,player->name+" empieza desde cero.");
        Player *newOne = new Player(player->name,player->icon,0);
        newOne->whereIs = player->whereIs;
        newOne->row = player->row;
        newOne->column = player->column;
        newOne->nodesVisited[newOne->whereIs->id] = true;
        playerList[b] = newOne;
        this->ui->throwB->show();
    }else{
        ui->select->hide();
        this->select = 0;
        showMinWin("Perderas dos turnos.",player->icon,player->name+" bloqueado.");
        player->blocked = player->blocked+2;
        this->ui->throwB->show();
    }

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

void GameWindow::cola()
{
    QString box = ui->getCola->toPlainText();
    if(box.toInt() < 0 || box.toInt() > 26){
        this->showMinWin("Esta casilla no existe, lo sentimos",player->icon,"Error");
    }else{
        this->move(player,this->board->totalNodes[box.toInt()-1]);
    }
    ui->getCola->hide();
    ui->cola->hide();
    ui->mover->hide();
    ui->throwB->show();
}
