#include "option.hpp"

Option::operator int() const {
	return std::stoi(value);
}
