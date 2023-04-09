#ifndef ORDENACION_H
#define ORDENACION_H

#include <QDialog>

namespace Ui {
class Ordenacion;
}

class Ordenacion : public QDialog
{
    Q_OBJECT

public:
    explicit Ordenacion(QWidget *parent = nullptr);
    ~Ordenacion();

private slots:
    void on_ejecutar_button_clicked();

    void on_reset_button_clicked();

    void on_seleccionarArch_clicked();

private:
    Ui::Ordenacion *ui;
    QString archivo1;
    QString directorio;
};

#endif // ORDENACION_H
