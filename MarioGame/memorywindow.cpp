
#include "memorywindow.h"
#include "ui_memorywindow.h"
#include <QPixmap>
#include <QIcon>
#include <QDebug>
#include <QDesktopWidget>
#include <time.h>

MemoryWindow::MemoryWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MemoryWindow)
{
    ui->setupUi(this);
    resize(QDesktopWidget().availableGeometry(this).size() * 0.8);
    generateMatrix();
}

void MemoryWindow::generateMatrix()
{
    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 6; column++)
        {
             matrix[row][column] = new QPushButton(" ", ui->memoryFrame);
             QPixmap newPix(":/img/Card.png");
             QIcon newIcon(newPix);
             matrix[row][column]->setIcon(newIcon);
             matrix[row][column]->setIconSize(QSize(120,190));
        }
    }
}
