#pragma once
#include<string>
#include "IRecipe.h"
using namespace std;

class Amount : public IRecipe {
private:
    //double i_count{ 0 };
    std::string type, i_count;
public:
    Amount(std::string a, std::string t);

    std::string getamount() const;

    virtual std::string getvalue() const override;
    virtual ~Amount() = default;
};