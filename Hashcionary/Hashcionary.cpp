#include "Hashcionary.h"

Hashcionary::Hashcionary(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}


void Hashcionary::on_botaoBuscar_clicked() {
	ui.linhaBusca->setText("Meu Ovo");
}
