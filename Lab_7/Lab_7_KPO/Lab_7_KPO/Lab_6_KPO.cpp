#include "Dictionary.h"
#include "stdafx.h"
#include <iostream>
#include <windows.h>


using namespace Dictionary;
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	try
	{
#if defined(TEST_CREATE_01)
		Instance d1 = Create("Преподаввввввввввввввввввввввввввввввввввввввввввввввввввввпппппппппппппппппппппппппппппппппппввввввввввввввввввввввввввввввввввввввввввввввввввввввватели", 5);
#elif defined(TEST_CREATE_02)
		Instance d1 = Create("Преподаватели", 1000);
#else 
		Instance d1 = Create("Преподаватели", 5);
#endif
		Entry e1 = { 1, "Гладкий" },
			e2 = { 2, "Веялкин" },
			e3 = { 3, "Смелов" },
			e4 = { 4, "Урбанович" },
#if defined(TEST_ADDENTRY_04)
			e5 = { 2, "Пацей" };
#else 
			e5 = { 5, "Пацей" };
#endif
		addEntry(d1, e1);
		addEntry(d1, e2);
		addEntry(d1, e3);
		addEntry(d1, e4);
		addEntry(d1, e5);
#if defined(TEST_ADDENTRY_03)
		addEntry(d1, e5);
#endif

#if defined(TEST_GETENTRY_05)
		Entry ex2 = GetEntry(d1, 4000);
#else
		Entry ex2 = GetEntry(d1, 4);
#endif
#if defined(TEST_DELENTRY_06)
		DelEntry(d1, 20000);
#else
		DelEntry(d1, 2);
#endif
#if defined(TEST_UPDENTRY_08)
		Entry newentry1 = { 1, "Вафел" };
#else 
		Entry newentry1 = { 6, "Вафел" };
#endif
#if defined(TEST_UPDENTRY_07)
		UpdEntry(d1, 30000, newentry1);
#else
		UpdEntry(d1, 3, newentry1);
#endif
		Print(d1);

		Instance d2 = Create("Студенты", 5);
		Entry s1 = { 1, "Иванов" },
			s2 = { 2, "Петров" },
			s3 = { 3, "Николаев" };
		addEntry(d2, s1);
		addEntry(d2, s2);
		addEntry(d2, s3);

		Entry newentry3 = { 3, "Николаев" };
		UpdEntry(d2, 3, newentry3);
		Print(d2);
		Delete(d1);
		Delete(d2);
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	system("pause");
}