#pragma once
#include <map>
#include <iostream>
#include <string>
#include "Ingredient.h"
#include "Amount.h"
#include "IRecipe.h"

using namespace std;

class Recipe : public IRecipe {
private:
    std::string rname;
    std::map<Ingredient, Amount> ingr;
    std::string howtomake;
    static int num_of_recipes;
public:
    Recipe(std::string n = { "No Name" }, std::string h = "Not Known", std::map<Ingredient, Amount> i = {});

    std::string makestring();

    virtual std::string getvalue() const override;
    virtual ~Recipe() { num_of_recipes--; };
};

