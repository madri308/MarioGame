#include "startwindow.h"
#include <QApplication>
#include "bomberwindow.h"
#include "wordsearchwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow w;
    w.show();

    return a.exec();
}
