#include "player.h"

Player::Player(QString name, QPixmap icon, int numbRand)
{
    this->name = name;
    this->icon = icon;
    this->numbRand = numbRand;
}

void Player::update(Node *whereIs, int visited)
{
    this->whereIs = whereIs;
    this->nodesVisited[visited] = true;
}
