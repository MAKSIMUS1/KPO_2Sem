#include "stdafx.h"

using namespace std;

int sum(int x, int y);
int sub(int x, int y);
int mul(int x, int y);

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b;
	printf("Введите a:");
	scanf_s("%d", &a);
	printf("Введите b:");
	scanf_s("%d", &b);
	printf("Сумма a + b:%d\n", sum(a, b));
	printf("Разность a - b:%d\n", sub(a, b));
	printf("Произведение a * b:%d\n", mul(a, b));

	system("pause");
	return 0;
}
