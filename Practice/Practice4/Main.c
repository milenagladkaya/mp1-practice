#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 15

void discountfunction(int discount[], int n) {
    srand((unsigned int)time(0));
    int i;
    for (i = 0; i < n; i++) {
        discount[i] = rand() % 50 + 1;
    }
}

void pricewithdiscount(int p[], int np[], int d[], int n) {
    int z;
    for (z = 0; z < n; z++) {
        np[z] = rint((float)p[z] * (1.0f - (float)d[z] / 100.0f));
    }
}

int barcodefunction(char barcode[][5], int n) {
    char bc[30];//it is stock of digits if user enters bar code incorrectly
    int i, k = 0, lenght = 0, j = 0;
    while (k == 0) {
        do {
            k = 0;
            gets(bc);
            lenght = strlen(bc);
            if (lenght != 4) {
                printf("Bar code can consist only 4 numbers.\n");
            }
        } while (lenght != 4);
        for (i = 0; i < n + 1; i++) {
            if ((barcode[i][0] == bc[0]) && (barcode[i][1] == bc[1]) && (barcode[i][2] == bc[2]) && (barcode[i][3] == bc[3])) {
                if (i == 15) {
                    k = 1;
                }
                else {
                    k = 2;
                }
                return (i);
            }
        }
        if (k == 0) {
            printf("There is no such bar code. Try to enter barcode again.\n");
        }
    }
}

int gooddescriptionoutput(char barc[][5], int n, int a[], int M, char gd[][N], int prc[], int disc[], int nprc[]) {
    int bc, z = 0;
    printf("- - - - -\nStart barcode scanning:\n");
    do {
        bc = barcodefunction(barc, n);
        if (bc != 15) {
            a[z] = bc;
            z++;
            M++;
            printf("%s - %d ruble - discount %d%% - price with discount: %d ruble\n", gd[bc], prc[bc], disc[bc], nprc[bc]);
        }
        if (bc == 15 && z == 0) {
            printf("You have to buy at least one good.\n");
            bc = 16;
        }
    } while (bc != 15);
    printf("The end of the barcode scanning.\n");
    return (M);
}

void amountofgoods(int a[], int b[], int M) {
    int z, h;
    for (z = 0; z < M; z++) {
        b[a[z]] = 1; //we put 1 into "scanned goods"
    }
    for (z = 1; z < M; z++) {
        for (h = 0; h < z; h++) {
            if (a[z] == a[h]) {
                b[a[z]]++;
            }
        }
    }
}

void check(char gd[][N], int np[], int p[], int pc[], int k) {
    int i = 0;
    float totalcostwithd = 0, totalcostcwithoutd = 0, d = 0;
    printf("-------------Check:-------------\n");
    for (i; i < k; i++) {
        if (p[i] != 0) {
            printf("%s - %d ruble - %d good(s) - %d ruble\n", gd[i], np[i], p[i], np[i] * p[i]);
            totalcostwithd += np[i] * p[i];
            totalcostcwithoutd += pc[i] * p[i];
        }
    }
    d = rint(100.0f - ((totalcostwithd / totalcostcwithoutd) * 100.0f));
    printf("---------------------------------\n");
    printf("cost without discount: %0.f ruble\ntotal discount %.0f%%\n---------------------------------\nTOTAL COST: %.0f ruble\n", totalcostcwithoutd, d, totalcostwithd);
}

void main() {
    int M = 0;
    char barcode[N + 1][5] = { "0001", "0002", "0003", "0004", "0005", "0006", "0007", "0008", "0009", "0010", "0011", "0012", "0013", "0014", "0015", "0000" };
    char goods[N][N] = { "potato", "cucumber", "tomato", "pasta", "chicken", "beef", "pork", "water", "juice", "milk", "sausages", "dumplings", "chocolate", "tea", "coffee" };
    int price[N] = { 45, 150, 250, 130, 100, 270, 300, 35, 50, 55, 200, 200, 80, 120, 150 };
    int newprice[N], discount[N], b[N] = { 0 }/*element of array - a number of scanned goood with this index*/, a[100]/*array contains indices of scanned goods*/;
    discountfunction(discount, N);
    pricewithdiscount(price, newprice, discount, N);
    printf("1) Our shop has only 15 gooods.\n2) Every of them has bar code from 0001 to 0015.\n3) When you finish to scan bar code of goods, enter 0000.\n");
    M = gooddescriptionoutput(barcode, N, a, M, goods, price, discount, newprice);
    amountofgoods(a, b, M);
    check(goods, newprice, b, price, N);
    system("pause");
}
