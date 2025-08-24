#include <iostream>
#include <string>
#include <windows.h>
#include <limits>
#include <chrono>
using namespace std;
#ifdef max
#undef max
#endif

const int TABLE_SIZE = 5;

struct elem {
	int phone;
	string name;
};

int hashF(int key, int size, int p = 0) {
	const double A = 0.6180339887;
	double product = key * A;
	double fractional_part = product - floor(product);
	int res = static_cast<int>(floor(size * fractional_part));

	return (res + p) % size;
}

void addToTable(elem table[], int key, int &size, string name) {
	int p = 0;
	int i = hashF(key,size,p++);
	while (table[i].phone != NULL) {
		if (p > TABLE_SIZE) {
			cout << "������������ ��������!" << endl;
			return;
		}
		i = hashF(key, size, p++);
	}

	table[i].phone = key;
	table[i].name = name;
	cout << "������� ��������!" << endl;
}

void deleteElem(elem table[], int key, int &size) {
	int h = hashF(key, size);
	bool isFind = false;
	for (int p = 0;p != TABLE_SIZE*2;++p) {
		if (table[h].phone == key) {
			isFind = true;
			break;
		}
		else {
			h = hashF(key, size, p);
		}
	}
	if (!isFind) {
		cout << "����� ������� �� ������!" << endl;
		return;
	}
	table[h] = { NULL };
	cout << "������� ������!" << endl;
}

void search(elem table[], int key, int size) {
	int h = hashF(key, size);
	bool isFind = false;
	for (int p = 0;p != TABLE_SIZE * 2;++p) {
		if (table[h].phone == key) {
			isFind = true;
			break;
		}
		else {
			h = hashF(key, size, p);
		}
	}
	if (!isFind) {
		cout << "����� ������� �� ������!" << endl;
		return;
	}
	else {
		cout << "����: " << table[h].phone << endl;
		cout << "��������: " << table[h].name << endl;
	}
}

void print(elem table[]) {
	bool isEmpty = true;
	for (int i = 0;i != TABLE_SIZE;++i) {
		if (table[i].phone != NULL) {
			isEmpty = false;
			cout << "(" << i << ") " << table[i].phone << " " << table[i].name << endl;
		}
	}
	if (isEmpty) {
		cout << "������� �����!";
	}
	cout << endl << endl;
}

bool strCheck(string str) {
	for (unsigned char ch : str) {
		if (isalpha(ch)) continue;
		if (ch == ' ') continue;
		//if (ch == '-') continue;

		bool isCyrillic = (ch >= 0xC0 && ch <= 0xFF) || (ch == 0xA8) || (ch == 0xB8);                   

		if (!isCyrillic) {
			return false;
		}
	}
	return true;
}

int main() {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	elem table[TABLE_SIZE] = { NULL };
	int choice = 0;

	int size = TABLE_SIZE;

	while (choice != 5) {
		cout << "(1) �������� �������" << endl;
		cout << "(2) ������� �������" << endl;
		cout << "(3) ������� �������" << endl;
		cout << "(4) ����� �������" << endl;
		cout << "(5) �����" << endl;
		cout << "> ";
		cin >> choice;
		system("cls");
		string temp;
		int num;
		string name;
		auto s = chrono::steady_clock::now();

		switch (choice)
		{
		case 1:
			cout << "������� ����(����� ��������):" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, temp, '\n');
			if (temp.size() > 5) {
				cout << "������������ ���� ������!" << endl;
				break;
			}
			try {
				num = stoi(temp);
			}
			catch (...) {
				cout << "������������ ���� ������!" << endl;
				break;
			}
			if (num <= 0) {
				cout << "������������ ���� ������!" << endl;
				break;
			}

			cout << "������� ��������(���):" << endl;
			getline(cin, name, '\n');
			if (!strCheck(name)) {
				cout << "�������� ���� ���!" << endl;
				break;
			}
			
			addToTable(table, num, size, name);

			num = NULL;
			name.clear();
			break;
		case 2:
			cout << "������� ����(����� ��������):" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, temp, '\n');
			if (temp.size() > 5) {
				cout << "������������ ���� ������!" << endl;
				break;
			}
			try {
				num = stoi(temp);
			}
			catch (...) {
				cout << "������������ ����!" << endl;
				break;
			}
			if (num <= 0) {
				cout << "������������ ���� ������!" << endl;
				break;
			}

			deleteElem(table, num, size);

			num = NULL;
			break;
		case 3:
			print(table);
			break;
		case 4:
			cout << "������� ����(����� ��������):" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, temp, '\n');
			if (temp.size() > 5) {
				cout << "������������ ���� ������!" << endl;
				break;
			}
			try {
				num = stoi(temp);
			}
			catch (...) {
				cout << "������������ ����!" << endl;
				break;
			}
			if (num <= 0) {
				cout << "������������ ���� ������!" << endl;
				break;
			}

			s = chrono::steady_clock::now();
			search(table, num, size);
			auto searchT = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - s);
			cout << endl << "����� ������:" << searchT.count() << " ���" << endl;
			num = NULL;
			break;
		case 5:
			exit(0);
		default:
			cout << "������������ ����!" << endl;
			break;
		}
	}

}