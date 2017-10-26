/********************************************************************************
** Form generated from reading UI file 'popup1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUP1_H
#define UI_POPUP1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_popup1
{
public:
    QPushButton *botaoOkMensagem;
    QLabel *labelMensagem;

    void setupUi(QWidget *popup1)
    {
        if (popup1->objectName().isEmpty())
            popup1->setObjectName(QStringLiteral("popup1"));
        popup1->setWindowModality(Qt::ApplicationModal);
        popup1->resize(234, 101);
        QIcon icon;
        icon.addFile(QStringLiteral("../dictionary1600.png"), QSize(), QIcon::Normal, QIcon::Off);
        popup1->setWindowIcon(icon);
        botaoOkMensagem = new QPushButton(popup1);
        botaoOkMensagem->setObjectName(QStringLiteral("botaoOkMensagem"));
        botaoOkMensagem->setGeometry(QRect(80, 60, 75, 23));
        labelMensagem = new QLabel(popup1);
        labelMensagem->setObjectName(QStringLiteral("labelMensagem"));
        labelMensagem->setGeometry(QRect(30, 20, 181, 20));
        QFont font;
        font.setPointSize(10);
        labelMensagem->setFont(font);

        retranslateUi(popup1);

        QMetaObject::connectSlotsByName(popup1);
    } // setupUi

    void retranslateUi(QWidget *popup1)
    {
        popup1->setWindowTitle(QApplication::translate("popup1", "popup1", Q_NULLPTR));
        botaoOkMensagem->setText(QApplication::translate("popup1", "Ok", Q_NULLPTR));
        labelMensagem->setText(QApplication::translate("popup1", "Palavra inserida com sucesso!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class popup1: public Ui_popup1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUP1_H
