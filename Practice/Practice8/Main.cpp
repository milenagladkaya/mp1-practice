#include "Matrix.h"
#include "Exception.h"
#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int x1, y1, x2, y2, a, b, check;


    cout << "Введите размер матрицы A:" << endl;
    Input(&x1, &y1);
    Matrix A(x1, y1);
    A.Fill();
    cout << "Матрица A имеет вид:" << endl;
    A.Print();

newB:
    cout << "\n\nВведите размер матрицы B:" << endl;
    Input(&x2, &y2);
    Matrix B(x2, y2);
    B.Fill();
    cout << "Матрица B имеет вид:" << endl;
    B.Print();

    Matrix C(x1, y1);
    Matrix D(x2, y1);
    do {
        int n;
        Menu();
        do {
            while (!(cin >> n))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "Вы ввели символ. Введите число." << endl;
            };
            if ((n < 1) || (n > 11))
                cout << "Операции с таким номером нет. Попробуйте ввести ещё раз." << endl;
        } while ((n < 1) || (n > 11));
        double dig;
        switch (n)
        {
        case 1:
        {

            try
            {
                C = A + B;
                cout << "\nC = A + B :";
                C.Print();
            }
            catch (Error1)
            {
                cout << "Размеры матриц не совпадают. Если хотите изменить размер матрицы B введите 1, если нет, любое другое число." << endl;
                cin >> b;
                if (b == 1)
                    goto newB;
            }
            break;
        }
        case 2:
        {
            try
            {
                C = A - B;
                cout << "\nC = A - B :";
                C.Print();
            }
            catch (Error1)
            {
                cout << "Размеры матриц не совпадают. Если хотите изменить размер матрицы B введите 1, если нет, любое другое число." << endl;
                cin >> b;
                if (b == 1)
                    goto newB;
            }
            break;
        }
        case 3:
        {
            try
            {
                D = (A * B);
                cout << "\nC = A * B :";
                D.Print();
            }
            catch (Error2)
            {
                cout << "Количество столбцов A не равно количеству строк B." << endl;
                cout << "Если хотите изменить размер матрицы B введите 1, если нет, любое другое число." << endl;
                cin >> b;
                if (b == 1)
                    goto newB;
            }
            break;
        }
        case 4:
        {
            dig = Digital();
            C = A + dig;
            cout << "\nC = A + dig :";
            C.Print();
            break;
        }
        case 5:
        {
            dig = Digital();
            C = A - dig;
            cout << "\nC = A - dig :";
            C.Print();
            break;
        }
        case 6:
        {
            dig = Digital();
            C = A * dig;
            cout << "\nC = A * dig :";
            C.Print();
            break;
        }
        case 7:
        {
            try
            {
                A += B;
                cout << "\nA += B :";
                A.Print();
            }
            catch (Error1)
            {
                cout << "Размеры матриц не совпадают. Если хотите изменить размер матрицы B введите 1, если нет, любое другое число." << endl;
                cin >> b;
                if (b == 1)
                    goto newB;
            }
            break;
        }
        case 8:
        {
            try
            {
                A -= B;
                cout << "\nA -= B :";
                A.Print();
            }
            catch (Error1)
            {
                cout << "Размеры матриц не совпадают. Если хотите изменить размер матрицы B введите 1, если нет, любое другое число." << endl;
                cin >> b;
                if (b == 1)
                    goto newB;
            }
            break;
        }
        case 9:
        {
            dig = Digital();
            A += dig;
            cout << "\nA += dig :";
            A.Print();
            break;
        }
        case 10:
        {
            dig = Digital();
            A -= dig;
            cout << "\nA -= dig :";
            A.Print();
            break;
        }
        case 11:
        {
            dig = Digital();
            A *= dig;
            cout << "\nA *= dig :";
            A.Print();
            break;
        }
        }
        cout << "\nЕсли вы хотите сделать ещё какие-то действия с матрицами, введите 1" << endl;
        cout << "Если нет, любое другое число." << endl;
        cin >> a;
    } while (a == 1);

    system("pause");
}
