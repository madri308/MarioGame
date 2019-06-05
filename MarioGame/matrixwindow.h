#ifndef MATRIXWINDOW_H
#define MATRIXWINDOW_H

#include "QTableView"
#include <QMainWindow>

namespace Ui {
class MatrixWindow;
}

class MatrixWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MatrixWindow(QWidget *parent = nullptr);
    ~MatrixWindow();
    QTableView *matrix;
private:
    Ui::MatrixWindow *ui;
};

#endif // MATRIXWINDOW_H
