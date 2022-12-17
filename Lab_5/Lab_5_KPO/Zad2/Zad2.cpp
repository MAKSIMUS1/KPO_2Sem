#include <iostream>
using namespace std;

typedef int real_chast;
typedef int mnimaya_chast;

struct Complex
{
	real_chast rl;
	mnimaya_chast mn;

	bool operator >(Complex& a)
	{
		return (mn > a.mn);
	}
	bool operator <(Complex& a)
	{
		return (mn < a.mn);
	}
	bool operator ==(Complex& a)
	{
		return (mn == a.mn);
	}
};

int main()
{
	Complex chislo1 = { 80, 31 },
		chislo2 = { 12, 30 },
		chislo3 = { 97, -55 };

	cout << "Complex1 > Complex2: ";
	if (chislo1 > chislo2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "Complex1 < Complex2: ";
	if (chislo1 < chislo2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "Complex1 = Complex2: ";
	if (chislo1 == chislo2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "Complex1 = Complex3: ";
	if (chislo1 == chislo3)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
};
