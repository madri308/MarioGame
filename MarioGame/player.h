#ifndef PLAYER_H
#define PLAYER_H

#include "QString"
#include "QIcon"
#include "node.h"

class Player
{
public:
    Player(QString name, QPixmap icon, int numbRand);
    Player();
    QString name;
    QPixmap icon;
    int numbRand;
    bool nodesVisited[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Node *whereIs;
    int box;
    Node *Start;

    int row = 0;
    int column = 0;
    void update(Node *whereIs, int visited);
    int blocked = 0;
    bool won = true;
};

#endif // PLAYER_H
