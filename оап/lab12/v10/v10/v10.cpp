#include "Heap.h"
#include <iostream>

using namespace std;

heap::CMP cmpAAA(void* a1, void* a2) {
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
    heap::CMP rc = heap::EQUAL;
    if (A1->x > A2->x) rc = heap::GREAT;
    else if (A2->x > A1->x) rc = heap::LESS;
    return rc;
#undef A2
#undef A1
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    heap::Heap h1 = heap::create(30, cmpAAA);
    heap::Heap h2 = heap::create(30, cmpAAA);
    heap::Heap* currentHeap = &h1; // Указатель на текущую кучу

    int choice, k, heapChoice;

    for (;;) {
        cout << "\nМеню:\n";
        cout << "1 - Вывод текущей кучи\n";
        cout << "2 - Добавить элемент в текущую кучу\n";
        cout << "3 - Удалить максимальный элемент из текущей кучи\n";
        cout << "4 - Удалить минимальный элемент из текущей кучи\n";
        cout << "5 - Удалить i-й элемент из текущей кучи\n";
        cout << "6 - Объединить две кучи (К1 + К2 = К1)\n";
        cout << "7 - Переключиться на другую кучу\n";
        cout << "8 - Вывести обе кучи\n";
        cout << "0 - Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 0:
            exit(0);
        case 1:
            currentHeap->scan(0);
            break;
        case 2: {
            AAA* a = new AAA;
            cout << "Введите ключ: ";
            cin >> k;
            a->x = k;
            currentHeap->insert(a);
            cout << "Элемент добавлен в кучу " << (currentHeap == &h1 ? "К1" : "К2") << endl;
        }
              break;
        case 3:
            currentHeap->extractMax();
            cout << "Максимальный элемент удален из кучи " << (currentHeap == &h1 ? "К1" : "К2") << "!\n";
            break;
        case 4:
            currentHeap->extractMin();
            cout << "Минимальный элемент удален из кучи " << (currentHeap == &h1 ? "К1" : "К2") << "!\n";
            break;
        case 5:
            cout << "Введите индекс элемента для удаления: ";
            cin >> k;
            currentHeap->extractI(k);
            cout << "Элемент удален из кучи " << (currentHeap == &h1 ? "К1" : "К2") << "!\n";
            break;
        case 6:
            h1.unionHeap(h2);
            cout << "Кучи объединены (К1 + К2 = К1)!\n";
            break;
        case 7:
            cout << "Выберите кучу (1 - К1, 2 - К2): ";
            cin >> heapChoice;
            if (heapChoice == 1) {
                currentHeap = &h1;
                cout << "Теперь работаем с кучей К1\n";
            }
            else if (heapChoice == 2) {
                currentHeap = &h2;
                cout << "Теперь работаем с кучей К2\n";
            }
            else {
                cout << "Некорректный выбор кучи!\n";
            }
            break;
        case 8:
            cout << "\nКуча К1:";
            h1.scan(0);
            cout << "\nКуча К2:";
            h2.scan(0);
            break;
        default:
            cout << "Некорректный ввод!\n";
        }
    }

    return 0;
}