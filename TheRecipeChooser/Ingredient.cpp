#include "Ingredient.h"

Ingredient::Ingredient(std::string n) : name{ n }{
	}


std::string Ingredient::getname() const{
	return name;
}

std::string Ingredient::getvalue() const {
	return this->name;
}