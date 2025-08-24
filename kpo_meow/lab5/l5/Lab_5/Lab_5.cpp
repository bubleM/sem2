#include "stdafx.h"
#include <iostream>
#include <windows.h>
using namespace std;
using namespace Dictionary;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");

#if (defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_DELENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) + defined(TEST_DICTIONARY) > 1 )
#error

#endif
	try {

#ifdef TEST_CREATE_01 // Если определено TEST_CREATE_01 (первое тестовое условие)
		Instance d1 = Create("Пример строки с русскими символами", 5);
#endif

#ifdef TEST_CREATE_02 // Если определено TEST_CREATE_02 (второе тестовое условие)
		Instance d1 = Create("Пример строки", 100000);
#endif

#ifdef TEST_ADDENTRY_03
		Instance test = Create("Test", 0);
		Entry test_entry = { 1, "test_entry1" };
		addEntry(test, test_entry);
#endif

#ifdef TEST_ADDENTRY_04 // Если определено TEST_ADDENTRY_04 (четвертое тестовое условие)
		Instance test = Create("Test", 2);
		Entry test_entry = { 1, "test_entry1" };
		addEntry(test, test_entry);
		addEntry(test, test_entry);
#endif

#ifdef TEST_GETENTRY_05 //GetEntry: не найдена запись
		Instance test = Create("Test", 2);
		Entry test_entry = { 1, "test_entry1" };
		addEntry(test, test_entry);
		GetEntry(test, 2);
#endif

#ifdef TEST_DELENTRY_06 //DelEntry: не найдена запись
		Instance test = Create("Test", 2);
		Entry test_entry = { 1, "test_entry1" };
		addEntry(test, test_entry);
		DelEntry(test, 2);
#endif

#ifdef TEST_UPDENTRY_07
		Instance test = Create("Test", 3);
		Entry test_entry = { 1, "test_entry1" }, entry_to_update = { 2, "entry_to_update" };
		addEntry(test, test_entry);
		UpdEntry(test, 3, entry_to_update);
#endif

#ifdef TEST_UPDENTRY_08
		Instance test = Create("Test", 3);
		Entry test_entry = { 2, "test_entry1" }, entry_to_update = { 2, "entry_to_update" };
		addEntry(test, test_entry);
		UpdEntry(test, 2, entry_to_update);
#endif

#ifdef TEST_DICTIONARY
		Instance d1 = Create("Преподаватели", 5); // Создание словаря
		Entry e1 = { 1, "Гладкий" }, // Записи словаря
			e2 = { 2, "Веялкин" },
			e3 = { 3, "Смелов" },
			e4 = { 4, "Урбанович" },
			e5 = { 5, "Пацей" };

		addEntry(d1, e1);  // Добавление записи в словарь
		addEntry(d1, e2);
		addEntry(d1, e3);
		addEntry(d1, e4);
		addEntry(d1, e5);

		DelEntry(d1, 2);
		Entry new_entry1 = { 6, "Гурин" };
		UpdEntry(d1, 3, new_entry1);
		Print(d1);


		Instance d2 = Create("Студенты", 5);
		Entry s1 = { 1, "Иванов" }, s2 = { 2, "Петров" }, s3 = { 3, "Сидоров" };
		addEntry(d2, s1);
		addEntry(d2, s2);
		addEntry(d2, s3);

		Entry new_entry2 = { 4, "Николаев" };
		UpdEntry(d2, 3, new_entry2);
		Print(d2);

		cout << endl;
		Entry ex2 = GetEntry(d1, 4);  // Получение записи по id 4
		Delete(d1);
		Delete(d2);
#endif
	}
	catch (const char* e) {
		cout << e << endl;
	}
	system("pause");
}