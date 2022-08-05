// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MathLibrary.h"

void ExampleConstCast();

int main()
{
    int a, b;
    std::cout << "Enter the first number:!\n";
    std::cin >> a;
    std::cout << "Enter the second number:!\n";
    std::cin >> b;

    fibonacci_init(a, b);
    do {
        std::cout << fibonacci_index() << ":"
            << fibonacci_current() << std::endl;
    } while (fibonacci_next());

    std::cout << fibonacci_index() + 1 <<
        " Fits in " << std::endl;

    ExampleConstCast();
}

void ExampleConstCast() {
    const int Temp = 0;
    //std::cin >> Temp;
    int* t = const_cast<int*>(&Temp);
    *t = 2;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
