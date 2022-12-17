/*Разработать функцию, проверяющую является ли число положительным.
Реализацию выполнить через лямбда, которое возвращает true (число положительное) false (в противном случае)*/
#include <iostream>
using namespace std;



void main()
{
	setlocale(LC_ALL, "Rus");
	while (true)
	{
		int num; 
		cin >> num;
		if (num == 0) {
			cout << "Ноль ни положительный, ни отрицательный" << endl;
			exit(0);
		}
		else
		{
			auto res = [num] {
				if (num > 0)
					return true;
				if (num < 0)
					return false;
			};
			cout << "Функция вернула: " << res() << endl;
		}
	}
}