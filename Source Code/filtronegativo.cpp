#include "filtronegativo.h"
#include "ui_filtronegativo.h"

#include <QMessageBox>

#include <QApplication>
#include <QFileDialog>
#include <iostream>
#include <vector>
#include <ctime>
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

    // Abrir cuadro de diálogo para seleccionar el directorio de origen
    originDirectory = QFileDialog::getExistingDirectory(
        nullptr, // Puntero a la ventana padre del cuadro de diálogo
        "Seleccionar Directorio Origen", // Cadena de texto que se muestra en la barra de título del cuadro de diálogo
        QDir::homePath(), // Ruta inicial que se muestra en el cuadro de diálogo
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks // Mostrar solo directorios y evitar la resolución de enlaces simbólicos
    );

    if (originDirectory.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "No se seleccionó ningún directorio.");
    }

    ui->rutaOrigen->setText(originDirectory);

    // Abrir cuadro de diálogo para seleccionar el directorio de destino
    destinyDirectory = QFileDialog::getExistingDirectory(
        nullptr, // Puntero a la ventana padre del cuadro de diálogo
        "Seleccionar Directorio Destino", // Cadena de texto que se muestra en la barra de título del cuadro de diálogo
        QDir::homePath(), // Ruta inicial que se muestra en el cuadro de diálogo
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks // Mostrar solo directorios y evitar la resolución de enlaces simbólicos
    );

    if (destinyDirectory.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "No se seleccionó ningún directorio.");
    }

    ui->rutaDestino->setText(destinyDirectory);

}


void FiltroNegativo::on_ejecutar_clicked()
{
    mediaTiempos = 0;
    for(int i = 0; i < 5 ; i++ )
    {
       clock_t start_time = clock();

    // Obtener lista de archivos
       vector<String> filenames;
       string sourceDirectoryStr = originDirectory.toStdString();
       glob(sourceDirectoryStr + "/*.jpg", filenames);

       if (filenames.empty())
       {
           QMessageBox::warning(this, "Warning", "No se encontraron archivos JPG en el directorio de origen.");
       }

       // Aplicar filtro negativo y guardar imágenes en el directorio de destino
       for (const auto &filename : filenames) {
           Mat image = imread(filename);
           if (image.empty())
           {
               QMessageBox::warning(this, "Warning", "No se pudo leer el archivo.");
               continue;
           }

           Mat negativeImage;
           bitwise_not(image, negativeImage);

           string dstFilename = destinyDirectory.toStdString() + "/" + QFileInfo(QString::fromStdString(filename)).fileName().toStdString();

           bool success = imwrite(dstFilename, negativeImage);
           if (!success)
           {
               QMessageBox::warning(this, "Warning", "No se pudo guardar la imagen en el archivo");
               continue;
           }
       }

       clock_t end_time = clock();
       double elapsed_time = (double(end_time - start_time) / CLOCKS_PER_SEC) * 1000;
       mediaTiempos += elapsed_time;

       // Pintar los tiempos en los recuadros.
       switch(i)
       {
            case 0:
                ui->textEdit->setText(QString::number(elapsed_time));
                break;
            case 1:
                ui->textEdit_2->setText(QString::number(elapsed_time));
                break;
            case 2:
                ui->textEdit_3->setText(QString::number(elapsed_time));
                break;
            case 3:
                ui->textEdit_4->setText(QString::number(elapsed_time));
                break;
            case 4:
                ui->textEdit_6->setText(QString::number(elapsed_time));
                break;
       }
    }

    mediaTiempos = mediaTiempos/5;
    ui->textEdit_5->setText(QString::number(mediaTiempos));
}


void FiltroNegativo::on_reset_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_4->clear();
    ui->textEdit_5->clear();
    ui->textEdit_6->clear();
    ui->rutaOrigen->clear();
    ui->rutaDestino->clear();
}


void FiltroNegativo::on_help_clicked()
{
    QMessageBox::information(this, "Help", "El formato de imagen que se reconoce es unicamente .jpg \n Los tiempos estan expresados en milisegundos.");
}

