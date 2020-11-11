#ifndef OPTION_HPP
#define OPTIION_HPP

#include <string>

class Option {
public:
	Option() : Option("") {}
	explicit Option(const std::string& val) : value(val) {}
	operator int() const;			// return value as int

private:
	std::string value;
};

#endif