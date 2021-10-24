#include "RecipeGUI.h"
#include "AddRecipe.h"
#include "ChooseRecipe.h"
#include "AddRecDialog.h"
#include "ViewRecipe.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <map>
#include "Recipe.h"
#include "Ingredient.h"
#include "Amount.h"
#include "Database_Manager.h"
#include "IRecipe.h"
#include <stdio.h>
#include <string>
#include <memory>
using namespace std;


int main(int argc, char *argv[])
{
    Database_Manager::Get();

    QApplication a(argc, argv);
    RecipeGUI w;
    w.show();
    return a.exec();
}