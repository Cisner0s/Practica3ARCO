#ifndef FILTRONEGATIVO_H
#define FILTRONEGATIVO_H

#include <QDialog>
#include "filtronegativo.h"
#include "ui_filtronegativo.h"

#include <QMessageBox>

#include <QApplication>
#include <QFileDialog>
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

namespace Ui {
class FiltroNegativo;
}

class FiltroNegativo : public QDialog
{
    Q_OBJECT


public:
    explicit FiltroNegativo(QWidget *parent = nullptr);
    ~FiltroNegativo();

private slots:
    void on_pushButton_2_clicked();

    void on_seleccionarCarpeta_clicked();

    void on_ejecutar_clicked();

    void on_reset_clicked();

    void on_help_clicked();

private:
    Ui::FiltroNegativo *ui;
    QString originDirectory;
    QString destinyDirectory;
    double mediaTiempos;
};

#endif // FILTRONEGATIVO_H
