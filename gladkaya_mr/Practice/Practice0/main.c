#include <stdio.h>
#include <math.h>
#include<locale.h>
 void main() {
 	double x1, y1, r1, x2, y2, r2, o1o2, rs, rr;
	setlocale(LC_ALL, "Russian");
 	printf("������� ���������� ������ ������ ���������� � � ������\n");
	printf("x1 = ");
	scanf_s("%lf", &x1);
	printf("y1 = ");
	scanf_s("%lf", &y1);
	printf("r1 = ");
	scanf_s("%lf", &r1);
	if (r1 < 0) {
		printf("������ ������ ���� �������������");
		return;
	}
	else {
		printf("������� ���������� ������ ������ ���������� � � ������\n");
		printf("x2 = ");
		scanf_s("%lf", &x2);
		printf("y2 = ");
		scanf_s("%lf", &y2);
		printf("r2 = ");
		scanf_s("%lf", &r2);
		if (r2 < 0) {
			printf("������ ������ ���� �������������");
			return;
		}
 		else {
			o1o2 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
			rs = r1 + r2;
			rr = abs(r1 - r2);
 			//1 ������
			if ((x1 = x2) && (y1 == y2) && (r1 == r2)) {
				printf("���������� ���������");
				return;
			}
			// 2 ������
			if ((rr < o1o2) && (rs > o1o2)) {
				printf("���������� ������������ � ���� ������");
				return;
			}
			// 3 ������
			if (o1o2 == rs) {
				printf("������� ������� �����������");
				return;
			}
			// 4 ������
			if ((o1o2 == rr) && (r1 != r2)) {
				printf("���������� ������� �����������");
				return;
			}
			//5 ������
			if ((o1o2 < rr) && (o1o2 != 0)) {
				printf("���������� �� ������������. ���� ��������� ������ ������");
				return;
			}
			//6 ������
			if (o1o2 > rs) {
				printf("���������� �� ������������. ��� ����������� �� ���������� ���� �� �����");
				return;
			}
			//7 ������
			if ((o1o2 == 0) && (r1 != r2)) {
				printf("��� ��������������� ����������");
				return;
			}
 		}
	}
	system("pause");
} 
