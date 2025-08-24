#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

union Cit {
    char fullname[100]; 
    char address[100];
    char date[11];
    char gender;
};

struct Citizen {
    Cit name;
    Cit addr;
    Cit birthday;
    Cit gendr;
};

vector<Citizen> citizens;

void addCitizen() {
    Citizen citizen;

    cout << "ФИО горожанина: ";
    cin.ignore();
    cin.getline(citizen.name.fullname, sizeof(citizen.name.fullname));
    cout << "Адрес: ";
    cin.getline(citizen.addr.address, sizeof(citizen.addr.address));
    cout << "Дата рождения (ДДММГГГГ): ";
    cin.getline(citizen.birthday.date, sizeof(citizen.birthday.date));
    cout << "Пол (м/ж): ";
    cin >> citizen.gendr.gender;

    citizens.push_back(citizen);
    cout << "Успешно добавлен!" << endl;
}

void displayCitizens() {
    for (int i = 0; i < citizens.size(); i++) {
        cout << "Горожанин " << i + 1 << ":" << endl;
        cout << "ФИО: " << citizens[i].name.fullname << endl;
        cout << "Адрес: " << citizens[i].addr.address << endl;
        cout << "Дата рождения: " << citizens[i].birthday.date << endl;
        cout << "Пол: " << citizens[i].gendr.gender << endl;
        cout << endl;
    }
}

void searchCitizen() {
    char birthday[11];
    cout << "Введите дату рождения горожанина (ДДММГГГГ): ";
    cin.ignore();
    cin.getline(birthday, sizeof(birthday));

    bool found = false;
    for (int i = 0; i < citizens.size(); i++) {
        if (strcmp(citizens[i].birthday.date, birthday) == 0) {
            cout << "Горожанин " << i + 1 << ":" << endl;
            cout << "ФИО: " << citizens[i].name.fullname << endl;
            cout << "Адрес: " << citizens[i].addr.address << endl;
            cout << "Дата рождения: " << citizens[i].birthday.date << endl;
            cout << "Пол: " << citizens[i].gendr.gender << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Горожанин не найден!" << endl;
}

void writeToFile() {
    ofstream file("citizens.txt");
    
    for (int i = 0; i < citizens.size(); i++) {
        file << "Горожанин " << i + 1 << ":" << endl;
        file << "ФИО: " << citizens[i].name.fullname << endl;
        file << "Адрес: " << citizens[i].addr.address << endl;
        file << "Дата рождения: " << citizens[i].birthday.date << endl;
        file << "Пол: " << citizens[i].gendr.gender << endl;
        file << endl;
    }

    file.close();
    cout << "Данные успешно записаны в файл!" << endl;
}

void readFromFile() {
    ifstream file("citizens.txt");
    if (!file) {
        cout << "Файл не найден!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl; 
    }

    file.close();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int choice;
    do {
        cout << "Меню:" << endl;
        cout << "1. Ввод информации о горожанине" << endl;
        cout << "2. Вывод информации о горожанинах" << endl;
        cout << "3. Поиск горожанина по дате рождения" << endl;
        cout << "4. запись в файл" << endl;
        cout << "5. чтение из файла" << endl;
        cout << "0. Выход" << endl;
        cout << "Введите пункт меню:";
        cin >> choice;
        switch (choice)
        {
        case 1: addCitizen(); break;
        case 2: displayCitizens(); break;
        case 3:searchCitizen(); break;
        case 4:writeToFile(); break;
        case 5:readFromFile(); break;
        default:
            break;
        }
        cout << endl;
    } while (choice != 0);
}