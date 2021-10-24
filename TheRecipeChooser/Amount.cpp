#include "Amount.h"

Amount::Amount(std::string a, std::string t) : i_count{ a }, type{ t } {
}

std::string Amount::getamount() const {
	//std::string a = to_string(this->i_count);
	std::string res = this->i_count + " " + this->type;
	return res;
}

std::string Amount::getvalue() const {
	return this->type;
}