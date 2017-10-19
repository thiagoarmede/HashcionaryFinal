/********************************************************************************
** Form generated from reading UI file 'Hashcionary.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HASHCIONARY_H
#define UI_HASHCIONARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HashcionaryClass
{
public:
    QAction *actionAtiva;
    QWidget *centralWidget;
    QLineEdit *linhaBusca;
    QPushButton *botaoBuscar;
    QLabel *label;
    QTextBrowser *browserSignificado;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *HashcionaryClass)
    {
        if (HashcionaryClass->objectName().isEmpty())
            HashcionaryClass->setObjectName(QStringLiteral("HashcionaryClass"));
        HashcionaryClass->resize(380, 331);
        actionAtiva = new QAction(HashcionaryClass);
        actionAtiva->setObjectName(QStringLiteral("actionAtiva"));
        centralWidget = new QWidget(HashcionaryClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        linhaBusca = new QLineEdit(centralWidget);
        linhaBusca->setObjectName(QStringLiteral("linhaBusca"));
        linhaBusca->setGeometry(QRect(40, 50, 161, 21));
        botaoBuscar = new QPushButton(centralWidget);
        botaoBuscar->setObjectName(QStringLiteral("botaoBuscar"));
        botaoBuscar->setGeometry(QRect(260, 50, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 161, 21));
        QFont font;
        font.setFamily(QStringLiteral("Open Sans Semibold"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        browserSignificado = new QTextBrowser(centralWidget);
        browserSignificado->setObjectName(QStringLiteral("browserSignificado"));
        browserSignificado->setGeometry(QRect(40, 90, 301, 201));
        HashcionaryClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HashcionaryClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 380, 21));
        HashcionaryClass->setMenuBar(menuBar);

        retranslateUi(HashcionaryClass);
        QObject::connect(botaoBuscar, SIGNAL(clicked()), linhaBusca, SLOT(update()));

        QMetaObject::connectSlotsByName(HashcionaryClass);
    } // setupUi

    void retranslateUi(QMainWindow *HashcionaryClass)
    {
        HashcionaryClass->setWindowTitle(QApplication::translate("HashcionaryClass", "Hashcionary", Q_NULLPTR));
        actionAtiva->setText(QApplication::translate("HashcionaryClass", "ativa", Q_NULLPTR));
        linhaBusca->setPlaceholderText(QApplication::translate("HashcionaryClass", "Digite a palavra.", Q_NULLPTR));
        botaoBuscar->setText(QApplication::translate("HashcionaryClass", "Buscar", Q_NULLPTR));
        label->setText(QApplication::translate("HashcionaryClass", "Hashcion\303\241rio", Q_NULLPTR));
        browserSignificado->setPlaceholderText(QApplication::translate("HashcionaryClass", "Significado.", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HashcionaryClass: public Ui_HashcionaryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HASHCIONARY_H
