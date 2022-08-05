#pragma once

#include "Animal.h"
#include "lion.h"

class TestPointers
{
public:
	TestPointers();
	virtual ~TestPointers();
	int TestSharedPtr(Animal& h);
	int TestUniquePtr();
	int TestWeakPtr();
};


