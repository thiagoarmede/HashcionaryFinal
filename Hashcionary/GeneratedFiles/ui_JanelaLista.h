/********************************************************************************
** Form generated from reading UI file 'JanelaLista.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELALISTA_H
#define UI_JANELALISTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JanelaLista
{
public:
    QLabel *label;
    QPushButton *botaoListar;
    QTextEdit *listaArquivo;

    void setupUi(QWidget *JanelaLista)
    {
        if (JanelaLista->objectName().isEmpty())
            JanelaLista->setObjectName(QStringLiteral("JanelaLista"));
        JanelaLista->resize(669, 728);
        QIcon icon;
        icon.addFile(QStringLiteral("../dictionary1600.png"), QSize(), QIcon::Normal, QIcon::Off);
        JanelaLista->setWindowIcon(icon);
        label = new QLabel(JanelaLista);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 10, 201, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        botaoListar = new QPushButton(JanelaLista);
        botaoListar->setObjectName(QStringLiteral("botaoListar"));
        botaoListar->setGeometry(QRect(300, 50, 75, 23));
        listaArquivo = new QTextEdit(JanelaLista);
        listaArquivo->setObjectName(QStringLiteral("listaArquivo"));
        listaArquivo->setGeometry(QRect(40, 90, 601, 611));

        retranslateUi(JanelaLista);

        QMetaObject::connectSlotsByName(JanelaLista);
    } // setupUi

    void retranslateUi(QWidget *JanelaLista)
    {
        JanelaLista->setWindowTitle(QApplication::translate("JanelaLista", "JanelaLista", Q_NULLPTR));
        label->setText(QApplication::translate("JanelaLista", "Dicion\303\241rio Completo", Q_NULLPTR));
        botaoListar->setText(QApplication::translate("JanelaLista", "Listar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class JanelaLista: public Ui_JanelaLista {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELALISTA_H
