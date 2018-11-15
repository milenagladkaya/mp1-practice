#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define N 10

void main() {
    int mode, number, guess, k = 0, a = 1, b = 1000;
    char moreorless;
    setlocale(LC_ALL, "Russian");
    printf("Выберете режим игры. Введите 1 или 2\n");
    do {
        scanf_s("%d", &mode);
    } while (mode != 1 && mode != 2);
    
    
    switch (mode) {
    case 1: {
        srand((unsigned int)time(0));
        number = rand() * b / RAND_MAX + a; 
        printf("Число загадано. Оно находится в диапазоне от 1 до 1000. Попытайтесь его отгадать.\n");
        do {
            do {
                scanf_s("%d", &guess);
            } while (guess < a || guess > b);
            if (number > guess) {
                printf("Загаданное число больше\n");
            }
            else if(number < guess) {
                printf("Загаданное число меньше\n");
            }
            k++;
        } while (number != guess);
        printf("Вы угадали число с %d попыток\n", k);
        break;
    }
    case 2: {
        printf("Загадайте число от 1 до 1000\n");
        do {
            scanf_s("%d", &number);
        } while (number < a || number > b);
        printf("На попытки компьютера отгадать число вы можете вводить только '<' или '>'\n");
        //k = 1;
        do{
                guess = (b + a) / 2;
                printf("%d\n", guess);
                k++;
                if (guess == number) {
                    break;
                }
                do {
                    scanf_s("%c", &moreorless);
                } while ((moreorless != '<') && (moreorless != '>'));
                if (moreorless == '>') {
                    a = guess;
                }
                else if (moreorless == '<') {
                    b = guess;
                } 
        } while (guess != number);
            printf("Компьютер отгадал ваше число с %d попыток", k);
            break;
    }
            
    }

    system("pause");
}