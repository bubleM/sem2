#include "stack.h"
using namespace std;
void displayMenu() {
    cout << "1. Добавить элемент в стек 1\n";
    cout << "2. Добавить элемент в стек 2\n";
    cout << "3. Удалить элемент из стека 1\n";
    cout << "4. Удалить элемент из стека 2\n";
    cout << "5. Очистить стек 1\n";
    cout << "6. Очистить стек 2\n";
    cout << "7. Сохранить стек 1 в файл\n";
    cout << "8. Загрузить стек 1 из файла\n";
    cout << "9. Сохранить стек 2 в файл\n"; 
    cout << "10. Загрузить стек 2 из файла\n"; 
    cout << "11. сформировать стек из повторяющихся элементов стека 1 и стека 2\n";
    cout << "0. Выход\n";
}

int main() {
    setlocale(LC_ALL, "rus");
    Stack stack1, stack2, duplicatesStack;
    initStack(stack1);
    initStack(stack2);
    initStack(duplicatesStack);

    int choice, value;

    do {
        displayMenu();
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите значение для добавления в стек 1: ";
            cin >> value;
            push(stack1, value);
            break;
        case 2:
            cout << "Введите значение для добавления в стек 2: ";
            cin >> value;
            push(stack2, value);
            break;
        case 3:
            try {
                value = pop(stack1);
                cout << "Удаленное значение из стека 1: " << value << endl;
            }
            catch (const runtime_error& e) {
               cerr << e.what() << endl;
            }
            break;
        case 4:
            try {
                value = pop(stack2);
                cout << "Удаленное значение из стека 2: " << value << endl;
            }
            catch (const runtime_error& e) {
                cerr << e.what() << endl;
            }
            break;
        case 5:
            clear(stack1);
            cout << "Стек 1 очищен." << endl;
            break;
        case 6:
            clear(stack2);
            cout << "Стек 2 очищен." << endl;
            break;
        case 7:
            saveToFile(stack1, "stack1.txt");
            cout << "Стек 1 сохранен в файл." << endl;
            break;
        case 8:
            loadFromFile(stack1, "stack1.txt");
            cout << "Стек 1 загружен из файла." << endl;
            break;
        case 9:
            saveStack2ToFile(stack2, "stack2.txt");
            cout << "Стек 2 сохранен в файл." << endl;
            break;
        case 10:
            loadStack2FromFile(stack2, "stack2.txt");
            cout << "Стек 2 загружен из файла." << endl; 
            break;
        case 11:
            findDuplicates(stack1, stack2, duplicatesStack);
            cout << "Извлеченные общие элементы:" << endl;
            displayStack(duplicatesStack);
            break;
        case 0:
            clear(stack1);
            clear(stack2);
            clear(duplicatesStack);
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Ошибка!" << endl;
        }
    } while (choice != 0);

    return 0;
}

