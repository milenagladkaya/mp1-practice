#pragma once
#include <iostream>
class Matrix
{
private:
    double *m;
    int x, y;
public:
    Matrix();
    Matrix(int _x, int _y);
    Matrix(int _x, int _y, double *_m);
    Matrix(const Matrix& _m);
    ~Matrix();

    bool operator!= (const Matrix&);
    const Matrix& operator= (const Matrix&);
    Matrix operator+ (const Matrix&);
    Matrix operator- (const Matrix&);
    Matrix operator* (const Matrix&);
    Matrix operator+ (double);
    Matrix operator- (double);
    Matrix operator* (double);
    Matrix& operator+= (const Matrix&);
    Matrix& operator-= (const Matrix&);
    Matrix& operator+= (double);
    Matrix& operator-= (double);
    Matrix& operator*= (double);
    double* operator[] (int);

    void Fill();
    void Print();

};

void Input(int *x, int *y);
void Menu();
double Digital();
