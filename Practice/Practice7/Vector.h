#pragma once
class Vector
{
private:
    int dim;
    double *x;
public:
    Vector(); //по умолчвнию
    Vector(int _dim); //с параметром
    Vector(const Vector& v); //копирования
    ~Vector();//деструктор


    const Vector& operator= (const Vector&);
    Vector operator+ (const Vector&);
    Vector operator- (const Vector&);
    double operator* (const Vector&);
    Vector operator+ (double);
    Vector operator- (double);
    Vector operator* (double);
    Vector& operator+= (const Vector&);
    Vector& operator-= (const Vector&);
    Vector& operator*= (const Vector&);
    Vector& operator+= (double);
    Vector& operator-= (double);
    Vector& operator*= (double);
    double& operator[] (int);
    const double& operator[] (int) const;

    void Length();
    void Fill();
    void Print();

};
void Input(int *d);
void Menu();
double Digital();
