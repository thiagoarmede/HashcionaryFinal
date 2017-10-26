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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HashcionaryClass
{
public:
    QAction *actionInserir_palavra;
    QAction *actionExcluir_palavra;
    QAction *actionSair;
    QAction *actionListar_dicionario;
    QWidget *centralWidget;
    QLineEdit *linhaBusca;
    QPushButton *botaoBuscar;
    QLabel *label;
    QTextBrowser *browserSignificado;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuArquivo;
    QMenu *menuSobre;

    void setupUi(QMainWindow *HashcionaryClass)
    {
        if (HashcionaryClass->objectName().isEmpty())
            HashcionaryClass->setObjectName(QStringLiteral("HashcionaryClass"));
        HashcionaryClass->resize(389, 365);
        QIcon icon;
        icon.addFile(QStringLiteral("../dictionary1600.png"), QSize(), QIcon::Normal, QIcon::Off);
        HashcionaryClass->setWindowIcon(icon);
        HashcionaryClass->setDocumentMode(false);
        actionInserir_palavra = new QAction(HashcionaryClass);
        actionInserir_palavra->setObjectName(QStringLiteral("actionInserir_palavra"));
        actionExcluir_palavra = new QAction(HashcionaryClass);
        actionExcluir_palavra->setObjectName(QStringLiteral("actionExcluir_palavra"));
        actionSair = new QAction(HashcionaryClass);
        actionSair->setObjectName(QStringLiteral("actionSair"));
        actionListar_dicionario = new QAction(HashcionaryClass);
        actionListar_dicionario->setObjectName(QStringLiteral("actionListar_dicionario"));
        centralWidget = new QWidget(HashcionaryClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        linhaBusca = new QLineEdit(centralWidget);
        linhaBusca->setObjectName(QStringLiteral("linhaBusca"));
        linhaBusca->setGeometry(QRect(40, 50, 161, 21));
        botaoBuscar = new QPushButton(centralWidget);
        botaoBuscar->setObjectName(QStringLiteral("botaoBuscar"));
        botaoBuscar->setGeometry(QRect(300, 50, 75, 23));
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
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 300, 71, 31));
        HashcionaryClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HashcionaryClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 389, 21));
        menuArquivo = new QMenu(menuBar);
        menuArquivo->setObjectName(QStringLiteral("menuArquivo"));
        menuSobre = new QMenu(menuBar);
        menuSobre->setObjectName(QStringLiteral("menuSobre"));
        HashcionaryClass->setMenuBar(menuBar);

        menuBar->addAction(menuArquivo->menuAction());
        menuBar->addAction(menuSobre->menuAction());
        menuArquivo->addAction(actionInserir_palavra);
        menuArquivo->addAction(actionExcluir_palavra);
        menuArquivo->addAction(actionListar_dicionario);
        menuArquivo->addSeparator();
        menuArquivo->addAction(actionSair);

        retranslateUi(HashcionaryClass);

        QMetaObject::connectSlotsByName(HashcionaryClass);
    } // setupUi

    void retranslateUi(QMainWindow *HashcionaryClass)
    {
        HashcionaryClass->setWindowTitle(QApplication::translate("HashcionaryClass", "Hashcion\303\241rio", Q_NULLPTR));
        actionInserir_palavra->setText(QApplication::translate("HashcionaryClass", "Inserir palavra", Q_NULLPTR));
        actionExcluir_palavra->setText(QApplication::translate("HashcionaryClass", "Excluir palavra", Q_NULLPTR));
        actionSair->setText(QApplication::translate("HashcionaryClass", "Sair", Q_NULLPTR));
        actionListar_dicionario->setText(QApplication::translate("HashcionaryClass", "Listar dicion\303\241rio", Q_NULLPTR));
        linhaBusca->setPlaceholderText(QApplication::translate("HashcionaryClass", "Digite a palavra.", Q_NULLPTR));
        botaoBuscar->setText(QApplication::translate("HashcionaryClass", "Buscar", Q_NULLPTR));
        label->setText(QApplication::translate("HashcionaryClass", "Hashcion\303\241rio", Q_NULLPTR));
        browserSignificado->setPlaceholderText(QApplication::translate("HashcionaryClass", "Significado.", Q_NULLPTR));
        pushButton->setText(QApplication::translate("HashcionaryClass", "Sair", Q_NULLPTR));
        menuArquivo->setTitle(QApplication::translate("HashcionaryClass", "Arquivo", Q_NULLPTR));
        menuSobre->setTitle(QApplication::translate("HashcionaryClass", "Sobre", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HashcionaryClass: public Ui_HashcionaryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HASHCIONARY_H
