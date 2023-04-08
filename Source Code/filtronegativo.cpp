#include "filtronegativo.h"
#include "ui_filtronegativo.h"

#include <QMessageBox>

#include <QApplication>
#include <QFileDialog>
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

FiltroNegativo::FiltroNegativo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FiltroNegativo)
{
    ui->setupUi(this);
}

FiltroNegativo::~FiltroNegativo()
{
    delete ui;
}

void FiltroNegativo::on_seleccionarCarpeta_clicked()
{

    // Abrir cuadro de diálogo para seleccionar el directorio
            directory = QFileDialog::getExistingDirectory(
            nullptr, // Puntero a la ventana padre del cuadro de diálogo
            "Seleccionar directorio", // Cadena de texto que se muestra en la barra de título del cuadro de diálogo
            QDir::currentPath(), // Ruta inicial que se muestra en el cuadro de diálogo
            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks // Mostrar solo directorios y evitar la resolución de enlaces simbólicos
        );

        if (directory.isEmpty()) {
            cout << "No se seleccionó ningún directorio." << endl;

        }

}


void FiltroNegativo::on_ejecutar_clicked()
{ /*
    // Buscar todos los archivos .jpg en el directorio especificado
        String pattern = directory.toStdString() + "*.jpg"; falta /
        glob(pattern, filenames, false);

        // Mostrar los nombres de los archivos encontrados
        for (size_t i = 0; i < filenames.size(); i++)
        {
            cout << filenames[i] << endl;
        }
        */
}


void FiltroNegativo::on_reset_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_4->clear();
    ui->textEdit_5->clear();
    ui->textEdit_6->clear();
}


void FiltroNegativo::on_help_clicked()
{
    QMessageBox::information(this, "Help", "El formato de imagen que se reconoce es unicamente .jpg");
}

