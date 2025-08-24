#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

union Cit
{
	string fullname;
	string address;
	string date;
	string gender;

};

struct Citizen
{
	Cit name;
	Cit addr;
	Cit birthday;
	Cit gendr;
};

vector<Citizen> citizens;

void addCitizen()
{
	Citizen citizen;

	cout << "ФИО горожанина: ";
	cin.ignore();
	getline(cin, citizen.name.fullname);
	cout << "Адрес: ";
	getline(cin, citizen.addr.address);
	cout << "Дата рождения(ДДММГГГГ):";
	getline(cin, citizen.birthday.date);
	cout << "Пол(м/ж):";
	cin >> citizen.gendr.gender;


	citizens.push_back(citizen);
	cout << "Успешно добавлен!" << endl;
}

void displayCitizens()
{
	for (int i = 0; i < citizens.size(); i++)
	{
		cout << "Горожанин " << i + 1 << ":" << endl;
		cout << "ФИО: " << citizens[i].name.fullname << endl;
		cout << "Адрес: " << citizens[i].addr.address << endl;
		cout << "дата рождения: " << citizens[i].birthday.date << endl;
		cout << "пол: " << citizens[i].gendr.gender << endl;
		cout << endl;
	}
}


void searchCitizen()
{
	string bithday;
	cout << "Введите дату рождения горожанина: ";
	cin.ignore();
	getline(cin, bithday);
	bool found = false;
	for (int i = 0; i < citizens.size(); i++)
	{
		if (citizens[i].birthday.date == bithday)
		{
			cout << "Горожанин " << i + 1 << ":" << endl;
			cout << "ФИО: " << citizens[i].name.fullname << endl;
			cout << "Адрес: " << citizens[i].addr.address << endl;
			cout << "дата рождения: " << citizens[i].birthday.date << endl;
			cout << "пол: " << citizens[i].gendr.gender << endl;
			cout << endl;
			found = true;
		}
	}
	if (!found)
		cout << "Горожанин не найден!" << endl;
}

void writeToFile()
{
	ofstream file("citizens.txt");
	for (int i = 0; i < citizens.size(); i++)
	{
		cout << "Горожанин " << i + 1 << ":" << endl;
		cout << "ФИО: " << citizens[i].name.fullname << endl;
		cout << "Адрес: " << citizens[i].addr.address << endl;
		cout << "дата рождения: " << citizens[i].birthday.date << endl;
		cout << "пол: " << citizens[i].gendr.gender << endl;
		cout << endl;
		file << endl;
	}
	file.close();
	cout << "Данные успешно записаны в файл!" << endl;
}

void readFromFile()
{
	ifstream file("citizens.txt");
	if (!file)
	{
		cout << "Файл не найден!" << endl;
		return;
	}
	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}
	file.close();
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");

	int choice;
	do {
		cout << "Меню:" << endl;
		cout << "1. Ввод информации об горожанине" << endl;
		cout << "2. Вывод информации об горожанинах" << endl;
		cout << "3. Поиск горожанина по дате рождения" << endl;
		cout << "4. Запись информации в файл" << endl;
		cout << "5. Чтение из файла" << endl;
		cout << "0. Выход" << endl;
		cout << "Введите номер пункта меню: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1:addCitizen();
			break;
		case 2:displayCitizens();
			break;
		case 3:searchCitizen();
			break;
		case 4:writeToFile();
			break;
		case 5:readFromFile();
			break;
		}
		cout << endl;
	} while (choice != 0);
	return 0;
}