#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int N, number, right, left = 1, mid, count=0;
	bool find = false;

	cout << "Введите число N:";
	cin >> N;

	const int maxIt = ceil(log2(N));
	right = N;
	mid = N / 2;
	int choise;
	do {
		system("cls");
		cout << mid << endl;
		cout << "(1)Больше" << endl;
		cout << "(2)Меньше" << endl;
		cout << "(3)Нашёл" << endl;
		cin >> choise;
		if (choise == 1)
		{
			left = mid + 1;
			mid = (right+left) / 2;
		}
		else if (choise == 2)
		{
			right = mid - 1;
			mid = (left+right+1) / 2;
		}
		else if (choise == 3) {
			find = true;
		}
		else {
			cout << "Неверный ввод!" << endl;
		}
		count++;
		continue;

	} while (find != true);

	system("cls");
	cout << "загаданное число:" << mid << endl;
	cout << "Количество шагов:" << count << endl;
	cout << "Максимальное количество шагов:" << maxIt << endl;

	left = 1;
	right = N;
	cout << "Все шаги бинарного поиска:" << endl;
	for (int i = 1; right > 1; i++) {
		mid = (right + left) / 2;
		cout << mid << endl;
		right = mid;
	}
}