#include "stdafx.h"
#include <iostream>
int countNumber(int day, int month, int year)
{
	int DaysInMountch[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (defineLeapYear(year)) {
		DaysInMountch[1] = 29;
	}
	int OrdinalNumber = day;
	for (int i = 0; i < month - 1; i++)
	{
		OrdinalNumber += DaysInMountch[i];
	}
	return OrdinalNumber;
}