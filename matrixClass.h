#ifndef matrixClass_H
#define matrixClass_H

#include <iostream>

class matrixClass {
private:
    int n;
    int** data;

public:
    // Constructors and Destructor
    matrixClass(); // Default constructor
    matrixClass(int n); // Parameterized constructor
    matrixClass(int n, int* t); // Parameterized constructor with array
    matrixClass(const matrixClass& m); // Copy constructor
    ~matrixClass(); // Destructor

    // Methods
    matrixClass& alokuj(int n);
    matrixClass& wstaw(int x, int y, int wartosc);
    int pokaz(int x, int y);
    matrixClass& dowroc();
    matrixClass& losuj();
    matrixClass& losuj(int x);
    //matrixClass& diagonalna(int* t);
    //matrixClass& diagonalna_k(int k, int* t);
    //matrixClass& kolumna(int x, int* t);
    //matrixClass& wiersz(int y, int* t);
    //matrixClass& przekatna();
    //matrixClass& pod_przekatna();
    //matrixClass& nad_przekatna();
    //matrixClass& szachownica();

    // Operators
    matrixClass& operator+(const matrixClass& m);
    matrixClass& operator*(const matrixClass& m);
    matrixClass& operator+(int a);
    matrixClass& operator*(int a);
    //matrixClass& operator-(int a);
    //friend matrixClass operator+(int a, const matrixClass& m);
    //friend matrixClass operator*(int a, const matrixClass& m);
    //friend matrixClass operator-(int a, const matrixClass& m);
    //matrixClass& operator++(int);
    //matrixClass& operator--(int);
    matrixClass& operator+=(int a);
    //matrixClass& operator-=(int a);
    //matrixClass& operator*=(int a);
    //matrixClass& operator=(double a); // Corrected operator
    friend std::ostream& operator<<(std::ostream& o, const matrixClass& m);
    bool operator==(const matrixClass& m) const;
    bool operator>(const matrixClass& m) const;
    bool operator<(const matrixClass& m) const;
};

#endif // matrixClass_H