#include <iostream>
using namespace std;

int getFunction( int m, int n)
{
	if (m == 0 || n == 0)
		return n + 1;
	else
		return getFunction(m - 1, getFunction(m, n - 1));
}

int main()
{
	setlocale(LC_ALL, "rus");
	int F;
	int n, m;

	cout<<"Введите 2 целых неотрицательных числа: "<<endl;
	cout << "n= ";
	cin >> n;
	if (n < 0) {
		cout << "попробуйте еще раз!";
		return 1;
	}

	cout << "m= ";
	cin >> m;
	if (m < 0) {
		cout << "попробуйте еще раз!";
		return 1;
	}

	F = getFunction(m,n);
	cout <<"F=" << F;
}