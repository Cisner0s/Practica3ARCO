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

private:
    Ui::Ordenacion *ui;
};

#endif // ORDENACION_H
