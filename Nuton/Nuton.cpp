#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include <cmath>

double f_x(double x) {
	return pow(2, x)*x-pow(3, x)+10;
}

double df_x(double x) //возвращает значение производной
{
    return pow(2, x)*x*log(2)+pow(2, x)-pow(3, x)*log(3);
}

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
setlocale(LC_CTYPE, "Russian_Russia.1251");


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

double x2, delta = 1;
x = b;
while(delta >= e) {
	x2 = x - (f_x(x)/df_x(x));
	cout << "x2 = " << x2 << endl;
	delta = fabs(x2 - x);
	x = x2;
}

cout << endl;
cout << "Ответ: " << x2 << endl;

cout << endl;
system("pause");
}
