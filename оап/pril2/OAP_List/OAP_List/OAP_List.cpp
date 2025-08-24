#include "List.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct Car {
    char brand[30];
    char color[20];
    char factoryNumber[20];
    char releaseDate[15];
    char bodyType[15];
    char lastCheckDate[15];
    char owner[30];
};

void print(void* data) {
    Car* car = (Car*)data;
    cout << car->brand << " " << car->color << " " << car->factoryNumber
        << " " << car->releaseDate << " " << car->bodyType << " "
        << car->lastCheckDate << " " << car->owner << endl;
}

void ShowMenu(Object& carList) {
    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить автомобиль\n";
        cout << "2. Вывести список автомобилей\n";
        cout << "3. Найти автомобиль по владельцу\n";
        cout << "4. Удалить список\n";
        cout << "5. Подсчитать количество автомобилей\n";
        cout << "6. Выход\n";
        cout << "Выберите пункт: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Car* newCar = new Car;
            cout << "Марка: "; cin >> newCar->brand;
            cout << "Цвет: "; cin >> newCar->color;
            cout << "Заводской номер: "; cin >> newCar->factoryNumber;
            cout << "Дата выпуска: "; cin >> newCar->releaseDate;
            cout << "Тип кузова: "; cin >> newCar->bodyType;
            cout << "Дата последнего ТО: "; cin >> newCar->lastCheckDate;
            cout << "Владелец: "; cin >> newCar->owner;
            carList.Insert(newCar);
            break;
        }
        case 2:
            carList.PrintList(print);
            break;
        case 3: {
            char ownerName[30];
            cout << "Введите имя владельца: ";
            cin >> ownerName;
            Element* found = carList.Search(ownerName);
            if (found) {
                Car* car = (Car*)found->Data;
                cout << "Найден автомобиль: " << car->brand << ", владелец: " << car->owner << endl;
            }
            else {
                cout << "Автомобиль не найден.\n";
            }
            break;
        }
        case 4:
            carList.DeleteList();
            cout << "Список удален.\n";
            break;
        case 5:
            cout << "Количество автомобилей: " << carList.CountList() << endl;
            break;
        case 6:
            cout << "Выход...\n";
            break;
        default:
            cout << "Неверный выбор!\n";
        }
    } while (choice != 6);
}

int main() {
    setlocale(LC_ALL, "rus");
    Object carList;
    ShowMenu(carList);
    return 0;
}
