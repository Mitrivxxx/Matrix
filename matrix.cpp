#include "matrixClass.h"
#include <iostream>

int main() {
    // Test default constructor
    matrixClass m1;
   // std::cout << "Default constructor:\n" << m1 << std::endl;

    
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

    matrixClass matrix(3);

    // Przykładowe dane do wstawienia
    int diagonalValues[3] = { 1, 2, 3 };
    int columnValues[3] = { 4, 5, 6 };
    int rowValues[3] = { 7, 8, 9 };

    // Użycie metody diagonalna
    matrix.diagonalna(diagonalValues);
    std::cout << "Po użyciu metody diagonalna:\n" << matrix << std::endl;

    // Użycie metody diagonalna_k
    matrix.diagonalna_k(1, diagonalValues);
    std::cout << "Po użyciu metody diagonalna_k(1):\n" << matrix << std::endl;

    // Użycie metody kolumna
    matrix.kolumna(1, columnValues);
    std::cout << "Po użyciu metody kolumna(1):\n" << matrix << std::endl;

    // Użycie metody wiersz
    matrix.wiersz(1, rowValues);
    std::cout << "Po użyciu metody wiersz(1):\n" << matrix << std::endl;

    // Ustawia wartości na przekątnej macierzy
 


 

    // Test operators
    m2 += 5;
    std::cout << "matrixClass after adding 5 to each element:\n" << m2 << std::endl;

    // Test friend operator*(int a, const matrixClass& m)
    matrixClass m6 = 3 * m1;
    std::cout << "Matrix after multiplying each element by 3:\n" << m3 << std::endl;

    // Test friend operator-(int a, const matrixClass& m)
    matrixClass m5 = 10 - m6;
    std::cout << "Matrix after subtracting each element from 10:\n" << m4 << std::endl;

    // Test operator++(int)
    matrixClass m16(3); // Przykładowa macierz 3x3
    m16.losuj(); // Wypełnia macierz losowymi wartościami

    std::cout << "Initial matrix:\n" << m16 << std::endl;

    m16++;
    std::cout << "Matrix after post-incrementing each element by 1:\n" << m16 << std::endl;

    m16--;
    std::cout << "Matrix after post-decrementing each element by 1:\n" << m16 << std::endl;

    matrixClass m11(3);

    // Wstawianie wartości do macierzy
    m11.wstaw(0, 0, 1).wstaw(0, 1, 2).wstaw(0, 2, 3);
    m11.wstaw(1, 0, 4).wstaw(1, 1, 5).wstaw(1, 2, 6);
    m11.wstaw(2, 0, 7).wstaw(2, 1, 8).wstaw(2, 2, 9);

    // Wyświetlanie macierzy
    std::cout << "Macierz początkowa:\n" << m11 << std::endl;

    // Użycie operatora -=
    m11 -= 1;
    std::cout << "Po użyciu operatora -= 1:\n" << m11 << std::endl;

    // Użycie operatora *=
    m11 *= 2;
    std::cout << "Po użyciu operatora *= 2:\n" << m11 << std::endl;

    // Użycie operatora =
    m11 = 5.0;
    std::cout << "Po użyciu operatora = 5.0:\n" << m11 << std::endl;



    

    return 0;
}