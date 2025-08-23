#pragma once
int getNumberOfDay(int day, int month, bool isLeap);
int getNumberByBD(int currentDay, int currentMonth, int currentYear, int BDDay, int BDMonth, bool isLeap);
pair<int, int> getDate(int number, bool isLeap);
int getHoliday(int number);