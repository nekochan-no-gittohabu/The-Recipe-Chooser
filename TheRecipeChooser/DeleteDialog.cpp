#include "DeleteDialog.h"

DeleteDialog::DeleteDialog(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
	QPixmap bkgnd("back3.jpg");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);
}

DeleteDialog::~DeleteDialog()
{
}

void DeleteDialog::on_yesdelete_clicked() {
	emit this->deleteselectedrecipe();
	this->close();
}