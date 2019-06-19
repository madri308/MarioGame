#include "guesswhowindow.h"
#include "ui_guesswhowindow.h"
#include <QPixmap>
#include <QPalette>
#include <qdebug.h>
#include <time.h>
#include <QMessageBox>

GuessWhoWindow::GuessWhoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuessWhoWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    int randIndex = rand()%15;
    currentCharacter = characters[14];
    qDebug() << currentCharacter;
    QPixmap background(currentCharacter);
    ui->label->setPixmap(background);
    fillWithBoxes();
    setLimit();
    ui->goBack->hide();
}

void GuessWhoWindow::fillWithBoxes()
{
    for(int row = 0; row < 10; row++)
    {
        for(int column = 0; column < 10; column++)
        {
            matrix[row][column] = new QPushButton("", ui->frame);
            QPixmap newPix(":/img/block.jpg");
            QIcon newIcon(newPix);
            matrix[row][column]->setIcon(newIcon);
            matrix[row][column]->setIconSize(QSize(120,190));
            QObject::connect(matrix[row][column],SIGNAL(clicked()),this,SLOT(onButtonClicked()));
            ui->guessLayout->addWidget(matrix[row][column],row,column);
            matrix[row][column]->show();
        }
    }
}

void GuessWhoWindow::setLimit()
{
    srand(time(NULL));
    int newLimit = (rand() % 4) + 5;
    limit = newLimit;
    qDebug() << limit;
    ui->tries->setText(QString::number(limit));
    limitToText = limit;
}

GuessWhoWindow::~GuessWhoWindow()
{
    delete ui;
}

void GuessWhoWindow::onButtonClicked()
{
    counter++;
    ui->tries->setText(QString::number(limitToText));
    if(counter <= limit)
    {
        limitToText--;
        ((QPushButton*)sender())->hide();
    }
    else{
        QMessageBox error;
        error.setText("Se ha quedado sin oportunidades");
        error.setIcon(QMessageBox::Warning);
        error.exec();
    }

}

void GuessWhoWindow::on_luigi_clicked()
{
    if(currentCharacter == ":/char/luigi.png")
    {
        QPalette pal = ui->luigi->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        ui->luigi->setAutoFillBackground(true);
        ui->luigi->setPalette(pal);
        ui->luigi->update();
        QMessageBox congrats;
        congrats.setText("¡Has adivinado correctamente!");
        QPixmap check;
        congrats.setIconPixmap(check);
        congrats.setWindowTitle("Felicidades");
        congrats.exec();
        won = true;
        ui->goBack->show();
    }
    else{
        QPalette pal = ui->luigi->palette();
        pal.setColor(QPalette::Button, QColor(Qt::red));
        ui->luigi->setAutoFillBackground(true);
        ui->luigi->setPalette(pal);
        ui->luigi->update();
        QMessageBox error;
        error.setWindowTitle("Lo siento");
        error.setText("No has adivinado correctamente");
        error.setIcon(QMessageBox::Critical);
        error.exec();
        ui->goBack->show();
        ui->yoshi->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->toad->hide();
        ui->mario->hide();
        ui->birdo->hide();
        ui->mario->hide();
        ui->magikoopa->hide();
        ui->bowser->hide();
        ui->peach->hide();
        ui->Boo->hide();
        ui->KingBoo->hide();
        ui->Floruga->hide();
        ui->luigi->hide();
        ui->goomba->hide();
        ui->koopa->hide();

    }
}

