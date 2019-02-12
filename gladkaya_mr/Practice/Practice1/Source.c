#include <stdio.h>
#include <math.h>
#include <locale.h>

void main() {

    float pDVP, pDSP, wood, w, h, d, massa;
    setlocale(LC_ALL, "Russian");
    printf("Введите плотность ДВП в кг/м^3\n");
    scanf("%f", &pDVP);
    printf("Введите плотность ДCП в кг/м^3\n");
    scanf("%f", &pDSP);
    printf("Введите плотность дерева в кг/м^3\n");
    scanf("%f", &wood);

    printf("Введите h в см (высота задней накладной стенки)\n");
    do {
        scanf("%f", &h);
    } while (h < 180 || h > 220);
    h /= 100.0f;
    printf("Введите w в см (ширина задней накладной стенки)\n");
    do {
        scanf("%f", &w);
    } while (w < 80 || w > 120);
    w /= 100.0f;
    printf("Введите d в см (глубина боковин)\n");
    do {
        scanf("%f", &d);
    } while (d < 50 || d > 90);
    d /= 100.0f;

    float backwall, sidewall, top, door, shelf;
    backwall = pDVP * h * w * 0.005;
    sidewall = pDSP * h * d * 0.015;
    top = pDSP * w * d * 0.015;
    door = wood * h * w * 0.01;
    shelf = pDSP * d * w * 0.01;
    int n = ceil(h / 0.4) - 1;
    massa = backwall + 2 * sidewall + 2 * top + 2 * door + n * shelf;
    printf("масса шкафа = %f", massa);

    system("pause");

}




        
