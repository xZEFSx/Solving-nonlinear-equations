#include <iostream>
#include <clocale>
#include <math.h>
#define E 2.71828

using namespace std;

static double f(double x) {
	return pow(E, x) - pow(E, -x) - 2;
}

static double f1(double x) {
	return log(pow(E, -x) + 2);
}

static double f2(double x) {
	return -1/(2*pow(E, x) + 1);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, x0, x1;
	double e = 0.001;
	cin >> a >> b;
	if (abs(f2(a)) < 1) {
		x0 = a;
	}
	else {
		x0 = b;
	}
	cout << "В ходе вычислений программа находит вот такие приближения:" << endl;
	x1 = f1(x0);
	while (abs(x0 - x1) >= e) {
		cout << "x = " << x1 << endl;
		x0 = x1;
		x1 = f1(x0);
	}
	cout << "А примерным итоговым корнем будет являться: " << x1 << endl;
	return 0;
}
