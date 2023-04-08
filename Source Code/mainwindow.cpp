#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ordenacion.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pB_Ordenacion_clicked()
{
    ord = new Ordenacion(this);
    ord->show();
}

void MainWindow::on_pB_FiltroNegativo_clicked()
{
    filtroNeg = new FiltroNegativo();
    filtroNeg->show();
}

