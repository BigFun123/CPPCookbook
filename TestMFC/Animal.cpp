#include <iostream>

#include "Animal.h"

Animal::Animal() {
	_name = "animal";
	std::cout << "Animal " << _name << " Constructed" << std::endl;
}

Animal::Animal(CString name) {
	_name = name;
	std::cout << "Animal " << _name << " Constructed" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal " << _name << " Destructed" << std::endl;
}

CString Animal::dump() {
	return _name;
}