#pragma once
#include <QWidget>
#include "ui_ChooseRecipe.h"
#include "ViewRecipe.h"
#include "DeleteDialog.h"

using namespace std;

class ChooseRecipe : public QWidget, public Ui::ChooseRecipe
{
	Q_OBJECT

public:
	ChooseRecipe(QWidget *parent = Q_NULLPTR);
	~ChooseRecipe();
	
private:
	ViewRecipe* viewing = new ViewRecipe;
	DeleteDialog* deleting = new DeleteDialog;

private slots:
	void on_OKc_clicked();
	void on_srchbtn_clicked();
	void on_dltbtn_clicked();
	void deleteselectedrecipe();
	void NameListLoaded(QVector<QString> Values);
	void RecipeLoaded(QVector<QString> Values);
};
