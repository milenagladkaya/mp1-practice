#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include<locale.h>
void main() {
	double x1, y1, r1, x2, y2, r2, o1o2, rs, rr;
	setlocale(LC_ALL, "Russian");
	printf("������� ���������� ������ ������ ���������� � � ������\n");
	printf("x1 = ");
	scanf("%lf", &x1);
	printf("y1 = ");
	scanf("%lf", &y1);
	printf("r1 = ");
	scanf("%lf", &r1);
	if (r1 < 0) {
		printf("������ ������ ���� �������������");
		return;
	}

	printf("������� ���������� ������ ������ ���������� � � ������\n");
	printf("x2 = ");
	scanf("%lf", &x2);
	printf("y2 = ");
	scanf("%lf", &y2);
	printf("r2 = ");
	scanf("%lf", &r2);
	if (r2 < 0) {
		printf("������ ������ ���� �������������");
		return;
	}

	o1o2 = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	rs = r1 + r2;
	rr = abs(r1 - r2);

	if ((x1 = x2) && (y1 == y2) && (r1 == r2)) {
		printf("���������� ���������");
		return;
	}

	if (o1o2 == rs) {
		printf("������� ������� �����������");
		return;
	}

	if ((o1o2 == rr) && (r1 != r2)) {
		printf("���������� ������� �����������");
		return;
	}

	if ((o1o2 < rr) && (o1o2 != 0)) {
		printf("���������� �� ������������. ���� ��������� ������ ������");
		return;
	}

	if (o1o2 > rs) {
		printf("���������� �� ������������. ��� ����������� �� ���������� ���� �� �����");
		return;
	}
	printf("���������� ������������ � ���� ������");

	system("pause");
}