void GuessWhoWindow::on_peach_clicked()
{
    if(currentCharacter == ":/char/peach.png")
    {
        QPalette pal = ui->peach->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        ui->peach->setAutoFillBackground(true);
        ui->peach->setPalette(pal);
        ui->peach->update();
        QMessageBox congrats;
        congrats.setText("¡Has adivinado correctamente!");
        QPixmap check;
        congrats.setWindowTitle("Felicidades");
        congrats.setIconPixmap(check);
        congrats.exec();
        won = true;
        ui->goBack->show();
    }
    else{
        QPalette pal = ui->peach->palette();
        pal.setColor(QPalette::Button, QColor(Qt::red));
        ui->peach->setAutoFillBackground(true);
        ui->peach->setPalette(pal);
        ui->peach->update();
        QMessageBox error;
        error.setWindowTitle("Lo siento");
        error.setText("No has adivinado correctamente");
        error.setIcon(QMessageBox::Critical);
        error.exec();
        ui->goBack->show();
        ui->yoshi->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->toad->hide();
        ui->mario->hide();
        ui->birdo->hide();
        ui->mario->hide();
        ui->bowser->hide();
        ui->Boo->hide();
        ui->magikoopa->hide();
        ui->KingBoo->hide();
        ui->Floruga->hide();
        ui->luigi->hide();
        ui->goomba->hide();
        ui->koopa->hide();
    }
}

void GuessWhoWindow::on_pushButton_3_clicked()
{
    if(currentCharacter == ":/char/redkoopa.png")
    {
        QPalette pal = ui->pushButton_3->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        ui->pushButton_3->setAutoFillBackground(true);
        ui->pushButton_3->setPalette(pal);
        ui->pushButton_3->update();
        QMessageBox congrats;
        congrats.setText("¡Has adivinado correctamente!");
        QPixmap check;
        congrats.setWindowTitle("Felicidades");
        congrats.setIconPixmap(check);
        congrats.exec();
        won = true;
        ui->goBack->show();
    }
    else{
        QPalette pal = ui->pushButton_3->palette();
        pal.setColor(QPalette::Button, QColor(Qt::red));
        ui->pushButton_3->setAutoFillBackground(true);
        ui->pushButton_3->setPalette(pal);
        ui->pushButton_3->update();
        QMessageBox error;
        error.setWindowTitle("Lo siento");
        error.setText("No has adivinado correctamente");
        error.setIcon(QMessageBox::Critical);
        error.exec();
        ui->goBack->show();
        ui->yoshi->hide();
        ui->pushButton_2->hide();
        ui->toad->hide();
        ui->mario->hide();
        ui->birdo->hide();
        ui->mario->hide();
        ui->bowser->hide();
        ui->peach->hide();
        ui->Boo->hide();
        ui->KingBoo->hide();
        ui->Floruga->hide();
        ui->luigi->hide();
        ui->magikoopa->hide();
        ui->goomba->hide();
        ui->koopa->hide();
    }
}

void GuessWhoWindow::on_pushButton_2_clicked()
{
    if(currentCharacter == ":/char/greenturtle.jpg")
    {
        QPalette pal = ui->pushButton_2->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        ui->pushButton_2->setAutoFillBackground(true);
        ui->pushButton_2->setPalette(pal);
        ui->pushButton_2->update();
        QMessageBox congrats;
        congrats.setText("¡Has adivinado correctamente!");
        QPixmap check;
        congrats.setWindowTitle("Felicidades");
        congrats.setIconPixmap(check);
        congrats.exec();
        won = true;
        ui->goBack->show();
    }
    else{
        QPalette pal = ui->pushButton_2->palette();
        pal.setColor(QPalette::Button, QColor(Qt::red));
        ui->pushButton_2->setAutoFillBackground(true);
        ui->pushButton_2->setPalette(pal);
        ui->pushButton_2->update();
        QMessageBox error;
        error.setWindowTitle("Lo siento");
        error.setText("No has adivinado correctamente");
        error.setIcon(QMessageBox::Critical);
        error.exec();
        ui->goBack->show();
        ui->yoshi->hide();
        ui->pushButton_3->hide();
        ui->toad->hide();
        ui->mario->hide();
        ui->birdo->hide();
        ui->mario->hide();
        ui->magikoopa->hide();
        ui->bowser->hide();
        ui->peach->hide();
        ui->Boo->hide();
        ui->KingBoo->hide();
        ui->Floruga->hide();
        ui->luigi->hide();
        ui->goomba->hide();
        ui->koopa->hide();
    }
}

