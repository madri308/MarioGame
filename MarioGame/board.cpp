#include "board.h"
#include "iostream"
#include "windows.h"
#include <QMainWindow>
Board::Board()
{
    srand(time(NULL));
    int games = 0;
    int special = 0;
    for(int row = 0 ; row < 26 ; row++){
        int forType = (rand() % 10)+1;
        Node *newNode = new Node(row);
        this->totalNodes[row] = newNode;
        for(int column = 0 ; column < 26 ; column++){
            if(row != column){
                int value = (rand() % 10)+1;
                this->adjMatrix[row][column] = value;
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
    }
}

void Board::setNodesData()
{
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
}
