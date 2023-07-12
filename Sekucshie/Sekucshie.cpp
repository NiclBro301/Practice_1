#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include <cmath>

double f_x(double x) {
	return pow(2, x)*x-pow(3, x)+10;
}

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
setlocale(LC_CTYPE, "Russian_Russia.1251");

//(pow(2, x)*x-pow(3, x)+10)=0

double x=0, e=0.0001;
int a, b=1;

while(b >= 0){
	x++;
	b=f_x(x);
	cout << x << ':' << b << endl;
}

a=x-1;
b=x;
cout << "Корень лежит в промежутке [" << a << ";" << b << ']' << endl << endl;

double x0 = a, x1, x2, delta = 1;
x1 = b;
while(delta >= e) {
x2 = x1 - ((x1 - x0)/(f_x(x1)-f_x(x0)))*(f_x(x1));
cout << "x2 = " << x2 << endl;
delta = fabs(x2 - x1);
x1 = x2;
}

cout << endl;
cout << "Ответ: " << x2 << endl;

cout << endl;
system("pause");
}
