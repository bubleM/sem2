#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int DaysInMountch[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string date, birthday_str;
	cout << "Введите дату в формате ДДММГГГГ: " << endl;
	cin >> date;
	if (date.length() != 8) {
		cout << "Ошибка:Введите датy в правильном формате" << endl;
		return 1;
	}
	
	string day_str = date.substr(0, 2);
	string month_str = date.substr(2, 2);
	string year_str = date.substr(4, 4);
	//преобразовние из строки в число

	int day = stoi(day_str);
	int month = stoi(month_str);
	int year = stoi(year_str);
	
	
	if ((day > DaysInMountch[month - 1] && !defineLeapYear(year)) || day <= 0 || month <= 0 || month > 12 || year <= 0||((day > DaysInMountch[month - 1] && month!=2)||(month==2 && day>29) && defineLeapYear(year)))
	{
		cout << "Ошибка:НЕКОРЕКТНО" << endl;
		return 1;
	}


	cout << "Введите дату cвоего рождения в формате ДДММГГГГ: " << endl;
	cin >> birthday_str;

	if (birthday_str.length() != 8) {
		cout << "Ошибка:Введите датy в правильном формате" << endl;
		return 1;
	}

	string bd_sm = birthday_str.substr(0, 2);
	string monthBD_str = birthday_str.substr(2, 2);
	string yearBD_str = birthday_str.substr(4, 4);

	int birthday = stoi(bd_sm);
	int monthOfBirth = stoi(monthBD_str);
	int yearOfBirth = stoi(yearBD_str);

	if (((birthday > DaysInMountch[month - 1]) && !defineLeapYear(yearOfBirth)) || birthday <= 0 || monthOfBirth <= 0 || monthOfBirth > 12 || yearOfBirth <= 0 ||
		((birthday > DaysInMountch[month - 1] && monthOfBirth != 2) || (monthOfBirth == 2 && birthday > 29) && defineLeapYear(yearOfBirth)))
	{
		cout << "Ошибка:НЕКОРЕКТНО" << endl;
		return 1;
	}

	if ((year < yearOfBirth) || (year == yearOfBirth && ((month < monthOfBirth) || (month == monthOfBirth && day < birthday)))) 
	{
		cout << "Ошибка:Вы еще не родились!" << endl;
		return 1;
	}


	if (defineLeapYear(year)) 
	{
		cout << year << " - високосный год." << endl;
	}
	else {
		cout << year << " - не високосный год." << endl;
	}

	int OrdinalNumber = countNumber(day, month, year);
	cout << "Порядковый номер введенного дня в году равен: " << OrdinalNumber << endl;
	
	int summDays = countDays(birthday, monthOfBirth, day, month, year, yearOfBirth);
	cout << "До дня вашего рождения осталось: " << summDays<<" дней " << endl;
	
}

