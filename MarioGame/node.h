#ifndef NODE_H
#define NODE_H
#include "iostream"

struct Node
{
public:
    Node(int id);

    std::string type;
    Node *nodes[26];
    int values[26];
    int ways = 0;
    int id = 0;
    bool visited = false;
    int column = 0;
    int row = 0;
};

#endif // NODE_H
