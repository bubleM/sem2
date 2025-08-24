#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

enum Eform
{
	monarchy=1, republic
}forms;

struct State
{
	string name;
	string capital;
	string population;
	string square;
	Eform form;
};
vector<State> states;

void addState()
{
	State state;
	int form;

	cout << "Наименование: ";
	cin.ignore();
	getline(cin, state.name);
	cout << "Столица: ";
	getline(cin, state.capital);
	cout << "Численность населения: ";
	getline(cin, state.population);
	cout << "Площадь: ";
	getline(cin, state.square);
	

	cout << "форма правления(Монархия(1), республика(2)): ";
	do {
		cin >> form;
		if (form < 1 || form>2)
			cout << "Некоректно!";
	} while (form < 1 || form>2);
	
	state.form = static_cast<Eform>(form);

	states.push_back(state);
	cout << "Государство успешно добавлено!" << endl;
}

void displayStates()
{
	for (int i = 0; i < states.size(); i++)
	{
		
		cout << "Государство " << i + 1 << ":" << endl;
		cout << "Наименование: " << states[i].name << endl;
		cout << "Столица: " << states[i].capital << endl;
		cout << "Численность населения: " << states[i].population << endl;
		cout << "Площадь: " << states[i].square << endl;

		if (states[i].form == monarchy)
			cout << "Форма правления: Монархия" << endl;
		else if (states[i].form == republic)
			cout << "Форма правления: Республика" << endl;
		cout << endl;
	}
}

void deleteStateByCapital()
{
	string capital;

	cout << "Введите столицу государства: "<<endl;
	cin.ignore();
	getline(cin, capital);

	bool found = false;

	for (int i = 0; i < states.size(); i++) {
		if (states[i].capital == capital) {
			states.erase(states.begin() + i);
			found = true;
		}
	}
	if (found)
		cout << "Государство со столицей " << capital << " успешно удалено!" << endl;
	else
		cout << "Государство со столицей " << capital << " не найдено!" << endl;
}

void searchState()
{
	string capital;
	cout << "Введите столицу государства: "<<endl;
	cin.ignore();
	getline(cin, capital);
	bool found = false;
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i].capital == capital)
		{
			cout << "Государство " << i + 1 << ":" << endl;
			cout << "Наименование: " << states[i].name << endl;
			cout << "Столица: " << states[i].capital << endl;
			cout << "Численность населения: " << states[i].population << endl;
			cout << "Площадь: " << states[i].square << endl;
			cout << endl;
			found = true;
		}
	}
	if (!found)
		cout << "Государство со столицей " << capital << " не найдено!" << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");

	int choice;
	do {
		cout << "/////////////////////////////////////////////" << endl;
		cout << "Меню:" << endl;
		cout << "1. Ввод Государства" << endl;
		cout << "2. Вывод информации об государствах" << endl;
		cout << "3. Удаление государства" << endl;
		cout << "4. Поиск государства" << endl;
		cout << "0. Выход" << endl;
		cout << "/////////////////////////////////////////////" << endl;
		cout << "Введите номер пункта меню: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1:addState();
			break;
		case 2:displayStates();
			break;
		case 3:deleteStateByCapital();
			break;
		case 4:searchState();
			break;
		}
		cout << endl;
	} while (choice != 0);
	return 0;
}