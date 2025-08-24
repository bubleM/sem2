#include <iostream>
using namespace std;

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

struct Date {
	day dd;
	month mm;
	year yyyy;
};

bool operator > (Date date1, Date date2) {
	return ((date1.yyyy > date2.yyyy) || ((date1.yyyy == date2.yyyy) && (date1.mm > date2.mm)) || ((date1.yyyy == date2.yyyy) && (date1.mm == date2.mm) && (date1.dd > date2.dd)));
}

bool operator < (Date date1, Date date2) {
	return ((date1.yyyy < date2.yyyy) || ((date1.yyyy == date2.yyyy) && (date1.mm < date2.mm)) || ((date1.yyyy == date2.yyyy) && (date1.mm == date2.mm) && (date1.dd < date2.dd)));
}

bool operator == (Date date1, Date date2) {
	return(date1.dd == date2.dd && date1.mm == date2.mm && date1.yyyy == date1.yyyy);
}

int main() {
	setlocale(LC_ALL, "Russian");
	Date date1 = { 7,1,1980 };
	Date date2 = { 7,2,1993 };
	Date date3 = { 7,1,1980 };

	if (date1 < date2) cout << "истина" << endl;
	else cout << "ложь" << endl;

	if (date1 > date2) cout << "истина" << endl;
	else cout << "ложь" << endl;

	if (date1 == date2) cout << "истина" << endl;
	else cout << "ложь" << endl;

	if (date1 == date3) cout << "истина" << endl;
	else cout << "ложь" << endl;
}