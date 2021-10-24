#include "Recipe.h"


int Recipe::num_of_recipes=0;

Recipe::Recipe(std::string n, std::string h, std::map<Ingredient, Amount> i) :
    rname{ n }, howtomake{ h }, ingr{ i }{
    std::cout << rname << ": Recipe added" << std::endl;
    std::cout <<"Number of recipes: " << ++num_of_recipes << std::endl;
}

std::string Recipe::makestring() {
    std::string ingr_string{};
    std::string amo_string{};
    auto it = (this->ingr).begin();
    while (it != (this->ingr).end()) {
        ingr_string += it->first.getname() + "\n";
        amo_string += it->second.getamount() + "\n";
        it++;
    }
    std::string mystring = "'" + this->rname + "', '" + ingr_string + "', '" + amo_string + "', '" + this->howtomake + "'";
    return mystring;
}

std::string Recipe::getvalue() const {
	return this->rname;
}
