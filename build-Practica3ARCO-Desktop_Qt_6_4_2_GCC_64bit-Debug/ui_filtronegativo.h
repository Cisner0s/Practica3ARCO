/********************************************************************************
** Form generated from reading UI file 'filtronegativo.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTRONEGATIVO_H
#define UI_FILTRONEGATIVO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_FiltroNegativo
{
public:

    void setupUi(QDialog *FiltroNegativo)
    {
        if (FiltroNegativo->objectName().isEmpty())
            FiltroNegativo->setObjectName("FiltroNegativo");
        FiltroNegativo->resize(400, 300);

        retranslateUi(FiltroNegativo);

        QMetaObject::connectSlotsByName(FiltroNegativo);
    } // setupUi

    void retranslateUi(QDialog *FiltroNegativo)
    {
        FiltroNegativo->setWindowTitle(QCoreApplication::translate("FiltroNegativo", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FiltroNegativo: public Ui_FiltroNegativo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTRONEGATIVO_H
