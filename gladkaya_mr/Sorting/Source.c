#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define K 999

void input(int a[], int n) {
    int i;
    srand((unsigned int)time(0));
    for (i = 0; i < n; i++) {
        a[i] = rand() * 1000 / RAND_MAX;
    }
}

void output(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void sortingbychoice(int a[], int n) {
    int i, j, min, minindex;
    for (i = 0; i < n; i++) {
        min = a[i];
        minindex = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < min) {
                min = a[j];
                minindex = j;
            }
        }
        a[minindex] = a[i];
        a[i] = min;
    }
}

void sortinginserts(int a[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        j = i - 1;
        temp = a[i];
        while ((j >= 0) && (a[j] > temp)) {
            a[j + 1] = a[j];
            a[j] = temp;
            j--;
        }
    }
}

void bubblesorting(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 1; j < n - i; j++) {
            if (a[j - 1] > a[j]) {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}

void sortingbycount(int a[], int n) {
    int count[K];
    int i, j, b = 0;
    for (i = 0; i < K; i++) {
        count[i] = 0;
    }
    for (i = 0; i < n; i++) {
        count[a[i]]++;
    }
    for (i = 0; i < K; i++) {
        for (j = 0; j < count[i]; j++) {
            a[b] = i;
            b++;
        }
    }
}

void main() {
    int a[N];
    int numberofsorting, k = 0;
    printf("Source array:\n");
    input(a, N);
    output(a, N);
    printf("\nYou have to choose a number of an array sorting method in ascending order.\n");
    printf(" 1 - sorting by choice\n 2 - sorting inserts\n 3 - bubble sorting\n 4 - sorting by count\n");
    do {
        if (k > 0) {
            printf("There is no such number\n");
        }
        scanf("%d", &numberofsorting);
        k++;
    } while (numberofsorting < 1 || numberofsorting > 4);
    switch (numberofsorting) {
    case 1: {
        sortingbychoice(a, N);
        output(a, N);
        break;
    }
    case 2: {
        sortinginserts(a, N);
        output(a, N);
        break;
    }
    case 3: {
        bubblesorting(a, N);
        output(a, N);
        break;
    }
    case 4: {
        sortingbycount(a, N);
        output(a, N);
        break;
    }
    }

    system("pause");
}