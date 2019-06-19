#include "catwindow.h"
#include "ui_catwindow.h"

CatWindow::CatWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CatWindow)
{
    ui->setupUi(this);
    this->buttons[0][0] = ui->P0;
    this->buttons[0][1] = ui->P1;
    this->buttons[0][2] = ui->P2;
    this->buttons[1][0] = ui->P3;
    this->buttons[1][1] = ui->P4;
    this->buttons[1][2] = ui->P5;
    this->buttons[2][0] = ui->P6;
    this->buttons[2][1] = ui->P7;
    this->buttons[2][2] = ui->P8;
    this->P1 = ui->label;
    this->P2 = ui->label2;
    this->desc = ui->label3;
    for(int row = 0 ; row<3 ; row++){
        for(int column = 0 ; column<3 ; column++){
            QPushButton *button = this->buttons[row][column];
            connect(button, &QPushButton::released, [=]{
                changeState(row,column);
            });
        }
    }
}

CatWindow::~CatWindow()
{
    delete ui;
}

bool CatWindow::verifyWiner(){
    if((buttons[0][0]->text() == state && buttons[0][1]->text() == state && buttons[0][2]->text() == state) ||
       (buttons[1][0]->text() == state && buttons[1][1]->text() == state && buttons[1][2]->text() == state)||
       (buttons[2][0]->text() == state && buttons[2][1]->text() == state && buttons[2][2]->text() == state)||
       (buttons[0][0]->text() == state && buttons[1][0]->text() == state && buttons[2][0]->text() == state)||
       (buttons[0][1]->text() == state && buttons[1][1]->text() == state && buttons[2][1]->text() == state)||
       (buttons[0][2]->text() == state && buttons[1][2]->text() == state && buttons[2][2]->text() == state)||
       (buttons[0][0]->text() == state && buttons[1][1]->text() == state && buttons[2][2]->text() == state)||
       (buttons[0][2]->text() == state && buttons[1][1]->text() == state && buttons[2][0]->text() == state)){
        return true;
    }
    return false;
}
bool CatWindow::isFull(){
    for(int row = 0 ; row < 3 ; row++){
        for(int column = 0 ; column < 3 ; column++){
            if(this->buttons[row][column]->text() == "-"){
                return false;
            }
        }
    }return true;
}
void CatWindow::changeState(int row,int column)
{
    if(this->buttons[row][column]->text() == "-"){
        this->buttons[row][column]->setText(this->state);
        if(verifyWiner() && state == "X"){
            g->msgBox.setWindowTitle("Gato");
            g->msgBox.setText("Ganaste");
            g->msgBox.setIconPixmap(*ui->label->pixmap());
            g->msgBox.exec();
            g->move(g->player,g->newWhereIs);
            g->pos--;
            g->showMaximized();
            this->hide();
        }else {
            if(isFull() || (verifyWiner() && state == "O")){
                g->msgBox.setWindowTitle("Gato");
                g->msgBox.setText("Perdiste");
                g->msgBox.setIconPixmap(*ui->label->pixmap());
                g->msgBox.exec();
                g->showMaximized();
                this->hide();
            }else{
                if(this->state == "O"){
                    this->state = "X";
                }else{
                    this->state = "O";
                }
            }

        }

    }
}
