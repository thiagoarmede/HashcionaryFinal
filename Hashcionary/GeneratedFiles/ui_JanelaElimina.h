/********************************************************************************
** Form generated from reading UI file 'JanelaElimina.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELAELIMINA_H
#define UI_JANELAELIMINA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JanelaElimina
{
public:
    QLineEdit *linhaElimina;
    QPushButton *botaoElimina;
    QPushButton *eliminaBotaoVoltar;
    QLabel *label;

    void setupUi(QWidget *JanelaElimina)
    {
        if (JanelaElimina->objectName().isEmpty())
            JanelaElimina->setObjectName(QStringLiteral("JanelaElimina"));
        JanelaElimina->setWindowModality(Qt::ApplicationModal);
        JanelaElimina->resize(364, 128);
        QIcon icon;
        icon.addFile(QStringLiteral("../dictionary1600.png"), QSize(), QIcon::Normal, QIcon::Off);
        JanelaElimina->setWindowIcon(icon);
        linhaElimina = new QLineEdit(JanelaElimina);
        linhaElimina->setObjectName(QStringLiteral("linhaElimina"));
        linhaElimina->setGeometry(QRect(60, 50, 241, 21));
        botaoElimina = new QPushButton(JanelaElimina);
        botaoElimina->setObjectName(QStringLiteral("botaoElimina"));
        botaoElimina->setGeometry(QRect(80, 90, 75, 23));
        eliminaBotaoVoltar = new QPushButton(JanelaElimina);
        eliminaBotaoVoltar->setObjectName(QStringLiteral("eliminaBotaoVoltar"));
        eliminaBotaoVoltar->setGeometry(QRect(210, 90, 75, 23));
        label = new QLabel(JanelaElimina);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 10, 141, 20));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        retranslateUi(JanelaElimina);

        QMetaObject::connectSlotsByName(JanelaElimina);
    } // setupUi

    void retranslateUi(QWidget *JanelaElimina)
    {
        JanelaElimina->setWindowTitle(QApplication::translate("JanelaElimina", "JanelaElimina", Q_NULLPTR));
        linhaElimina->setPlaceholderText(QApplication::translate("JanelaElimina", "Digite a palavra a ser eliminada do dicion\303\241rio", Q_NULLPTR));
        botaoElimina->setText(QApplication::translate("JanelaElimina", "Eliminar", Q_NULLPTR));
        eliminaBotaoVoltar->setText(QApplication::translate("JanelaElimina", "Voltar", Q_NULLPTR));
        label->setText(QApplication::translate("JanelaElimina", "Eliminar Palavras", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class JanelaElimina: public Ui_JanelaElimina {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELAELIMINA_H