void GuessWhoWindow::on_Boo_clicked()
{
    if(currentCharacter == ":/char/boo.png")
    {
        QPalette pal = ui->Boo->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        ui->Boo->setAutoFillBackground(true);
        ui->Boo->setPalette(pal);
        ui->Boo->update();
        QMessageBox congrats;
        congrats.setText("¡Has adivinado correctamente!");
        QPixmap check;
        congrats.setWindowTitle("Felicidades");
        congrats.setIconPixmap(check);
        congrats.exec();
        won = true;
        ui->goBack->show();
    }
    else{
        QPalette pal = ui->Boo->palette();
        pal.setColor(QPalette::Button, QColor(Qt::red));
        ui->Boo->setAutoFillBackground(true);
        ui->Boo->setPalette(pal);
        ui->Boo->update();
        QMessageBox error;
        error.setWindowTitle("Lo siento");
        error.setText("No has adivinado correctamente");
        error.setIcon(QMessageBox::Critical);
        error.exec();
        ui->goBack->show();
        ui->yoshi->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->toad->hide();
        ui->mario->hide();
        ui->birdo->hide();
        ui->mario->hide();
        ui->bowser->hide();
        ui->peach->hide();
        ui->KingBoo->hide();
        ui->magikoopa->hide();
        ui->Floruga->hide();
        ui->luigi->hide();
        ui->goomba->hide();
        ui->koopa->hide();
    }
}

void GuessWhoWindow::on_toad_clicked()
{
    if(currentCharacter == ":/char/toad.jpg")
    {
        QPalette pal = ui->toad->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        ui->toad->setAutoFillBackground(true);
        ui->toad->setPalette(pal);
        ui->toad->update();
        QMessageBox congrats;
        congrats.setText("¡Has adivinado correctamente!");
        QPixmap check;
        congrats.setIconPixmap(check);
        congrats.exec();
        won = true;
        congrats.setWindowTitle("Felicidades");
        ui->goBack->show();
    }
    else{
        QPalette pal = ui->toad->palette();
        pal.setColor(QPalette::Button, QColor(Qt::red));
        ui->toad->setAutoFillBackground(true);
        ui->toad->setPalette(pal);
        ui->toad->update();
        QMessageBox error;
        error.setWindowTitle("Lo siento");
        error.setText("No has adivinado correctamente");
        error.setIcon(QMessageBox::Critical);
        error.exec();
        ui->goBack->show();
        ui->yoshi->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->mario->hide();
        ui->birdo->hide();
        ui->mario->hide();
        ui->bowser->hide();
        ui->peach->hide();
        ui->Boo->hide();
        ui->magikoopa->hide();
        ui->KingBoo->hide();
        ui->Floruga->hide();
        ui->luigi->hide();
        ui->goomba->hide();
        ui->koopa->hide();
    }
}

void GuessWhoWindow::on_yoshi_clicked()
{
    if(currentCharacter == ":/char/yoshi.jpg")
    {
        QPalette pal = ui->yoshi->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        ui->yoshi->setAutoFillBackground(true);
        ui->yoshi->setPalette(pal);
        ui->yoshi->update();
        QMessageBox congrats;
        congrats.setText("¡Has adivinado correctamente!");
        QPixmap check;
        congrats.setIconPixmap(check);
        congrats.exec();
        won = true;
        congrats.setWindowTitle("Felicidades");
        ui->goBack->show();
    }
    else{
        QPalette pal = ui->yoshi->palette();
        pal.setColor(QPalette::Button, QColor(Qt::red));
        ui->yoshi->setAutoFillBackground(true);
        ui->yoshi->setPalette(pal);
        ui->yoshi->update();
        QMessageBox error;
        error.setWindowTitle("Lo siento");
        error.setText("No has adivinado correctamente");
        error.setIcon(QMessageBox::Critical);
        error.exec();
        ui->goBack->show();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->toad->hide();
        ui->mario->hide();
        ui->magikoopa->hide();
        ui->birdo->hide();
        ui->mario->hide();
        ui->bowser->hide();
        ui->peach->hide();
        ui->Boo->hide();
        ui->KingBoo->hide();
        ui->Floruga->hide();
        ui->luigi->hide();
        ui->goomba->hide();
        ui->koopa->hide();
    }
}

