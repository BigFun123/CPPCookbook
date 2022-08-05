#include <afxwin.h>
#include <iostream>
#include "Lion.h"

Lion::Lion() {
	Animal::_name = "Lion";
	std::cout << "Lion " << _name << " Constructed" << std::endl;
}

Lion::~Lion() {
	std::cout << "Lion " << _name << " Destructed" << std::endl;
}

CString Lion::dump() {
	
	return "Lion: " + _name;
}