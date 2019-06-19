#include "card.h"

Card::Card()
{

}

Card::Card(QString name, QString type)
{
    if(name == "A")
    {
        intValue = 14;
        this->name = name;
        this->type = type;
    }
    else if(name == "K")
    {
        intValue = 13;
        this->name = name;
        this->type = type;
    }
    else if(name == "Q")
    {
        intValue = 12;
        this->name = name;
        this->type = type;
    }
    else if(name == "J")
    {
        intValue = 11;
        this->name = name;
        this->type = type;
    }
    else {
        intValue = name.toInt();
        this->name = name;
        this->type = type;
    }
}
