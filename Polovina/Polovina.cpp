#include "stdafx.h"
#include <iostream>
#include <locale.h>

double f_x(double c) {
	return pow(2, c)*c-pow(3, c)+10;
}

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
setlocale(LC_CTYPE, "Russian_Russia.1251");

double a, b, c = 0;
double eps = 0.0001;

cout << "Введите нижний предел отрезка >";
cin >> a;
cout << "Введите верхний предел отрезка >";
cin >> b;

while((f_x(a) - f_x(b)) > eps) {
	c = (a + b)/2;
	if(f_x(c)<0) {
		b = c;
	} else {
		a = c;
	}
}

cout << "Ответ: " << c << endl;

cout << endl;
system("pause");
}
