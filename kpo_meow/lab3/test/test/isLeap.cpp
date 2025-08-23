#include "stdafx.h"
bool isLeapYear(int year) {
	if (year % 4 == 0) {
		return true;
	}
	return false;
}