void GuessWhoWindow::on_bowser_clicked()
{
    if(currentCharacter == ":/char/bowser.png")
    {
        QPalette pal = ui->bowser->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        ui->bowser->setAutoFillBackground(true);
        ui->bowser->setPalette(pal);
        ui->bowser->update();
        QMessageBox congrats;
        congrats.setText("¡Has adivinado correctamente!");
        QPixmap check;
        congrats.setIconPixmap(check);
        congrats.exec();
        won = true;
        congrats.setWindowTitle("Felicidades");
        ui->goBack->show();
    }
    else{
        QPalette pal = ui->bowser->palette();
        pal.setColor(QPalette::Button, QColor(Qt::red));
        ui->bowser->setAutoFillBackground(true);
        ui->bowser->setPalette(pal);
        ui->bowser->update();
        QMessageBox error;
        error.setWindowTitle("Lo siento");
        error.setText("No has adivinado correctamente");
        error.setIcon(QMessageBox::Critical);
        error.exec();
        ui->goBack->show();
        ui->yoshi->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->toad->hide();
        ui->mario->hide();
        ui->birdo->hide();
        ui->mario->hide();
        ui->peach->hide();
        ui->Boo->hide();
        ui->KingBoo->hide();
        ui->Floruga->hide();
        ui->luigi->hide();
        ui->goomba->hide();
        ui->magikoopa->hide();
        ui->koopa->hide();
    }
}

void GuessWhoWindow::on_koopa_clicked()
{
    if(currentCharacter == ":/char/koopa.png")
    {
        QPalette pal = ui->koopa->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        ui->koopa->setAutoFillBackground(true);
        ui->koopa->setPalette(pal);
        ui->koopa->update();
        QMessageBox congrats;
        congrats.setText("¡Has adivinado correctamente!");
        QPixmap check;
        congrats.setIconPixmap(check);
        congrats.exec();
        won = true;
        congrats.setWindowTitle("Felicidades");
        ui->goBack->show();
    }
    else{
        QPalette pal = ui->koopa->palette();
        pal.setColor(QPalette::Button, QColor(Qt::red));
        ui->koopa->setAutoFillBackground(true);
        ui->koopa->setPalette(pal);
        ui->koopa->update();
        QMessageBox error;
        error.setWindowTitle("Lo siento");
        error.setText("No has adivinado correctamente");
        error.setIcon(QMessageBox::Critical);
        error.exec();
        ui->goBack->show();
        ui->yoshi->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->toad->hide();
        ui->mario->hide();
        ui->birdo->hide();
        ui->mario->hide();
        ui->bowser->hide();
        ui->peach->hide();
        ui->Boo->hide();
        ui->magikoopa->hide();
        ui->KingBoo->hide();
        ui->Floruga->hide();
        ui->luigi->hide();
        ui->goomba->hide();
    }
}

