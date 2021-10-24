#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RecipeGUI.h"
#include "addrecipe.h"
#include "chooserecipe.h"
#include "AddRecDialog.h"
#include "ViewRecipe.h"

class RecipeGUI : public QMainWindow
{
    Q_OBJECT

public:
    RecipeGUI(QWidget *parent = Q_NULLPTR);
    ~RecipeGUI();

private:
    Ui::RecipeGUIClass ui;
    AddRecipe* adding = new AddRecipe();
    ChooseRecipe* choosing = new ChooseRecipe();

private slots:
    void on_addbtn_clicked();
    void on_chsbtn_clicked();
};
