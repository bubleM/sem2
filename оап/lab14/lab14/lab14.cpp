#include <iostream>
#include <list>
#include <string>
using namespace std;

struct Client {
    string accountNumber;
    string fullName;
};

struct HashTable {
    int size;
    list<Client>* table;
};

HashTable* createHashTable(int size) {
    HashTable* hashTable = new HashTable;
    hashTable->size = size;
    hashTable->table = new list<Client>[size];
    return hashTable;
}

int hashFunction(const string& key, int size) {
    int hashValue = 0;
    for (char ch : key) {
        hashValue ^= static_cast<int>(ch); //к ASCII-кодам символов
    }
    return hashValue % size;
}

void insert(HashTable* hashTable, const string& accountNumber, const string& fullName) {
    int index = hashFunction(accountNumber, hashTable->size);
    Client client = { accountNumber, fullName };
    hashTable->table[index].push_back(client);
}

string search(HashTable* hashTable, const string& accountNumber) {
    int index = hashFunction(accountNumber, hashTable->size);
    for (const Client& client : hashTable->table[index]) {
        if (client.accountNumber == accountNumber) {
            return client.fullName;
        }
    }
    return "Не найден";
}

bool remove(HashTable* hashTable, const string& accountNumber) {
    int index = hashFunction(accountNumber, hashTable->size);
    auto& clients = hashTable->table[index];

    for (auto it = clients.begin(); it != clients.end(); ++it) {
        if (it->accountNumber == accountNumber) {
            clients.erase(it); 
            return true; 
        }
    }
    return false;
}

void display(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        cout << "Index " << i << ": ";
        for (const Client& client : hashTable->table[i]) {
            cout << "(" << client.accountNumber << ", " << client.fullName << ") ";
        }
        cout << endl;
    }
}

void deleteHashTable(HashTable* hashTable) {
    delete[] hashTable->table; 
    delete hashTable;
}

int main() {
    setlocale(LC_ALL, "rus");

    int size;
    cout << "Введите размер таблицы:" << endl;
    cin >> size;

    HashTable* hashTable = createHashTable(size);

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Добавить клиента\n";
        cout << "2. Найти клиента\n";
        cout << "3. Удалить клиента\n";
        cout << "4. Показать содержимое таблицы\n";
        cout << "5. Выход\n";
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: { 
            string accountNumber, fullName;
            cout << "Введите номер счета клиента: ";
            cin >> accountNumber;
            cout << "Введите полное имя клиента: ";
            cin.ignore();
            getline(cin, fullName); 

            insert(hashTable, accountNumber, fullName); 
            cout << "Клиент добавлен.\n";
            break;
        }
        case 2: { 
            string accountNumber;
            cout << "Введите номер счета для поиска: ";
            cin >> accountNumber;

            cout << "Результат поиска: " << search(hashTable, accountNumber) << endl;
            break;
        }
        case 3: { 
            string accountNumber;
            cout << "Введите номер счета для удаления: ";
            cin >> accountNumber;

            if (remove(hashTable, accountNumber)) {
                cout << "Клиент удален.\n";
            }
            else {
                cout << "Клиент не найден.\n";
            }
            break;
        }
        case 4: { 
            cout << "\nСодержимое хеш-таблицы:\n";
            display(hashTable);
            break;
        }
        case 5:
            deleteHashTable(hashTable);
            return 0;
        default:
            cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}
