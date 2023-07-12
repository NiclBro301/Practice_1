#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include <cmath>

double f(double x) {
	return pow(2, x)*x-pow(3, x)+10;
}

double df(double x) {
    return pow(2, x)*x*log(2)+pow(2, x)-pow(3, x)*log(3);
}

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
setlocale(LC_CTYPE, "Russian_Russia.1251");

double x=0, x0, eps=0.0001;
double a, b=1, count = 0;
double a1, b1;

while(b >= 0){
	x++;
	b=f(x);
	cout << x << ':' << b << endl;
}

a=x-1;
b=x;
cout << "Корень лежит в промежутке [" << a << ";" << b << ']' << endl << endl;

while(fabs(b-a)>eps) {
	a1=a;
	b1=a;
	a = a1 - (f(a1)/df(a1));
	b = b1 - ((b1 - b)/(f(b1)-f(b)))*(f(b1));
	cout << "a = " << a << "; b = " << b << endl;
}

cout << endl;
cout << "Ответ :" << a << endl;
cout << endl;
system("pause");
}
