#include <iostream>
#include <fstream>
using namespace std;

struct list
{
	float number;
	list* next;
};

void input(list*&, float); 
void output(list*); 
float del(list*&, float); 
int isEmpty(list*); 
void toFile(list*& p);
void fromFile(list*& p); 
void proizv10(list*); 
void find(list*);

int main()
{
	setlocale(LC_CTYPE, "Russian");

	list* first = NULL;
	int choice;
	float value;

	do{
		cout << "1 - Ввод элементов" << endl;
		cout << "2 - Вывод элементов" << endl;
		cout << "3 - Удаление переменной" << endl;
		cout << "4 - Поиск" << endl;
		cout << "5 - Запись в файл" << endl;
		cout << "6 - Чтение данных из файла" << endl;
		cout << "7 - Вычисление умножения" << endl;
		cout << "0 - Выход из программы" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			int n;
			cout << "Сколько чисел вы хотите ввести?" << endl;
			cin >> n;
			for (int i = 0; i < n; i++) {
				cout << "Введите число ";
				cin >> value;
				input(first, value);
			}
			break;

		case 2:
			output(first);
			break;

		case 3:
			if (!isEmpty(first)) {
				cout << "Введите удаляемое число ";
				cin >> value;
				if (del(first, value))
				{
					cout << "Удалено число " << value << endl;
					output(first);
				}
				else
					cout << "Число не найдено" << endl;
			}
			else
				cout << "Список пуст" << endl;
			break;

		case 4:
			find(first);
			break;

		case 5:
			toFile(first);
			break;

		case 6:
			fromFile(first);
			break;

		case 7:
			proizv10(first);
			break;
		}
	} while (choice != 0);
	return 0;

}

void input(list*& first, float value)

{
	list* newfirst = new list;

	if (newfirst != NULL) 
	{
		newfirst->number = value; 
		newfirst->next = first; 
		first = newfirst; 
	}
	else
		cout << "Операция добавления не выполнена" << endl;
}

float del(list*& p, float value)

{
	list* previous, * current, * temp;
	if (value == p->number)
	{
		temp = p;
		p = p->next; // отсоединить узел
		delete temp; //освободить отсоединенный узел
		return value;
	}
	else
	{
		previous = p;
		current = p->next;

		while (current != NULL && current->number != value)
		{
			previous = current;
			current = current->next; 
		}
		if (current != NULL)
		{
			temp = current;
			previous->next = current->next;
			delete(temp);
			return value;
		}
	}
	return 0;
}


int isEmpty(list* p)
{
	return p == NULL;
}


void output(list* p)
{
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			cout << "-->" << p->number;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void proizv10(list* p)
{
	float pr = 1;

	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		while (p != NULL)
		{
			if (p->number < 10)
				pr = pr * (p->number);
			p = p->next;
		}
		cout << "Произведение = " << pr << endl;
	}
}


void toFile(list*& p) 
{
	list* temp = p;
	list buf;

	ofstream frm("FILE1.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (temp)
	{
		buf = *temp;
		frm.write((char*)&buf, sizeof(list));
		temp = temp->next;
	}
	frm.close();
	cout << "Список записан в файл FILE1.dat\n";
}


void fromFile(list*& p) 
{
	list buf, * first = nullptr;

	ifstream frm("FILE1.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}

	frm.read((char*)&buf, sizeof(list));
	while (!frm.eof())
	{
		input(first, buf.number);
		cout << "-->" << buf.number;
		frm.read((char*)&buf, sizeof(list));
	}
	cout << "-->NULL" << endl;
	frm.close();
	p = first;
	cout << "\nСписок считан из файла FILE1.dat\n";
}

void find(list * p)
{
	float value;

	cout << "Введите число для поиска ";
	cin >> value;
	while (p != NULL)
	{
		if (p->number == value)
		{
			cout << "Число " << value << " найдено в списке" << endl;
			return;
		}
		p = p->next;
	}
	cout << "Число не найдено в списке" << endl;
}