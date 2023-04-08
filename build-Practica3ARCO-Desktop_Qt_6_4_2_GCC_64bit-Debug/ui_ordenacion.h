/********************************************************************************
** Form generated from reading UI file 'ordenacion.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDENACION_H
#define UI_ORDENACION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Ordenacion
{
public:

    void setupUi(QDialog *Ordenacion)
    {
        if (Ordenacion->objectName().isEmpty())
            Ordenacion->setObjectName("Ordenacion");
        Ordenacion->resize(426, 313);

        retranslateUi(Ordenacion);

        QMetaObject::connectSlotsByName(Ordenacion);
    } // setupUi

    void retranslateUi(QDialog *Ordenacion)
    {
        Ordenacion->setWindowTitle(QCoreApplication::translate("Ordenacion", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ordenacion: public Ui_Ordenacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDENACION_H
