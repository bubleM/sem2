#include <iostream>
#include "stack.h"
using namespace std;

void displayMenu() {
    cout << "Меню:\n";
    cout << "1. Добавить элемент в стек 1\n";
    cout << "2. Добавить элемент в стек 2\n";
    cout << "3. Заполнить стек 3\n";
    cout << "4. Удалить элементы из стека 3, входящие в стек 2, но не входящие в стек 1\n";
    cout << "5. Удалить элементы из стека 3, входящие в стек 1, но не входящие в стек 2\n";
    cout << "6. Очистить стек 1\n";
    cout << "7. Очистить стек 2\n";
    cout << "8. Очистить стек 3\n";
    cout << "9. Сохранить стек 1 в файл\n";
    cout << "10. Загрузить стек 1 из файла\n";
    cout << "11. Выход\n";
}

int main() {
    setlocale(LC_ALL, "rus");
    Stack stack1, stack2, stack3;
    initStack(&stack1);
    initStack(&stack2);
    initStack(&stack3);

    int choice, value;

    while (true) {
        displayMenu();
        cout << "Выберите опцию: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите элемент для добавления в стек 1: ";
            cin >> value;
            push(&stack1, value);
            break;
        case 2:
            cout << "Введите элемент для добавления в стек 2: ";
            cin >> value;
            push(&stack2, value);
            break;
        case 3:
            cout << "Введите элементы для заполнения стека 3 (введите -1 для завершения):\n";
            while (true) {
                cin >> value;
                if (value == -1) break;
                push(&stack3, value);
            }
            break;
        case 4:
            removeFromStack3BasedOnStack2(&stack1, &stack2, &stack3);
            cout << "Элементы удалены из стека 3.\n";
            break;
        case 5:
            removeFromStack3BasedOnStack1(&stack1, &stack2, &stack3);
            cout << "Элементы удалены из стека 3.\n";
            break;
        case 6:
            clear(&stack1);
            cout << "Стек 1 очищен.\n";
            break;
        case 7:
            clear(&stack2);
            cout << "Стек 2 очищен.\n";
            break;
        case 8:
            clear(&stack3);
            cout << "Стек 3 очищен.\n";
            break;
        case 9:
            saveToFile(&stack1, "stack1.txt");
            cout << "Стек 1 сохранен в файл.\n";
            break;
        case 10:
            loadFromFile(&stack1, "stack1.txt");
            cout << "Стек 1 загружен из файла.\n";
            break;
        case 11:
            clear(&stack1);
            clear(&stack2);
            clear(&stack3);
            return 0; 
        default:
            cout << "Неверно, попробуйте снова\n";
        }
    }

    return 0;
}
