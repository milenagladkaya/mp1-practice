#include "Matrix.h"
#include "Exception.h"
#include <iostream>
#include <cstring>
using namespace std;

Matrix::Matrix()
{
    x = 0;
    y = 0;
    memset(&m[x * y], 0.0, sizeof(m[x * y]));
}

Matrix::Matrix(int _x, int _y)
{
    x = _x;
    y = _y;
    m = new double[_x * _y];
    memset(&m[_x * _y], 0.0, sizeof(m[_x * _y]));
}

Matrix::Matrix(int _x, int _y, double *_m)
{
    x = _x;
    y = _y;
    m = new double[_x * _y];
    for (int i = 0; i < _x * _y; i++)
        memcpy(&m[i], &_m[i], sizeof(m[i]));

}

Matrix::Matrix(const Matrix& _m)
{
    x = _m.x;
    y = _m.y;
    m = new double[x * y];
    for (int i = 0; i < (x * y); i++)
        memcpy(&m[i], &_m.m[i], sizeof(m[i]));

}

Matrix::~Matrix()
{
    x = 0;
    y = 0;
    //delete[] m;

}


const Matrix& Matrix::operator= (const Matrix& _m)
{
    if (*this != _m) {
        x = _m.x;
        y = _m.y;
        for (int i = 0; i < x * y; i++)
            memcpy(&m[i], &_m.m[i], sizeof(m[i]));
    }
    return *this;
}

bool Matrix:: operator!= (const Matrix& _m)
{
    for (int i = 0; i < (x * y); i++)
    {
        if (m[i] != _m.m[i])
            return true;
    }
    return false;
}

Matrix Matrix::operator+ (const Matrix& _m)
{
    if ((x != _m.x) || (y != _m.y))
        throw Error1();
    Matrix C(*this);
    for (int i = 0; i < (x * y); i++)
        C.m[i] += _m.m[i];
    return C;
}

Matrix Matrix::operator- (const Matrix& _m)
{
    if ((x != _m.x) || (y != _m.y))
        throw Error1();
    Matrix C(*this);
    for (int i = 0; i < (x * y); i++)
        C.m[i] -= _m.m[i];
    return C;
}

Matrix Matrix::operator* (const Matrix& _m)
{
    if (x != _m.y)
        throw Error2();
    Matrix C(_m.x, y);
    for (int i = 0; i < y * _m.x; i++)
        C.m[i] = 0.0;
    for (int i = 0; i < y; i++)
        for (int j = 0; j < _m.x; j++)
            for (int k = 0; k < x; k++)
                C.m[i * _m.x + j] += (m[i * x + k] * _m.m[k * _m.x + j]);
    return C;
}

Matrix Matrix::operator+ (double dig)
{
    Matrix C(*this);
    for (int i = 0; i < (x * y); i++)
        C.m[i] += dig;
    return C;
}
Matrix Matrix::operator- (double dig)
{
    Matrix C(*this);
    for (int i = 0; i < (x * y); i++)
        C.m[i] -= dig;
    return C;
}

Matrix Matrix::operator* (double dig)
{
    Matrix C(*this);
    for (int i = 0; i < (x * y); i++)
        C.m[i] *= dig;
    return C;
}

Matrix& Matrix::operator+= (const Matrix& _m)
{
    if ((x != _m.x) || (y != _m.y))
        throw Error1();
    for (int i = 0; i < (x * y); i++)
        m[i] += _m.m[i];
    return *this;
}

Matrix& Matrix::operator-= (const Matrix& _m)
{
    if ((x != _m.x) || (y != _m.y))
        throw Error1();
    for (int i = 0; i < (x * y); i++)
        m[i] -= _m.m[i];
    return *this;
}

Matrix& Matrix::operator+= (double dig)
{
    for (int i = 0; i < (x * y); i++)
        m[i] += dig;
    return *this;
}
Matrix& Matrix::operator-= (double dig)
{
    for (int i = 0; i < (x * y); i++)
        m[i] -= dig;
    return *this;
}
Matrix& Matrix::operator*= (double dig)
{
    for (int i = 0; i < (x * y); i++)
        m[i] *= dig;
    return *this;
}

double* Matrix::operator[] (int idx)
{
    if (idx < 0 || idx >= y)
        throw Error3();
    return m + x * idx;
}

void Matrix::Fill()
{
    for (int i = 0; i < x * y; i++) {
        while ((cout << i << "-й элемент = ") && (!(cin >> m[i]))) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Вы ввели символ. Введите число." << endl;
        };
    }
}

void Matrix::Print()
{
    for (int i = 0; i < x * y; i++)
    {
        if (i % (x) == 0)
            cout << endl;
        cout << m[i] << " ";
    }
    cout << "\n----------------------------------" << endl;
}

void Input(int *x, int *y)
{
    do {
        while ((cout << "\nКоличество столбцов: ") && (!(cin >> *x)))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Вы ввели символ. Введите число." << endl;
        };
        if (*x < 1)
            cout << "Число должно быть больше 0. Попробуйте ввести ещё раз." << endl;

    } while (*x < 1);

    do {
        while ((cout << "Количество строк: ") && (!(cin >> *y)))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Вы ввели символ. Введите число." << endl;
        };
        if (*y < 1)
            cout << "Число должно быть больше 0. Попробуйте ввести ещё раз." << endl;
    } while (*y < 1);
}

void Menu()
{
    cout << "\nДля того чтобы выбрать операцию, которую вы хотите провести над матрицами" << endl;
    cout << "введите соответвсвующий номер операции из указанных ниже:" << endl;
    cout << "1 - С = A + B" << "       " << "7 - A += B" << endl;
    cout << "2 - C = A - B" << "       " << "8 - A -= B" << endl;
    cout << "3 - C = A * B" << "       " << "9 - A += dig" << endl;
    cout << "4 - C = A + dig" << "     " << "10 - A -= dig" << endl;
    cout << "5 - C = A - dig" << "     " << "11 - A *= dig" << endl;
    cout << "6 - C = A * dig" << endl;
}
double Digital()
{
    double d;
    cout << "Введите число" << endl;
    while (!(cin >> d))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Вы ввели символ. Введите число." << endl;
    };
    return d;
}

const char* Error1::what() const
{
    return what_str.c_str();
}

const char* Error2::what() const
{
    return what_str.c_str();
}

const char* Error3::what() const
{
    return what_str.c_str();
}

