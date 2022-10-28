/********************************************************************************
** Form generated from reading UI file 'GUI_Gadget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_GADGET_H
#define UI_GUI_GADGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI_Gadget
{
public:

    void setupUi(QWidget *GUI_Gadget)
    {
        if (GUI_Gadget->objectName().isEmpty())
            GUI_Gadget->setObjectName(QString::fromUtf8("GUI_Gadget"));
        GUI_Gadget->resize(400, 300);

        retranslateUi(GUI_Gadget);

        QMetaObject::connectSlotsByName(GUI_Gadget);
    } // setupUi

    void retranslateUi(QWidget *GUI_Gadget)
    {
        GUI_Gadget->setWindowTitle(QCoreApplication::translate("GUI_Gadget", "GUI_Gadget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI_Gadget: public Ui_GUI_Gadget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_GADGET_H
