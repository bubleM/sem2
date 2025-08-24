#include <iostream>
using namespace std;

void bubbleSort(int* arr, int N)
{
	int num;
	for (int i = 1; i < N; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
			num = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = num;
		}
}

void main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int N, diploma = 0, cnt = 0, maxPoint = 100;
	int* results;
	string check;
	cout << "Введите количество участников: ";
	cin >> N;
	if (N >= 10000) {
		cout << "Неверный ввод! Сделайте это правильно (<10000)";
		exit(0);
	}
	results = new int[N];

	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		results[i] = rand() % 100 + 1;
		cout << "Призер " << i + 1 << " = " << results[i] << endl;
	}

	bubbleSort(results, N);

	for (int i = 0; i < N; i++) {
		cout << results[i] << ' ';
	}
	cout << endl;

	for (int i = N - 1; i > 0; i--) {
		if (diploma == 3) {
			break;
		}
		else {
			cnt++;
			if (i == 1 && results[i] == results[0])
				cnt++;
		}
		if (results[i] != results[i - 1]) {
			diploma++;
		}
	}
	cout << "Количесвто призеров: " << cnt << endl;

	delete[] results;
}