#include "matrixwindow.h"
#include "ui_matrixwindow.h"

MatrixWindow::MatrixWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MatrixWindow)
{
    ui->setupUi(this);
    this->matrix = this->ui->matrix;
}

MatrixWindow::~MatrixWindow()
{
    delete ui;
}
