#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include <string>

#include "TestPointers.h"
#include <mutex>


using namespace std;

// type alias
using AnimalPtr = std::shared_ptr<Animal>;

TestPointers::TestPointers() {
	std::cout << "new PointerStuff\n";
}

TestPointers::~TestPointers() {
	std::cout << "PointerStuff died\n";
}

int TestPointers::TestSharedPtr(Animal& h)
{
	std::cout << "TestSharedPtr\n";

	auto sp = std::make_shared<Animal>(Animal());

	std::vector<AnimalPtr> f;
	f.push_back(sp);

	return 0;
}

int TestPointers::TestUniquePtr()
{
	std::cout << "TestUniquePtr\n";

	auto up = std::make_unique<Animal>(Lion());
	return 0;
}

int TestPointers::TestWeakPtr()
{
	std::cout << "TestWeakPtr" << std::endl;

	for (int i = 0; i < 10; i++) {
		std::shared_ptr<Animal> an = std::make_shared<Animal>(Animal());
		std::cout << "AN Count: " << an.use_count() << std::endl;
		std::weak_ptr<Animal> wp = an;
		std::cout << "wp Use Count: " << wp.use_count() << std::endl;
		auto p = wp.lock();
		std::cout << "wp Use Count: " << wp.use_count() << std::endl;
		std::cout << "p UC:" << p.use_count() << std::endl;
		std::cout << "wp Use Count: " << wp.use_count() << std::endl;
		std::cout << "AN Count: " << an.use_count() << std::endl;

	}

	return 0;
}

