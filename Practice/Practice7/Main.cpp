#include "Vector.h"
#include "Exception.h"
#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
    int d1 = 0, d2 = 0, c;
    setlocale(LC_ALL, "Russian");

    cout << "Введите размерность вектора v1: ";
    Input(&d1);
    Vector v1(d1);
    cout << "Введите ккординаты вектора v1:" << endl;
    v1.Fill();
    cout << "|v1| = ";
    v1.Length();

    cout << "Введите размерность вектора v2: ";
    Input(&d2);
    Vector v2(d2);
    cout << "Введите ккординаты вектора v2:" << endl;
    v2.Fill();
    cout << "|v2| = ";
    v2.Length();
    Vector v(d1);

    do {
        int n;
        Menu();
        do {
            cin >> n;
            if ((n < 1) || (n > 13))
                cout << "Операции с таким номером нет. Попробуйте ввести ещё раз." << endl;
        } while ((n < 1) || (n > 13));
        double dig;
        switch (n)
        {
        case 1:
        {
            try {
                v = v1 + v2;
                cout << "v = ( ";
                v.Print();
                cout << ")" << endl;
            }
            catch (Error1 e)
            {
                cout << e.what();
            }
            break;
        }
        case 2:
        {
            try
            {
                v = v1 - v2;
                cout << "v = ( ";
                v.Print();
                cout << ")" << endl;
            }
            catch (Error1 e)
            {
                cout << e.what();
            }
            break;
        }
        case 3:
        {
            try
            {
                double scal = v1 * v2;
                cout << "scal = " << scal << endl;
            }
            catch (Error1 e)
            {
                cout << e.what();
            }
            break;
        }
        case 4:
        {
            dig = Digital();
            v = v1 + dig;
            cout << "v = ( ";
            v.Print();
            cout << ")" << endl;
            break;
        }
        case 5:
        {
            dig = Digital();
            v = v1 - dig;
            cout << "v = ( ";
            v.Print();
            cout << ")" << endl;
            break;
        }
        case 6:
        {
            dig = Digital();
            v = v1 * dig;
            cout << "v = ( ";
            v.Print();
            cout << ")" << endl;
            break;
        }
        case 7:
        {
            try
            {
                v1 += v2;
                cout << "v1 = ( ";
                v1.Print();
                cout << ")" << endl;
            }
            catch (Error1 e)
            {
                cout << e.what();
            }
            break;
        }
        case 8:
        {
            try
            {
                v1 -= v2;
                cout << "v1 = ( ";
                v1.Print();
                cout << ")" << endl;
            }
            catch (Error1 e)
            {
                cout << e.what();
            }
            break;
        }
        case 9:
        {
            try
            {
                v1 *= v2;
                cout << "v1 = ( ";
                v1.Print();
                cout << ")" << endl;
            }
            catch (Error1 e)
            {
                cout << e.what();
            }
            break;
        }
        case 10:
        {
            dig = Digital();
            v1 += dig;
            cout << "v1 = ( ";
            v1.Print();
            cout << ")" << endl;
            break;
        }
        case 11:
        {
            dig = Digital();
            v1 -= dig;
            cout << "v1 = ( ";
            v1.Print();
            cout << ")" << endl;
            break;
        }
        case 12:
        {
            dig = Digital();
            v1 *= dig;
            cout << "v1 = ( ";
            v1.Print();
            cout << ")" << endl;
            break;
        }
        case 13:
        {
            try {
                int i;
                cout << "Введите индекс: ";
                cin >> i;
                cout << "v1[" << i << "] = " << v1[i] << endl;
            }
            catch (Error2 e)
            {
                cout << e.what();
            }
        }
        }
        cout << "Если вы хотите сделать ещё какие-то действия с векторами, введите 1" << endl;
        cout << "Если нет, любое другое число." << endl;
        cin >> c;
    } while (c == 1);

    system("pause");
}
