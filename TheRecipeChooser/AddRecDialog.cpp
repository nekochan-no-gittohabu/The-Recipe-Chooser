#include "AddRecDialog.h"

AddRecDialog::AddRecDialog(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
    QPixmap bkgnd("back3.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

AddRecDialog::~AddRecDialog()
{
}

void AddRecDialog::on_OKad_clicked() {
	this->close();
}