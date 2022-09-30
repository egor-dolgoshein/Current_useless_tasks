#include <iostream>
#include <vector>
#include <cmath>
/* 
используется метод касательных(метод Ньютона)
суть в том, чтобы:
1) выделить отрезки, на которых точно существует единственный корень уравнения (делаем аналитически - на бумаге)
2) уточнение корня, те вычисление его с некоторой погрешностью epsilon c помощью известной формулы
*/


using namespace std;

// значение функции в какой-то точке х
double f(double x)
{
	return pow(x, 3) + 4.19 * x * x - 0.553 * x - 6.4;
}

// значение производной в точке х
double derivative_f(double x)
{
	return 3 * x * x + 8.38 * x - 0.553;
}

// корни отделили аналитически, сейчас уточняем их
double root(double epsilon, double derivative_min, double a)
{
	double xn = a; // правая граница отрезка, на котором единственный корень
	while (abs(f(xn) / derivative_min) > epsilon) // известное условие выхода из цикла
	{
		xn = xn - f(xn) / derivative_f(xn); // известная формула следующего значения х
	}
	return xn;
}

void algorithm()
{
	vector<double> segment_border = { 2, -1, -3 }; // правые границы трех отрезков, на которых есть корень
	vector<double> derivative_min = { derivative_f(1), derivative_f(-8.38 / 6), derivative_f(-4) }; // минимум производной f на этих отрезках (нужно для формулы)
	double epsilon = 0.001; // погрешность (взял произвольно)
	for (int i = 0; i < 3; ++i)
	{
		double cur_root = root(epsilon, derivative_min[i], segment_border[i]); // вычисляем корень на отрезке
		cout << i + 1 << "-й корень равен " << cur_root << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	algorithm();
}