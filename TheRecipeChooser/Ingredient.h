#pragma once
#include<string>
#include "IRecipe.h"
using namespace std;

class Ingredient : public IRecipe {
private:
    std::string name;

public:
    Ingredient(std::string n);

    std::string getname() const;

    virtual std::string getvalue() const override;
    virtual ~Ingredient() = default;
};