void GuessWhoWindow::on_birdo_clicked()
{
    if(currentCharacter == ":/char/birdo.jpg")
    {
        QPalette pal = ui->birdo->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        ui->birdo->setAutoFillBackground(true);
        ui->birdo->setPalette(pal);
        ui->birdo->update();
        QMessageBox congrats;
        congrats.setText("¡Has adivinado correctamente!");
        QPixmap check;
        congrats.setIconPixmap(check);
        congrats.exec();
        won = true;
        congrats.setWindowTitle("Felicidades");
        ui->goBack->show();
    }
    else{
        QPalette pal = ui->birdo->palette();
        pal.setColor(QPalette::Button, QColor(Qt::red));
        ui->birdo->setAutoFillBackground(true);
        ui->birdo->setPalette(pal);
        ui->birdo->update();
        QMessageBox error;
        error.setWindowTitle("Lo siento");
        error.setText("No has adivinado correctamente");
        error.setIcon(QMessageBox::Critical);
        error.exec();
        ui->goBack->show();
        ui->yoshi->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->toad->hide();
        ui->mario->hide();
        ui->mario->hide();
        ui->bowser->hide();
        ui->peach->hide();
        ui->Boo->hide();
        ui->KingBoo->hide();
        ui->Floruga->hide();
        ui->luigi->hide();
        ui->magikoopa->hide();
        ui->goomba->hide();
        ui->koopa->hide();
    }
}

void GuessWhoWindow::on_KingBoo_clicked()
{
    if(currentCharacter == ":/char/kingboo.png")
    {
        QPalette pal = ui->KingBoo->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        ui->KingBoo->setAutoFillBackground(true);
        ui->KingBoo->setPalette(pal);
        ui->KingBoo->update();
        QMessageBox congrats;
        congrats.setText("¡Has adivinado correctamente!");
        QPixmap check;
        congrats.setIconPixmap(check);
        congrats.exec();
        won = true;
        congrats.setWindowTitle("Felicidades");
        ui->goBack->show();
    }
    else{
        QPalette pal = ui->KingBoo->palette();
        pal.setColor(QPalette::Button, QColor(Qt::red));
        ui->KingBoo->setAutoFillBackground(true);
        ui->KingBoo->setPalette(pal);
        ui->KingBoo->update();
        QMessageBox error;
        error.setWindowTitle("Lo siento");
        error.setText("No has adivinado correctamente");
        error.setIcon(QMessageBox::Critical);
        error.exec();
        ui->goBack->show();
        ui->yoshi->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->toad->hide();
        ui->mario->hide();
        ui->birdo->hide();
        ui->mario->hide();
        ui->bowser->hide();
        ui->peach->hide();
        ui->Boo->hide();
        ui->Floruga->hide();
        ui->luigi->hide();
        ui->goomba->hide();
        ui->koopa->hide();
        ui->magikoopa->hide();
    }
}

void GuessWhoWindow::on_mario_clicked()
{
    if(currentCharacter == ":/char/mario.png")
    {
        QPalette pal = ui->mario->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        ui->mario->setAutoFillBackground(true);
        ui->mario->setPalette(pal);
        ui->mario->update();
        QMessageBox congrats;
        congrats.setText("¡Has adivinado correctamente!");
        QPixmap check;
        congrats.setIconPixmap(check);
        congrats.exec();
        won = true;
        congrats.setWindowTitle("Felicidades");
        ui->goBack->show();
    }
    else{
        QPalette pal = ui->mario->palette();
        pal.setColor(QPalette::Button, QColor(Qt::red));
        ui->mario->setAutoFillBackground(true);
        ui->mario->setPalette(pal);
        ui->mario->update();
        QMessageBox error;
        error.setWindowTitle("Lo siento");
        error.setText("No has adivinado correctamente");
        error.setIcon(QMessageBox::Critical);
        error.exec();
        ui->goBack->show();
        ui->yoshi->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->toad->hide();
        ui->mario->hide();
        ui->birdo->hide();
        ui->bowser->hide();
        ui->peach->hide();
        ui->Boo->hide();
        ui->KingBoo->hide();
        ui->Floruga->hide();
        ui->luigi->hide();
        ui->goomba->hide();
        ui->koopa->hide();
        ui->magikoopa->hide();
    }
}

