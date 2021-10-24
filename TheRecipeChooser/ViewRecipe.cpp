#include "ViewRecipe.h"

ViewRecipe::ViewRecipe(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
    QPixmap bkgnd("back2.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

ViewRecipe::~ViewRecipe()
{
}


void ViewRecipe::on_OKview_clicked() {
	this->close();
}