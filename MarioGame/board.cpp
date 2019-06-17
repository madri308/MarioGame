#include "board.h"
#include "iostream"
#include "windows.h"
#include <QMainWindow>
Board::Board()
{
    srand(time(NULL));
    for(int row = 0 ; row < 26 ; row++){
        Node *newNode = new Node(row);
        this->totalNodes[row] = newNode;
        for(int column = 0 ; column < 26 ; column++){
            if(row != column && this->adjMatrix[row][column] == 0){
                int value = (rand() % 10)+1;
                this->adjMatrix[row][column] = value;
                this->adjMatrix[column][row] = value;
            }
        }
    }
    this->generate();
    this->setNodesData();
}
void Board::generate(){
    srand(time(NULL));
    //NUMERO DE VERTICES
    int vert = 423+(rand() % 118);
    int noVert = 676 - vert;
    for(int Vert = 0 ; Vert<noVert ; Vert++){
        int row = rand() % 26;
        int column = rand() % 26;
        while(this->adjMatrix[row][column] == 0){
            row = rand() % 26;
            column = rand() % 26;
        }
        this->adjMatrix[row][column] = 0;
        this->adjMatrix[column][row] = 0;
        Vert++;
    }
}

void Board::setNodesData()
{
    srand(time(NULL));
    for(int node = 0 ; node < 26 ; node++){
        Node *actualNode = this->totalNodes[node];
        for(int way = 0 ; way < 26 ; way++){
            if(this->adjMatrix[node][way] != 0){
                Node *oneNode = this->totalNodes[way];
                actualNode->nodes[actualNode->ways] = oneNode;
                actualNode->values[actualNode->ways] = this->adjMatrix[node][way];
                actualNode->ways++;
            }
        }
    }
    std::string types[17][3] = {{"Sopa De Letras","2","Juego"},{"Gato","2","Juego"},{"Memorizar Direccion","2","Juego"},{"Memorizar Items","2","Juego"},{"Atrapar El Gato","2","Juego"},{"Bomber Mario","2","Juego"},{"Quien Es?","2","Juego"},{"Rejunta Monedas","2","Juego"},{"Cartas","2","Juego"},{"Carcel","1","Castigo"},{"Tubos","1","Comodin"},{"Tubos","2","Comodin"},{"Tubos","3","Comodin"},{"Estrella","1","Comodin"},{"Flor De Fuego","1","Comodin"},{"Flor De Hielo","1","Comodin"},{"Cola","1","Comodin"}};
    for(int node = 0 ; node < 26 ; node++){
        Node *actualNode = this->totalNodes[node];

        int type = (rand() % 17);
        while(stoi(types[type][1]) == 0){
            type = (rand() % 17);
        }
        actualNode->type2 = types[type][2];
        actualNode->type = types[type][0];
        types[type][1] = std::to_string(stoi(types[type][1])-1);
        if(actualNode->type == "Tubos"){
            if(types[type][1] == "0"){
                actualNode->type = actualNode->type + "1";
                this->tube1 = actualNode;
                std::cout<<"T1 ";
                std::cout<<tube1->id<<std::endl;
            }else if(types[type][1] == "1"){
                actualNode->type = actualNode->type + "2";
                this->tube2 = actualNode;
                types[type][1] = "0";
                std::cout<<"T2 ";
                std::cout<<tube2->id<<std::endl;
            }else{
                actualNode->type = actualNode->type + "3";
                this->tube3 = actualNode;
                types[type][1] = "0";
                std::cout<<"T3 ";
                std::cout<<tube3->id<<std::endl;
            }
        }
    }
}
