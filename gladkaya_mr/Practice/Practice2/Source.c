#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define N 10

void main() {

    int lenght, i, j, z, k, r, s, guess, temp, bull = 0, cow = 0;
    int a[N], b[N];
    setlocale(LC_ALL, "Russian");
    printf("Введите длину загадываемого компьютером числа\n");

    do {
        scanf("%d", &lenght);
    } while (lenght <= 0 || lenght > 10);
    srand((unsigned int)time(0));

    do {
        z = 1;
        k = 0;
        for (i = 0; i < lenght; i++) { //формируем массив из неповторяющихся цифр от 0 до 9
            a[i] = rand() % 10;
        }
        for (i = 1; i < lenght; i++) {
            for (j = 0; j < i; j++) {
                if (a[i] == a[j]) {
                    k++;
                }
            }
        }
        if (a[0] == 0) { //первый элемент не должен быть равен 0
            z = 0;
        }
    } while (z == 0 || k > 0);
    /*printf("загаданное число = ");
    for (i = 0; i < lenght; i++) {
        printf("%d", a[i]);
    }*/
    printf("\nЧисло загадано. Попробуйте его отгадать. Оно содержит только неповторяющиеся цифры.\n");
    
    do {
        cow = 0; bull = 0;
        do {
            r = 0;
            scanf("%d", &guess);
            for (i = 0; i < lenght; i++) { //проверяем длину
                if (((guess % 10) == 0) && ((guess / 10) == 0)) {
                    break;
                }
                b[i] = guess % 10;
                guess /= 10;
                r++;
            }
            s = 0;
            for (i = 1; i < r; i++) { // проверяем повтряющиеся цифры
                for (j = 0; j < i; j++) {
                    if (b[i] == b[j]) {
                        s++;
                    }
                }
            }
        } while (lenght != r || guess != 0 || s != 0);

        for (i = 0; i < lenght / 2; i++) { // переворачиваем массив, чтобы привести его к нормальному виду
            temp = b[i];
            b[i] = b[lenght - 1 - i];
            b[lenght - 1 - i] = temp;
        }

        for (i = 0; i < lenght; i ++) {
            for (j = 0; j < lenght; j++) {
                if (a[i] == b[j]) {
                    cow++;
                    if (i == j) {
                        bull++;
                    }
                }
            }
        }
        printf("количество коров  = %d\n", cow);
        printf("количество быков  = %d\n", bull);
    } while (bull != lenght);
    printf("Вы выиграли! Поздравляем!");
    
    system("pause");
}