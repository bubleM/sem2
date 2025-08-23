#include "stdafx.h"
#include <iostream>
bool defineLeapYear(int year) //високосный
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return 1;
	}
	return 0;
}