void GuessWhoWindow::on_goomba_clicked()
{
    if(currentCharacter == ":/char/goomba.png")
    {
        QPalette pal = ui->goomba->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        ui->goomba->setAutoFillBackground(true);
        ui->goomba->setPalette(pal);
        ui->goomba->update();
        QMessageBox congrats;
        congrats.setText("¡Has adivinado correctamente!");
        QPixmap check;
        congrats.setIconPixmap(check);
        congrats.exec();
        won = true;
        congrats.setWindowTitle("Felicidades");
        ui->goBack->show();
    }
    else{
        QPalette pal = ui->goomba->palette();
        pal.setColor(QPalette::Button, QColor(Qt::red));
        ui->goomba->setAutoFillBackground(true);
        ui->goomba->setPalette(pal);
        ui->goomba->update();
        QMessageBox error;
        error.setWindowTitle("Lo siento");
        error.setText("No has adivinado correctamente");
        error.setIcon(QMessageBox::Critical);
        error.exec();
        ui->goBack->show();
        ui->yoshi->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->toad->hide();
        ui->mario->hide();
        ui->birdo->hide();
        ui->mario->hide();
        ui->bowser->hide();
        ui->peach->hide();
        ui->Boo->hide();
        ui->KingBoo->hide();
        ui->Floruga->hide();
        ui->luigi->hide();
        ui->magikoopa->hide();
        ui->koopa->hide();
    }
}

void GuessWhoWindow::on_Floruga_clicked()
{
    if(currentCharacter == ":/char/floruga.png")
    {
        QPalette pal = ui->Floruga->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        ui->Floruga->setAutoFillBackground(true);
        ui->Floruga->setPalette(pal);
        ui->Floruga->update();

        QMessageBox congrats;
        congrats.setText("¡Has adivinado correctamente!");
        QPixmap check;
        congrats.setIconPixmap(check);
        congrats.exec();
        won = true;
        congrats.setWindowTitle("Felicidades");
        ui->goBack->show();
    }
    else{
        QPalette pal = ui->Floruga->palette();
        pal.setColor(QPalette::Button, QColor(Qt::red));
        ui->Floruga->setAutoFillBackground(true);
        ui->Floruga->setPalette(pal);
        ui->Floruga->update();

        QMessageBox error;
        error.setWindowTitle("Lo siento");
        error.setText("No has adivinado correctamente");
        error.setIcon(QMessageBox::Critical);
        error.exec();
        ui->goBack->show();
        ui->yoshi->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->toad->hide();
        ui->mario->hide();
        ui->birdo->hide();
        ui->mario->hide();
        ui->bowser->hide();
        ui->peach->hide();
        ui->Boo->hide();
        ui->KingBoo->hide();
        ui->luigi->hide();
        ui->goomba->hide();
        ui->koopa->hide();
        ui->magikoopa->hide();
    }
}

void GuessWhoWindow::on_magikoopa_clicked()
{
    if(currentCharacter == ":/char/magikoopa.jpg")
    {
        QPalette pal = ui->magikoopa->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        ui->magikoopa->setAutoFillBackground(true);
        ui->magikoopa->setPalette(pal);
        ui->magikoopa->update();

        QMessageBox congrats;
        congrats.setText("¡Has adivinado correctamente!");
        QPixmap check;
        congrats.setIconPixmap(check);
        congrats.exec();
        won = true;
        congrats.setWindowTitle("Felicidades");
        ui->goBack->show();
    }
    else{
        QPalette pal = ui->magikoopa->palette();
        pal.setColor(QPalette::Button, QColor(Qt::red));
        ui->magikoopa->setAutoFillBackground(true);
        ui->magikoopa->setPalette(pal);
        ui->magikoopa->update();

        QMessageBox error;
        error.setWindowTitle("Lo siento");
        error.setText("No has adivinado correctamente");
        error.setIcon(QMessageBox::Critical);
        error.exec();
        ui->goBack->show();
        ui->yoshi->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->toad->hide();
        ui->mario->hide();
        ui->birdo->hide();
        ui->mario->hide();
        ui->bowser->hide();
        ui->peach->hide();
        ui->Boo->hide();
        ui->KingBoo->hide();
        ui->luigi->hide();
        ui->goomba->hide();
        ui->koopa->hide();
    }
}
