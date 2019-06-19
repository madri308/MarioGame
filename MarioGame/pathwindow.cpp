#include "pathwindow.h"
#include "ui_pathwindow.h"
#include <time.h>
#include <QDebug>
PathWindow::PathWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PathWindow)
{
    ui->setupUi(this);
    generateMatrix();
}

void PathWindow::generateMatrix()
{
    srand(time(NULL));
    for(int row = 0; row < 8;row++)
    {
        for(int column = 0; column < 3; column++)
        {
            matrix[row][column] = new QPushButton("",ui->pathFrame);
            QPixmap icon(":/new/coins/block.jpg");
            QIcon block(icon);
            matrix[row][column]->setIcon(icon);
            matrix[row][column]->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
            matrix[row][column]->setIconSize(QSize(100,170));
            QObject::connect(matrix[row][column],SIGNAL(clicked()),this,SLOT(onButtonClicked()));
            ui->pathLayout->addWidget(matrix[row][column],row,column);
            matrix[row][column]->show();
        }
    }


}

PathWindow::~PathWindow()
{
    delete ui;
}

void PathWindow::onButtonClicked()
{
    if( ((QPushButton*)sender())->accessibleName() == "Good")
    {
        qDebug()  << "Hola";
    }
}
