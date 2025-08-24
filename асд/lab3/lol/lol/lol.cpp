#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

//пузырик
void bubble_sort(int* mass, int n) {
	for (int j = 0; j < n - 1; j++) {
		for (int i = j + 1; i < n; i++) {
			if (mass[i] < mass[j]) {
				swap(mass[j], mass[i]);
			}
		}
	}
}

//метод Шелла
void ShellSort(int mass[], int n) {
	int num;
	for (int i = 1; i < n; i++)
		for (int j = i; j > 0 && mass[j - 1] > mass[j]; j--) {
			num = mass[j - 1];
			mass[j - 1] = mass[j];
			mass[j] = num;
		}
}

//выбором
void SelectionSort(int mass[], int n) {
	int count, key;
	for (int i = 0; i < n - 1; i++) {
		count = mass[i];
		key = i;
		for (int j = i + 1; j < n; j++)
			if (mass[j] < mass[key])
				key = j;
		if (key != i) {
			mass[i] = mass[key];
			mass[key] = count;
		}
	}
}

//быстрая
void quickSort(int* mass, int first, int last) {
	int f = first;
	int l = last;
	int mid = mass[(f + l) / 2];
	int temp;

	while (f <= l) {
		while (mass[f] < mid)
			f++;
		while (mass[l] > mid)
			l--;
		if (f <= l) {
			temp = mass[f];
			mass[f] = mass[l];
			mass[l] = temp;
			f++;
			l--;
		}
	}
	if (l > first)
		quickSort(mass, first, l);
	if (f < last)
		quickSort(mass, f, last);
}

int main() {

	setlocale(LC_ALL, "Russian");
	unsigned int start_shaker, end_shaker, start_bubble, end_bubble, start_selection, end_selection, start_fast, end_fast;
	int size;
	cout << " Введите количество элементов в массив: "; cin >> size;

	//Генерация массива
	static int* arrA = new int[size];
	static int* arrB = new int[size];
	static int* arrC = new int[size];
	static int* arrD = new int[size];
	static int* arrE = new int[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arrA[i] = arrB[i] = arrC[i] = arrD[i] = arrE[i] = rand() % 100;
	}

	//Вывод массива
	for (int i = 0; i < size; i++) {
		cout << "элемент[" << i + 1 << "] = " << arrA[i] << "\n";
	}


	//Пузырьковая сортировка-----------------------------------------------------------
	start_bubble = clock();
	bubble_sort(arrB, size);
	cout << "\n Отсортированный массив (Пузырьковая сортировка):\n";
	for (int i = 0; i < size; i++) {
		cout << "элемент[" << i + 1 << "] = " << arrB[i] << "\n";
	}
	end_bubble = clock();
	unsigned int bubble_sort_time = end_bubble - start_bubble;
	cout << "\nВремя сортировки пузырьком: " << bubble_sort_time << " мс.\n";


	//Сортировка вставкой (или методом Шелла)------------------------------------------
	start_shaker = clock();
	ShellSort(arrC, size);
	cout << "\n Отсортированный массив (Сортировка вставкой):\n";
	for (int i = 0; i < size; i++) {
		cout << "элемент[" << i + 1 << "] = " << arrC[i] << "\n";
	}
	end_shaker = clock();
	unsigned int Shell_sort_time = end_shaker - start_shaker;
	cout << "\nВремя сортировки методом Шелла: " << Shell_sort_time << " мс.\n";


	//Сортировка выбором---------------------------------------------------------------
	start_selection = clock();
	SelectionSort(arrD, size);
	cout << "\n Отсортированный массив (Сортировка выбором):\n";
	for (int i = 0; i < size; i++) {
		cout << "элемент[" << i + 1 << "] = " << arrD[i] << "\n";
	}
	end_selection = clock();
	unsigned int Selection_sort_time = end_selection - start_selection;
	cout << "\nВремя сортировки выбором: " << Selection_sort_time << " мс.\n";


	//Быстрая сортировка---------------------------------------------------------------
	start_fast = clock();
	quickSort(arrE, 0, size);
	cout << "\n Отсортированный массив (Быстрая сортировка):\n";
	for (int i = 1; i < size + 1; i++) {
		cout << "элемент[" << i << "] = " << arrE[i] << "\n";
	}
	end_fast = clock();
	unsigned int quik_sort_time = end_fast - start_fast;
	cout << "\nВремя быстрой сортировки: " << quik_sort_time << " мс.\n\n";
}