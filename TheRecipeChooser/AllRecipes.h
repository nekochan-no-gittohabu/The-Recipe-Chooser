#pragma once

#include <QWidget>
#include "ui_AllRecipes.h"
#include "ViewRecipe.h"

class AllRecipes : public QWidget, public Ui::AllRecipes
{
	Q_OBJECT

public:
	AllRecipes(QWidget *parent = Q_NULLPTR);
	~AllRecipes();

private:
	ViewRecipe* viewing = new ViewRecipe;

private slots:
	void on_viewrecipe_clicked();
	void on_deleterecipe_clicked();
	void NameListLoaded(QVector<QString> Values);
};
