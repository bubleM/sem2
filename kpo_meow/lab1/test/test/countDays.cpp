#include "stdafx.h"
#include <iostream>
int countDays(int birthday, int monthOfBirth,int day, int month, int year, int yearOfBirth)
{
	int DaysInMountch[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (defineLeapYear(year)) {
		DaysInMountch[1] = 29;
	}

	int summ=0;
	if (defineLeapYear(yearOfBirth) && monthOfBirth == 2 && birthday == 29) {
		if (defineLeapYear(year)) {
			if (month==1) {
				summ = DaysInMountch[0] - day+29;
			}
			else if (month == 2) {
				if (day < 29) {
					summ = 29 - day;
				}
				else if (day == 29) {
					summ = 57;
					for (int i = 2; i != 12; i++) {
						summ += DaysInMountch[i];
					}
					for (int j = 0; j != 12; j++) {
						summ += 3*DaysInMountch[j];
					}
				
				}
			}
			else {
				summ = 57+DaysInMountch[month-1]-day;
				for (int k = 0; k != 12; k++) {
					for (int p = month; p != 12; p++) {
						summ += DaysInMountch[p];
					}
					summ += 3 * DaysInMountch[k];
				}
			}
		}
		else if(!defineLeapYear(year))
		{
			summ = DaysInMountch[month - 1] - day + 60;

			for (int b = month; b != 12; b++) 
			{
				summ += DaysInMountch[b];
			}

			if(defineLeapYear(year+3)) { 
				for (int a = 0; a != 12; a++) {
					summ += 2* DaysInMountch[a];
				}
			}

			else if (defineLeapYear(year + 2))
			{
				for (int a = 0; a != 12; a++) {
					summ += DaysInMountch[a];
				}
			}
		}
	}

	else if (day >= birthday) {
	if (month < monthOfBirth)
	{
		summ = DaysInMountch[month - 1] - day;
		for (int o = month; o != monthOfBirth; o++) 
		{
			summ += DaysInMountch[o];
		}
	}
	else if (month > monthOfBirth|| month == monthOfBirth) {
		summ= DaysInMountch[month - 1] - day+birthday;
		for (int j = month; j != 12; j++) {
			for (int i = 0; i != monthOfBirth - 1; i++)
			{
				summ += DaysInMountch[i];
			}
			summ += DaysInMountch[j];
		}
	}
	}
	
	else if (day < birthday)
	{
		if (month == monthOfBirth)
			summ = birthday - day;
		else if (month < monthOfBirth) {
			summ = DaysInMountch[month - 1] - day+birthday;
			for (int q = month; q != monthOfBirth - 1; q++) {
				summ += DaysInMountch[q];
			}
		}
		else if (month > monthOfBirth) {
			summ = DaysInMountch[month - 1] - day + birthday;
			for (int j = month; j != 12; j++) {
				for (int i = 0; i != monthOfBirth - 1; i++)
				{
					summ += DaysInMountch[i];
				}
				summ += DaysInMountch[j];
			}

		}
	}

	return summ;
}