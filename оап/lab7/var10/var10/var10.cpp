#include <iostream>
#include <Windows.h>
#include "stack.h"
using namespace std;

void displayMenu() {
	cout << "1 - Добавление элемента в стек" << endl;
	cout << "2 - Запись в файл" << endl;
	cout << "3 - Чтение из файла" << endl;
	cout << "4 - Вывод стека" << endl;
	cout << "5 - Очистка стека" << endl;
	cout << "6 - Поиск элемента из диапазона" << endl;
	cout << "7 - Выход" << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice; int x;
	Stack* myStk = new Stack; 
	myStk = NULL;

	do
	{
		displayMenu();
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент: " << endl;
			cin >> x;
			push(x, myStk); break;

		case 2: toFile(myStk); break;

		case 3: fromFile(myStk); break;

		case 4: 
			cout << "Весь стек: " << endl;
			show(myStk); break;

		case 5: clear(myStk); break;

		case 6: find(myStk); break;
		}
	} while (choice != 7);
	return 0;
}