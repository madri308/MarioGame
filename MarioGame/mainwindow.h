#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QLabel>
#include <time.h>
#include <QTime>
#include <QTimer>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QString diccionary[100] = {"ataque", "recolecta", "recluta", "cortesia", "placer", "seguridad", "voucher", "agricultura", "medio", "plata",
                              "moneda", "mezcla", "atraer", "batalla", "comun", "golpe", "calabaza", "ganga", "veneno", "galon",
                              "ecuacion", "comprensivo", "motivar", "mirar", "transformar", "critico", "monstruo", "dormir", "cancion", "elaborar",
                              "color", "metodo", "revolver", "ciencia", "insistir", "introducir", "campeon", "horror", "terror", "miedo",
                              "logro", "chimenea", "marihuana", "predador", "concreto", "manos", "juzgar", "derrota", "ganar", "chile",
                              "outlet", "genetica", "labor", "ensayo", "declaracion", "prosperar", "realidad", "habitat", "borrar", "cambiar",
                              "coser", "extasis", "violacion", "castillo", "villa", "nueva", "consumir", "transferir", "tragar", "convicto",
                              "cristal", "monos", "sobre", "instruccion", "ritmo", "inicial", "quejarse", "integrar", "tirar", "bosque",
                              "diametro", "retirado", "persona", "aguja", "razonar", "fabricar", "abeja", "caloria", "microfono", "avanzar",
                              "calcular", "censura", "supervisar", "aprobar", "peligro", "descubrir", "archivar", "alcohol", "cajas", "fans"};

    QString alphabet[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    QString wordsToHide[4];
    QTimer *timer;
    QTime actualTime = QTime(0, 2, 0);
    void generateMatrix();
    void checkWords(QString[4], int);
    ~MainWindow();

private slots:
    void on_checkButton_clicked();
    void updateCountdown();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
