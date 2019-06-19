#ifndef CARD_H
#define CARD_H
#include <QString>

class Card
{
public:
    QString name;
    int intValue;
    QString type;
    Card();
    Card(QString,QString);
};

#endif // CARD_H
