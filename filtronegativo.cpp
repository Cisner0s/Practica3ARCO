#include "filtronegativo.h"
#include "ui_filtronegativo.h"

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
