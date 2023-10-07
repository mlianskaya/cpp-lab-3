#include <iostream>
#include <cmath>
using namespace std;

long int min = 1000000000; //берем большое число, которое точно не получится при выполнении программы
long int m[32] = {}; //массив граммовок чашек (по условию 32 - максимальное количество чашек)
int n; //количество чашек
int porrige(long int gram_m, long int gram_p, int c) 
{
	if (c == n) //мы рассмотрели все комбинации с чашками
	{
		if (abs(gram_m - gram_p) < min)
			min = abs(gram_m - gram_p); //заменяем текущую минимальную разницу на новую
	}
	else // прибавляем чашку маше и переходим к следующей (16 строка), либо отдаем чашку пете и переходим к следующей (17 строка)
	{
		porrige(gram_m + m[c], gram_p, c + 1);
		porrige(gram_m, gram_p + m[c], c + 1);
	}	
	return 0;
}

int main() {
	cin >> n;  // вводим сколько чашек у нас есть в действительности
	for (int i = 0; i < n; i++)
		cin >> m[i];  // вводим граммовки чашек
	porrige(0, 0, 0); // изначально у каждого по 0 грамм каши
	cout << min;
	return 0;
}