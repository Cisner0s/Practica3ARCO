#ifndef FILTRONEGATIVO_H
#define FILTRONEGATIVO_H

#include <QDialog>

namespace Ui {
class FiltroNegativo;
}

class FiltroNegativo : public QDialog
{
    Q_OBJECT

public:
    explicit FiltroNegativo(QWidget *parent = nullptr);
    ~FiltroNegativo();

private:
    Ui::FiltroNegativo *ui;
};

#endif // FILTRONEGATIVO_H
