#include <iostream>
#include <clocale>
#include <math.h>
#define E 2.71828

using namespace std;

static double f(double x) {
	return pow(E, x) - pow(E, -x) - 2;
}

static double f1(double x) {
	return pow(E, x) + pow(E, -x);
}

static double f2(double x) {
	return pow(E, x) - pow(E, -x);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, x0 = 0.0, x1;
	double e = 0.001;
	cin >> a >> b;
	if (f(a) * f2(a) > 0) {
		x0 = a;
	}
	else {
		x0 = b;
	}
	x1 = x0 - f(x0) / f1(x0);
	cout << "В ходе вычислений программа находит вот такие приближения:" << endl;
	while (abs(x1 - x0) >= e) {
		cout << "x = " << x1 << endl;
		x0 = x1;
		x1 = x0 - f(x0) / f1(x0);
	}

	cout << "А примерным итоговым корнем будет являться: " << x1 << endl;
	return 0;
}