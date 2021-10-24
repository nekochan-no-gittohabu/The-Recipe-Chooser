#pragma once
using namespace std;
#include<string>

class IRecipe {
private:
	friend bool operator<(const IRecipe& lhs, const IRecipe& rhs);
	friend bool operator==(const IRecipe& lhs, const IRecipe& rhs);
public:
	IRecipe() = default;
	virtual std::string getvalue() const = 0;
	virtual ~IRecipe() = default;
};

