#include "ordenacion.h"
#include "ui_ordenacion.h"

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
