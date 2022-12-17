#include <iostream>

using namespace std;

void Leary_Year(int);
int Count_Day(int, int, int);
int Correct_Day();
int Correct_Input_Integer();
void Day_Program(int);
void which_month(int);

int main()
{
	setlocale(LC_ALL, "RU");
	int year1, month1, day1, year2, month2, day2, SUM1, SUM2, kol = 0, pr = 0, data1 = 0, data2;
	char d2[50];
	printf("Текущая дата.\n");
	data1 = Correct_Day();//Ввод текущего дня
	year1 = data1 % 10000;
	month1 = (data1 / 10000) % 100;
	day1 = data1 / 1000000;

	printf("Дата рождения.\n");
	data2 = Correct_Day();//Ввод дня рождения
	year2 = data2 % 10000;
	month2 = (data2 / 10000) % 100;
	day2 = data2 / 1000000;
	printf("День: %d\tМесяц: %d\tГод: %d\n", day1, month1, year1);
	printf("День: %d\tМесяц: %d\tГод: %d\n", day2, month2, year2);
	Leary_Year(year1);
	SUM1 = Count_Day(year1, month1, day1);
	SUM2 = Count_Day(year2, month2, day2);
	if (SUM2 > SUM1)
	{
		kol = SUM2 - SUM1;
	}
	else
	{
		kol = 365 - (SUM1 - SUM2);
	}
	printf("\nПорядковый номер текущего дня в году: %d\n", SUM1);
	printf("Дней до Дня Рождения: %d\n", kol);
	printf("Введите год: ");
	int day_progr;
	day_progr = Correct_Input_Integer();
	Day_Program(day_progr);
	which_month(month1);
}
void which_month(int month) {
	printf("Текущий месяц ");
	if (month == 1)
		printf("январь.\n");
	if (month == 2)
		printf("февраль");
	if (month == 3)
		printf("март");
	if (month == 4)
		printf("апрель");
	if (month == 5)
		printf("май");
	if (month == 6)
		printf("июнь");
	if (month == 7)
		printf("июль");
	if (month == 8)
		printf("август");
	if (month == 9)
		printf("сентябрь");
	if (month == 10)
		printf("октябрь");
	if (month == 11)
		printf("ноябрь");
	if (month == 12)
		printf("декабрь");
}
void Day_Program(int year) {
	if (year % 4 == 0 && year % 100 != 0)
		printf("В %d году день программиста 12 сентября.\n", year);
	else
		printf("В %d году день программиста 13 сентября.\n", year);
}

void Leary_Year(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		printf("Текущий год високосный.");
	else
		printf("Текущий год не високосный.");
}

int Count_Day(int year, int month, int day)
{
	int sum = 0;
	for (int i = 1; i <= month; i++)
	{
		if (i == month)
		{
			for (int j = 0; j < day; j++)
			{
				sum++;
			}
			break;
		}
		if (i == 2 && i != month)
		{
			if (year % 4 == 0 && year % 100 != 0)
			{
				for (int j = 0; j < 29; j++)
				{
					sum++;
				}
			}
			else
			{
				for (int j = 0; j < 28; j++)
				{
					sum++;
				}
			}
		}
		if (i % 2 == 0 && i != 2 && i != month)
		{
			for (int j = 0; j < 30; j++)
			{
				sum++;
			}
		}
		if (i % 2 != 0 && i != month)
		{
			for (int j = 0; j < 31; j++)
			{
				sum++;
			}
		}
	}
	return sum;
}

int Correct_Day()
{
	setlocale(LC_ALL, "RU");
	int year, month, day;
	bool proverka = true;
	char data[50];
	int data_int = 0;
	while (proverka)
	{
		printf("Введите дату в формате ДДММГГГГ: ");
		gets_s(data);
		if (data[8] == '\0')
		{
			if ((data[0] >= '0' || data[0] < '4') &&
				(data[1] >= '0' || data[1] <= '9') &&
				(data[2] >= '0' || data[2] < '1') &&
				(data[3] >= '0' || data[3] <= '9') &&
				(data[4] >= '0' || data[4] <= '9') &&
				(data[5] >= '0' || data[5] <= '9') &&
				(data[6] >= '0' || data[6] <= '9') &&
				(data[7] >= '0' || data[7] <= '9'))
			{
				data_int = atoi(data);
				if (data_int >= 1010001 && data_int <= 31129999)
				{
					year = data_int % 10000;
					month = (data_int / 10000) % 100;
					day = data_int / 1000000;
					if (month < 13 && month > 0)
					{
						if (year % 4 == 0 && year % 100 != 0)
						{
							if ((month == 2 && day < 30) || (month % 2 == 0 && month != 2 && day < 31) || (month % 2 == 1 && day < 32))
							{
								proverka = false;
							}
							else
								printf("Некорректная дата\n");
						}
						else
						{
							if ((month == 2 && day < 29) || (month % 2 == 0 && month != 2 && day < 31) || (month % 2 == 1 && day < 32))
							{
								proverka = false;
							}
							else
								printf("Некорректная дата\n");
						}
					}
					else
						printf("Некорректная дата\n");
				}
				else
					printf("Некорректная дата\n");
			}
		}
		else
			printf("Некорректная дата\n");
	}
	return data_int;
}
//Корректный ввод integer
int Correct_Input_Integer() {
	int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
	char ch[11];

	while (proverka != 1) //Если proverka_na_minus = 1, значит первый символ минус. Если proverka_na_minus = 2, значит первый символ число.Если
	{ //Если proverka_2 = 1, значит ввод неверный.
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(ch);//Если proverka_2 = 0, значит ввод верный и мы заканчиваем цикл и переводим в int.
		if (ch[0] == '-')
			proverka_na_minus = 1;
		else
			if (ch[0] >= '0' && ch[0] <= '9')
				proverka_na_minus = 2;
			else
				proverka_2 = 1;
		if (proverka_na_minus == 1)//Если первый символ минус, то тогда идет проверка каждого символа
			for (int i = 1; i < strlen(ch); i++) {
				if (ch[i] <= '0' || ch[i] >= '9') {
					proverka_2 = 1;
				}
				if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
					proverka_2 = 0;
				}
			}
		if (proverka_na_minus == 2)//Если первый символ число, то тогда проперка всего числа
			for (int i = 0; i < strlen(ch); i++) {
				if (ch[i] <= '0' || ch[i] >= '9') {
					proverka_2 = 1;
				}
				if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
					proverka_2 = 0;
				}
				if (ch[i] == '\n')
					break;
			}
		cin.clear();
		proverka_na_minus = 0;
		if (proverka_2 == 1)
			printf("Неверный ввод!\nВведите ещё раз: ");
		if (proverka_2 == 0)
			proverka = 1;
	}
	value = atoi(ch);
	return value;
}