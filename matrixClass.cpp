#include "matrixClass.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Default constructor
matrixClass::matrixClass() : n(0), data(nullptr) {}

// Parameterized constructor
matrixClass::matrixClass(int n) : n(n) {
    data = new int* [n];
    for (int i = 0; i < n; ++i) {
        data[i] = new int[n];
    }
}

// Parameterized constructor with array
matrixClass::matrixClass(int n, int* t) : n(n) {
    data = new int* [n];
    for (int i = 0; i < n; ++i) {
        data[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            data[i][j] = t[i * n + j];
        }
    }
}

// Copy constructor
matrixClass::matrixClass(const matrixClass& m) : n(m.n) {
    data = new int* [n];
    for (int i = 0; i < n; ++i) {
        data[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            data[i][j] = m.data[i][j];
        }
    }
}

// Destructor
matrixClass::~matrixClass() {
    for (int i = 0; i < n; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

// Method implementations
matrixClass& matrixClass::alokuj(int n) {
    if (this->n != n) {
        for (int i = 0; i < this->n; ++i) {
            delete[] data[i];
        }
        delete[] data;

        this->n = n;
        data = new int* [n];
        for (int i = 0; i < n; ++i) {
            data[i] = new int[n];
        }
    }
    return *this;
}

matrixClass& matrixClass::wstaw(int x, int y, int wartosc) {
    data[x][y] = wartosc;
    return *this;
}

int matrixClass::pokaz(int x, int y) {
    return data[x][y];
}

matrixClass& matrixClass::dowroc() {
    int** new_data = new int* [n];
    for (int i = 0; i < n; ++i) {
        new_data[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            new_data[i][j] = data[j][i];
        }
    }

    for (int i = 0; i < n; ++i) {
        delete[] data[i];
    }
    delete[] data;

    data = new_data;
    return *this;
}

matrixClass& matrixClass::losuj() {
    std::srand(std::time(0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = std::rand() % 10;
        }
    }
    return *this;
}
matrixClass& matrixClass::operator+=(int a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] += a;
        }
    }
    return *this;
}
matrixClass& matrixClass::losuj(int x) {
    std::srand(std::time(0));
    for (int i = 0; i < x; ++i) {
        int row = std::rand() % n;
        int col = std::rand() % n;
        data[row][col] = std::rand() % 10;
    }
    return *this;
}

// The remaining methods should be implemented similarly...

// Operator implementations
matrixClass& matrixClass::operator+(const matrixClass& m) {
    // Implement addition logic...
    return *this;
}

matrixClass& matrixClass::operator*(const matrixClass& m) {
    // Implement multiplication logic...
    return *this;
}

matrixClass& matrixClass::operator+(int a) {
    // Implement addition logic...
    return *this;
}

matrixClass& matrixClass::operator*(int a) {
    // Implement multiplication logic...
    return *this;
}

// The remaining operators should be implemented similarly...

std::ostream& operator<<(std::ostream& o, const matrixClass& m) {
    for (int i = 0; i < m.n; ++i) {
        for (int j = 0; j < m.n; ++j) {
            o << m.data[i][j] << " ";
        }
        o << std::endl;
    }
    return o;
}

bool matrixClass::operator==(const matrixClass& m) const {
    if (n != m.n) return false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (data[i][j] != m.data[i][j]) return false;
        }
    }
    return true;
}

bool matrixClass::operator>(const matrixClass& m) const {
    // Implement comparison logic...
    return false;
}

bool matrixClass::operator<(const matrixClass& m) const {
    // Implement comparison logic...
    return false;
}