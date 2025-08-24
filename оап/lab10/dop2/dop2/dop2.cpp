#include <iostream>
using namespace std;

int printP(int arr[], int nool, int n)
{
	if (nool == n)
	{
		for (int i = 0; i != n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return arr[n];
	}
	for (int i = nool; i != n; i++) {
		swap(arr[nool], arr[i]);

		printP(arr, nool + 1, n);
		swap(arr[nool], arr[i]);
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n = 5;
	int arr[5];

	for (int i = 0; i != 5; i++)
	{
		cout << "Введите " << i + 1 << "  элемент: ";
		cin >> arr[i];
	}

	cout << "Все перестановки:" << endl;
	printP(arr, 0, n);
}