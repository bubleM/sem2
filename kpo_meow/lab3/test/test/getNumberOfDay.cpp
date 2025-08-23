#include "stdafx.h"
int getNumberOfDay(int day, int month, bool isLeap) {
	int number = 0;

	if (!isLeap) {
		months[1].second = 28;
	}

	for (int i = 0; i != month - 1; ++i) {
		number += months[i].second;
	}
	number += day;
	return number;
}

int getNumberByBD(int currentDay, int currentMonth, int currentYear, int BDDay, int BDMonth, bool isLeap) {
	if (BDDay == 29 && BDMonth == 2) {
		int daysBefore = (4 - (currentYear % 4)) * 365;
		if (isLeap) {
			daysBefore = 0;
		}
		return getNumberOfDay(BDDay, BDMonth, isLeap) - getNumberOfDay(currentDay, currentMonth, isLeap) + daysBefore;
	}

	return getNumberOfDay(BDDay, BDMonth, isLeap) - getNumberOfDay(currentDay, currentMonth, isLeap);
}

pair<int, int> getDate(int number, bool isLeap) {
	if (isLeap) { // Увеличиваем порядковый номер праздника после 29-го февраля если год високосный
		for (int i = 0; i != holidays.size(); ++i) {
			if (holidays[i].second >= 59) {
				holidays[i].second++;
			}
		}
	}

	int monthIndex = 0;
	for (int i = 0; i != 12; ++i) {
		if (number > months[i].second) {
			number -= months[i].second;
			monthIndex++;
		}
		else {
			return make_pair(number, monthIndex);
		}
	}


	return make_pair(0, 0);
}

int getHoliday(int number) {
	bool flag = false;
	for (int i = 0; i != holidays.size(); ++i) {
		if (number == holidays[i].second) {
			return i;
		}
	}
	return -1;
}