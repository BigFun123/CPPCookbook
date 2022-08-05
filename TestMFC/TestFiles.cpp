#include "TestFiles.h"
#include <fstream>
#include <iostream>
#include <string>

int TestFiles::Test() {

	using namespace std;

	cout << "Writing file test.txt" << endl;
	fstream newfile;
	newfile.open("test.txt", ios::out);
	if (newfile.is_open())
	{
		newfile << "Test, 0, 1, 2,3, 1\n";
		newfile.close();
	}

	cout << "Reading file test.txt" << endl;

	newfile.open("test.txt", ios::in);
	if (newfile.is_open())
	{
		string tp;
		getline(newfile, tp);
		cout << tp << endl;
	}

	cout << "Completed testing files" << endl;
	return 0;

}