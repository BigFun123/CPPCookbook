#include "TestThreads.h"
#include <iostream>
#include <mutex>

using namespace std;


void threader(int p)
{
	for (int j = 0; j < 100; j++) {
		cout << "thread #" << this_thread::get_id() << " number " << p << endl ;
		std::this_thread::sleep_for(1ms);
	}

	cout << "thread complete id=" << this_thread::get_id();
}

// Test Threads
int TestThreads::Test()
{
	int i = 0;
	std::thread first(threader, 1);
	std::thread second(threader, 2);

	first.join();
	second.join();

	return 0;
    return 0;
}
