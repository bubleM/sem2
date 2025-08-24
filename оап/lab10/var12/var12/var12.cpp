#include <iostream>
using namespace std;

double recurs(int n, double x) {

	if (n == 0)
		return 0;
	else
		return cos(n * x) + recurs(n - 1, x);
}

int main()
{
	setlocale(LC_ALL, "rus");

	double y;
	int n;
	double x;
	cout << "введите n= ";
	cin >> n;
	cout << "введите угол x= ";
	cin >> x;
	y = recurs(n, x);
	cout << y;
}