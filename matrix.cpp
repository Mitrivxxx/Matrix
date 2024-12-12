#include "matrixClass.h"
#include <iostream>

int main() {
    // Test default constructor
    matrixClass m1;
    std::cout << "Default constructor:\n" << m1 << std::endl;

    // Test parameterized constructor
    matrixClass m2(3);
    std::cout << "Parameterized constructor (3x3 matrixClass):\n" << m2 << std::endl;

    // Test parameterized constructor with array
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    matrixClass m3(3, arr);
    std::cout << "Parameterized constructor with array (3x3 matrixClass):\n" << m3 << std::endl;

    // Test copy constructor
    matrixClass m4(m3);
    std::cout << "Copy constructor:\n" << m4 << std::endl;

    // Test losuj method
    m2.losuj();
    std::cout << "Randomized matrixClass:\n" << m2 << std::endl;

    // Test operators
    m2 += 5;
    std::cout << "matrixClass after adding 5 to each element:\n" << m2 << std::endl;

    return 0;
}