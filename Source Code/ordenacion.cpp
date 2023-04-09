#include "ordenacion.h"
#include "ui_ordenacion.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QList>
#include <QFileInfo>
#include <QDebug>

using namespace std;

Ordenacion::Ordenacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ordenacion)
{
    ui->setupUi(this);
}

Ordenacion::~Ordenacion()
{
    delete ui;
}

void Ordenacion::on_ejecutar_button_clicked()
{
    // Concatenar el nombre del archivo de salida al final de la ruta de la carpeta seleccionada
    QString rutaArchivo = directorio + "/numeros_ordenados.txt";

    // Crear el archivo de salida
    QFile outputFile(rutaArchivo);
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Warning", "No se pudo crear el archivo.");
    }

    // Abrir el archivo de entrada
    QFile inputFile(archivo1);
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Warning", "No se pudo abrir el archivo.");
    }

    vector<int> numeros;

    // Leer los números del archivo no ordenados y almacenarlos en el vector
    int num;
    QTextStream inputStream(&inputFile);
    while (!inputStream.atEnd())
    {
        inputStream >> num;
        numeros.push_back(num);
    }

    clock_t start_time = clock();

    // Ordenar los números utilizando la función sort de la STL de C++
    sort(numeros.begin(), numeros.end());

    clock_t end_time = clock();

    // Escribir los números ordenados en el archivo de salida
    QTextStream outputStream(&outputFile);
    for (int i = 0; i < numeros.size(); i++)
    {
        outputStream << numeros[i] << "\n";
    }

    inputFile.close();
    outputFile.close();

    double duration = double(end_time - start_time) / CLOCKS_PER_SEC * 1000;
    QString durationStr = QString::number(duration);

    switch(count)
    { // Pintar los tiempos en los recuadros correpondientes.
        case 0:
            ui->textEdit->append(durationStr);
            media = duration;
            break;
        case 1:
            ui->textEdit_2->append(durationStr);
            media = media + duration;
            break;
        case 2:
            ui->textEdit_3->append(durationStr);
            media = media + duration;
            break;
        case 3:
            ui->textEdit_4->append(durationStr);
            media = media + duration;
            break;
        case 4:
            ui->textEdit_5->append(durationStr);
            media = media + duration;
            media = media/5;
            ui->textEdit_6->append(QString::number(media));
            media = 0;
            count = -1;
            break;
    }
    count++;
}



void Ordenacion::on_reset_button_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_4->clear();
    ui->textEdit_5->clear();
    ui->textEdit_6->clear();
}


void Ordenacion::on_seleccionarArch_clicked()
{
    count = 0;
    archivo1 = QFileDialog::getOpenFileName(
        this,
        "Seleccionar Archivo de Entrada",
        QDir::homePath(),
        "Archivos de texto (*.txt)"
    );

    directorio = QFileDialog::getExistingDirectory(
        nullptr, // Puntero a la ventana padre del cuadro de diálogo
        "Seleccionar Directorio Origen", // Cadena de texto que se muestra en la barra de título del cuadro de diálogo
        QDir::homePath(), // Ruta inicial que se muestra en el cuadro de diálogo
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks // Mostrar solo directorios y evitar la resolución de enlaces simbólicos
    );
}


void Ordenacion::on_pushButton_clicked()
{
    QMessageBox::information(this, "Help", "El formato de archivo que se reconoce es unicamente .txt \n Los tiempos estan expresados en milisegundos.");
}

