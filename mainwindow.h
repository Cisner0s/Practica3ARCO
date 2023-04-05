#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ordenacion.h"
#include "filtronegativo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pB_Ordenacion_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Ordenacion *ord;
    FiltroNegativo *filtroNeg;
};
#endif // MAINWINDOW_H
