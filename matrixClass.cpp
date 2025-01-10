#include "matrixClass.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Default constructor
matrixClass::matrixClass() : n(0), data(0) {}

// Parameterized constructor
matrixClass::matrixClass(int n) : n(n) {
    data = new int* [n];
    for (int i = 0; i < n; ++i) {
        data[i] = new int[n];
    }
}

// Parameterized constructor with array
matrixClass::matrixClass(int n, int* t) : n(n) {
    if (t == nullptr) {
        throw std::invalid_argument("Input array cannot be null");
    }

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
    if (n != m.n) {
        throw std::invalid_argument("Matrices must be of the same size for addition");
    }

    matrixClass* result = new matrixClass(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result->data[i][j] = data[i][j] + m.data[i][j];
        }
    }
    return *result;
}

matrixClass& matrixClass::operator*(const matrixClass& m) {
    if (n != m.n) {
        throw std::invalid_argument("Matrices must be of the same size for multiplication");
    }

    matrixClass* result = new matrixClass(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result->data[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                result->data[i][j] += data[i][k] * m.data[k][j];
            }
        }
    }
    return *result;
}

matrixClass& matrixClass::operator+(int a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] += a;
        }
    }
    return *this;
}

matrixClass& matrixClass::operator*(int a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] *= a;
        }
    }
    return *this;
}


matrixClass& matrixClass::operator-(int a) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			data[i][j] -= a;
		}
	}
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
    if (n != m.n) {
        throw std::invalid_argument("Matrices must be of the same size for comparison");
    }

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum1 += data[i][j];
            sum2 += m.data[i][j];
        }
    }
    return sum1 > sum2;
}

bool matrixClass::operator<(const matrixClass& m) const {
    if (n != m.n) {
        throw std::invalid_argument("Matrices must be of the same size for comparison");
    }

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum1 += data[i][j];
            sum2 += m.data[i][j];
        }
    }
    return sum1 < sum2;
}






matrixClass& matrixClass::operator++(int) {
    matrixClass temp = *this; // Make a copy of the current state
    for (int i = 0; i < n*n; ++i) {
        data[i]++;
    }
    return temp;
}

// Post-decrement operator
matrixClass& matrixClass::operator--(int) {
    matrixClass temp = *this; // Make a copy of the current state
    for (int i = 0; i < n * n; ++i) {
        data[i]--;
    }
    return temp;
}
matrixClass operator*(int a, const matrixClass& m) {
    matrixClass result(m);
    for (int i = 0; i < result.n; ++i) {
        for (int j = 0; j < result.n; ++j) {
            result.data[i][j] *= a;
        }
    }
    return result;
}
matrixClass operator-(int a, const matrixClass& m) {
    matrixClass result(m.n);
    for (int i = 0; i < m.n; ++i) {
        for (int j = 0; j < m.n; ++j) {
            result.data[i][j] = a - m.data[i][j];
        }
    }
    return result;
}
// Ustawia wartoœci na przek¹tnej macierzy
matrixClass& matrixClass::diagonalna(int* t) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                data[i][j] = t[i];
            }
            else {
                data[i][j] = 0;
            }
        }
    }
    return *this;
}


// Ustawia wartoœci na k-tej przek¹tnej macierzy
matrixClass& matrixClass::diagonalna_k(int k, int* t) {
    if (k >= 0) {
        for (int i = 0; i < n - k; ++i) {
            data[i][i + k] = t[i];
        }
    }
    else {
        for (int i = 0; i < n + k; ++i) {
            data[i - k][i] = t[i];
        }
    }
    return *this;
}

// Ustawia wartoœci w kolumnie x
matrixClass& matrixClass::kolumna(int x, int* t) {
    for (int i = 0; i < n; ++i) {
        data[i][x] = t[i];
    }
    return *this;
}

// Ustawia wartoœci w wierszu y
matrixClass& matrixClass::wiersz(int y, int* t) {
    for (int i = 0; i < n; ++i) {
        data[y][i] = t[i];
    }
    return *this;
}

// Ustawia wartoœci na przek¹tnej macierzy na 1, resztê na 0
matrixClass& matrixClass::przekatna() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = (i == j) ? 1 : 0;
        }
    }
    return *this;
}

// Ustawia wartoœci pod przek¹tn¹ macierzy na 1, resztê na 0
matrixClass& matrixClass::pod_przekatna() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = (i > j) ? 1 : 0;
        }
    }
    return *this;
}

// Ustawia wartoœci nad przek¹tn¹ macierzy na 1, resztê na 0
matrixClass& matrixClass::nad_przekatna() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = (i < j) ? 1 : 0;
        }
    }
    return *this;
}

// Ustawia wartoœci w macierzy w formie szachownicy
matrixClass& matrixClass::szachownica() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = (i + j) % 2;
        }
    }
    return *this;
}


matrixClass operator+(int a, const matrixClass& m) {
    matrixClass result(m);
    for (int i = 0; i < result.n; ++i) {
        for (int j = 0; j < result.n; ++j) {
            result.data[i][j] += a;
        }
    }
    return result;
}
// Operator -= implementation
matrixClass& matrixClass::operator-=(int a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] -= a;
        }
    }
    return *this;
}

// Operator *= implementation
matrixClass& matrixClass::operator*=(int a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] *= a;
        }
    }
    return *this;
}

// Operator = implementation
matrixClass& matrixClass::operator=(double a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = static_cast<int>(a); // Casting double to int
        }
    }
    return *this;
}



