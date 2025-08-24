#include "stack.h"
using namespace std;
void displayMenu() {
    cout << "1. Добавить элемент в стек\n";
    cout << "2. Удалить элемент из стека\n";
    cout << "3. Очистить стек\n";
    cout << "4. Сохранить стек в файл\n";
    cout << "5. Загрузить стек из файла\n";
    cout << "6. Разделить стек на четные и нечетные элементы\n";
    cout << "0. Выход\n";
}

int main() {
    setlocale(LC_ALL, "rus");

    Stack Stack, evenStack, oddStack;
    initStack(Stack);
    initStack(evenStack);
    initStack(oddStack);

    int choice, value;

    do {
        displayMenu();
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите значение для добавления: ";
            cin >> value;
            push(Stack, value);
            break;
        case 2:
            try {
                value = pop(Stack);
                cout << "Удаленное значение: " << value << endl;
            }
            catch (const runtime_error& e) {
                cerr << e.what() << endl;
            }
            break;
        case 3:
            clear(Stack);
            cout << "Стек очищен." << endl;
            break;
        case 4:
            saveToFile(Stack, "stack.txt");
            cout << "Стек сохранен в файл." << endl;
            break;
        case 5:
            loadFromFile(Stack, "stack.txt");
            cout << "Стек загружен из файла." << endl;
            break;
        case 6:
            splitStack(Stack, evenStack, oddStack);
            cout << "Стек разделен на четные и нечетные элементы." << endl;

           cout << "Четные элементы: ";
            displayStack(evenStack);
            cout << "Нечетные элементы: ";
            displayStack(oddStack);
            break;
        case 0:
            clear(Stack);
            clear(evenStack);
            clear(oddStack);
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Ошибка!" << endl;
        }
    } while (choice != 0);

    return 0;
}


