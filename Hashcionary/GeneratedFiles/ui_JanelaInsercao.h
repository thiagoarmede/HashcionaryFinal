/********************************************************************************
** Form generated from reading UI file 'JanelaInsercao.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELAINSERCAO_H
#define UI_JANELAINSERCAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JanelaInsercao
{
public:
    QLabel *label;
    QLineEdit *InsereLinhaPalavra;
    QTextEdit *InsereMostraTexto;
    QPushButton *InsereBotaoInserir;
    QPushButton *InsereBotaoVoltar;

    void setupUi(QWidget *JanelaInsercao)
    {
        if (JanelaInsercao->objectName().isEmpty())
            JanelaInsercao->setObjectName(QStringLiteral("JanelaInsercao"));
        JanelaInsercao->resize(349, 331);
        label = new QLabel(JanelaInsercao);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 20, 71, 20));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        InsereLinhaPalavra = new QLineEdit(JanelaInsercao);
        InsereLinhaPalavra->setObjectName(QStringLiteral("InsereLinhaPalavra"));
        InsereLinhaPalavra->setGeometry(QRect(30, 50, 291, 21));
        InsereMostraTexto = new QTextEdit(JanelaInsercao);
        InsereMostraTexto->setObjectName(QStringLiteral("InsereMostraTexto"));
        InsereMostraTexto->setGeometry(QRect(30, 80, 291, 192));
        InsereBotaoInserir = new QPushButton(JanelaInsercao);
        InsereBotaoInserir->setObjectName(QStringLiteral("InsereBotaoInserir"));
        InsereBotaoInserir->setGeometry(QRect(70, 290, 75, 23));
        InsereBotaoVoltar = new QPushButton(JanelaInsercao);
        InsereBotaoVoltar->setObjectName(QStringLiteral("InsereBotaoVoltar"));
        InsereBotaoVoltar->setGeometry(QRect(210, 290, 75, 23));

        retranslateUi(JanelaInsercao);

        QMetaObject::connectSlotsByName(JanelaInsercao);
    } // setupUi

    void retranslateUi(QWidget *JanelaInsercao)
    {
        JanelaInsercao->setWindowTitle(QApplication::translate("JanelaInsercao", "JanelaInsercao", Q_NULLPTR));
        label->setText(QApplication::translate("JanelaInsercao", "Inser\303\247\303\243o", Q_NULLPTR));
        InsereLinhaPalavra->setPlaceholderText(QApplication::translate("JanelaInsercao", "Digite a palavra a inserir.", Q_NULLPTR));
        InsereMostraTexto->setPlaceholderText(QApplication::translate("JanelaInsercao", "Digite o significado da palavra.", Q_NULLPTR));
        InsereBotaoInserir->setText(QApplication::translate("JanelaInsercao", "Inserir", Q_NULLPTR));
        InsereBotaoVoltar->setText(QApplication::translate("JanelaInsercao", "Voltar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class JanelaInsercao: public Ui_JanelaInsercao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELAINSERCAO_H
