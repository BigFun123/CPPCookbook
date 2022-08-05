#pragma once

#include "framework.h"

class Animal {
public:
	CString _name;
	
	Animal();
	Animal(CString name);
	virtual ~Animal();
	virtual CString dump();
};