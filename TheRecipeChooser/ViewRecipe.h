#pragma once

#include <QWidget>
#include "ui_ViewRecipe.h"

class ViewRecipe : public QWidget, public Ui::ViewRecipe
{
	Q_OBJECT

public:
	ViewRecipe(QWidget *parent = Q_NULLPTR);
	~ViewRecipe();

private slots:
	void on_OKview_clicked();
};
