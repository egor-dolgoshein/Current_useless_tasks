#include <iostream>
#include <vector>
#include <cmath>
/* 
������������ ����� �����������(����� �������)
���� � ���, �����:
1) �������� �������, �� ������� ����� ���������� ������������ ������ ��������� (������ ������������ - �� ������)
2) ��������� �����, �� ���������� ��� � ��������� ������������ epsilon c ������� ��������� �������
*/


using namespace std;

// �������� ������� � �����-�� ����� �
double f(double x)
{
	return pow(x, 3) + 4.19 * x * x - 0.553 * x - 6.4;
}

// �������� ����������� � ����� �
double derivative_f(double x)
{
	return 3 * x * x + 8.38 * x - 0.553;
}

// ����� �������� ������������, ������ �������� ��
double root(double epsilon, double derivative_min, double a)
{
	double xn = a; // ������ ������� �������, �� ������� ������������ ������
	while (abs(f(xn) / derivative_min) > epsilon) // ��������� ������� ������ �� �����
	{
		xn = xn - f(xn) / derivative_f(xn); // ��������� ������� ���������� �������� �
	}
	return xn;
}

void algorithm()
{
	vector<double> segment_border = { 2, -1, -3 }; // ������ ������� ���� ��������, �� ������� ���� ������
	vector<double> derivative_min = { derivative_f(1), derivative_f(-8.38 / 6), derivative_f(-4) }; // ������� ����������� f �� ���� �������� (����� ��� �������)
	double epsilon = 0.001; // ����������� (���� �����������)
	for (int i = 0; i < 3; ++i)
	{
		double cur_root = root(epsilon, derivative_min[i], segment_border[i]); // ��������� ������ �� �������
		cout << i + 1 << "-� ������ ����� " << cur_root << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	algorithm();
}