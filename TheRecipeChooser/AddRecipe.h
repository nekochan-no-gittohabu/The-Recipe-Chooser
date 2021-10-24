#pragma once

#include <QWidget>
#include "ui_AddRecipe.h"
#include "AddRecDialog.h"
#include <map>
#include "Recipe.h"
#include "Ingredient.h"
#include "Amount.h"
#include "IRecipe.h"
#include <sstream>

class AddRecipe : public QWidget, public Ui::AddRecipe
{
	Q_OBJECT

public:
	AddRecipe(QWidget *parent = Q_NULLPTR);
	~AddRecipe();

private:
	AddRecDialog* adddia = new AddRecDialog();

private slots:
	void on_OKa_clicked();
	void on_addingr_clicked();
	void on_deleteingr_clicked();
};
