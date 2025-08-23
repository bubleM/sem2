#include "stdafx.h"
#include <iostream>
#include <chrono>

using namespace std::chrono;

int main() {
	setlocale(LC_ALL, "RU");

	string date;

	cout << "Введите дату в формате ДДММГГГГ:";
	cin >> date;

	if (date.size() != 8) {
		cout << "Неверный формат даты!";
		exit(10);
	}

	int day = atoi(date.substr(0, 2).c_str());
	int month = atoi(date.substr(2, 2).c_str());
	int year = atoi(date.substr(4, 4).c_str());

	bool leapYear = isLeapYear(year);

	if (!leapYear) {
		months[1].second = 28;
	}

	if (day < 1 || month < 1 || year < 1 || month > 12 || day > months[month - 1].second) {
		cout << "Введена некорректная дата!";
		exit(1);
	}

	int dayNumber = getNumberOfDay(day, month, leapYear);
	cout << endl << "Номер дня: " << dayNumber << endl;
	cout << "Номер введенного месяца: " << month << endl << "Название: " << months[month - 1].first << endl;

	//string BDDate;
	//cout << "Введите дату рождения в формате ДДММ:";
	//cin >> BDDate;

	//int BDDay = atoi(BDDate.substr(0, 2).c_str());
	//int BDMonth = atoi(BDDate.substr(2, 2).c_str());
	//months[1].second = 29;

	//if (BDDay < 1 || BDMonth < 1 || BDMonth > 12 || BDDay > months[month - 1].second) {
	//	cout << "Введена некорректная дата!";
	//	exit(1);
	//}

	//int dayNumber = getNumberOfDay(day, month, leapYear);
	//int daysBeforeBD = getNumberByBD(day, month, year, BDDay, BDMonth, leapYear);

	//leapYear ? cout << "Это вискосный год" : cout << "Это не високосный год";
	//cout << "Дней до ближайшего Дня рождения: " << daysBeforeBD;

	int number = 0;
	cout << endl << "Введите порядковый номер года: ";
	cin >> number;

	pair<int, int> Date = getDate(number, leapYear);
	int holidayIndex = getHoliday(number);
	cout << "Введенная дата: " << Date.first << " " << months[Date.second].first << endl;
	if (holidayIndex != -1) {
		cout << "С праздником: " << holidays[holidayIndex].first;
	}
	else {
		cout << "нет праздника";
	}
}