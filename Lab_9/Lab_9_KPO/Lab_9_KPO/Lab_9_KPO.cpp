#include <iostream>

using namespace std;

float defaultparm(int a, int b, int c, int d, int e, int x = 10, int y = 20) {
	return (a + b + c + d + e + x + y) / 7;
}

int main() {
	cout << defaultparm(2, 5, 7, 8, 11) << endl;
	cout << defaultparm(2, 5, 7, 8, 11, 30, 55) << endl;
}