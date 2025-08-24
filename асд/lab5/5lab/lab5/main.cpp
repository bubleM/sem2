#include <iostream>
#include <stack>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str;
	cout << "������� ������ ���������� {},[] ��� (), � ��� �� + - * / :" << endl;
	getline(cin, str, '\n');

	stack<char> s;
	for (int i = 0; i != str.size();++i) {
		if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
			s.push(str[i]);
		}
		else if ((str[i] == '}' || str[i] == ']' || str[i] == ')') && !s.empty()) {
			char temp = s.top();
			if (temp == '{' && str[i] == '}') {
				s.pop();
				continue;
			}
			if (temp == '(' && str[i] == ')') {
				s.pop();
				continue;
			}
			if (temp == '[' && str[i] == ']') {
				s.pop();
				continue;
			}
			else {
				cout << "������ ����������� �������!";
				return 1;
			}
		}
	}
	if (!s.empty()) {
		cout << "������ ����������� �������!";
		return 1;
	}
	cout << "������ ����������� �����!";
}