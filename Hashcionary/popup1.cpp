#include "popup1.h"

popup1::popup1(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.botaoOkMensagem, SIGNAL(clicked()), this, SLOT(close()));
}

popup1::~popup1()
{
}
