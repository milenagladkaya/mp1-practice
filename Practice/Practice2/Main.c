#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void main() {
    int mode, number, guess, k = 0, a = 1, b = 1000;
    char moreorless;
    printf("Choose game mode. Enter 1 or 2\n");
    do {
        scanf("%d", &mode);
    } while (mode != 1 && mode != 2);


    switch (mode) {
    case 1: {
        srand((unsigned int)time(0));
        number = rand() * b / RAND_MAX + a;
        printf("The number is made. It ranges from 1 to 1000. Try to guess it.\n");
        do {
            do {
                scanf("%d", &guess);
            } while (guess < a || guess > b);
            if (number > guess) {
                printf("The number is bigger\n");
            }
            else if (number < guess) {
                printf("The number is smaller\n");
            }
            k++;
        } while (number != guess);
        printf("You guessed the number of %d attempts\n", k);
        break;
    }
    case 2: {
        printf("Make a number from 1 to 1000\n");
        do {
            scanf("%d", &number);
        } while (number < a || number > b);
        printf("At the computer's attempts to guess the number, you can enter only '<' or '>'\n");
        //k = 1;
        do {
            guess = (b + a) / 2;
            printf("%d\n", guess);
            k++;
            if (guess == number) {
                break;
            }
            do {
                scanf("%c", &moreorless);
            } while ((moreorless != '<') && (moreorless != '>'));
            if (moreorless == '>') {
                a = guess;
            }
            else if (moreorless == '<') {
                b = guess;
            }
        } while (guess != number);
        printf("The computer guessed your number from %d attempts.", k);
        break;
    }

    }

    system("pause");
}
