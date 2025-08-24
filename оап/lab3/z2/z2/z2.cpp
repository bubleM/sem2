#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void writeToFile() {
    ofstream fout("t.txt");
    if (fout.is_open()) {
        fout << "Ночь ледяная рябь канала Аптека улица фонарь";
        fout.close();
    }
    else {
        cout << "Не удалось открыть файл для записи!\n";
    }
}

void readFromFile() {
    ifstream fin("t.txt");
    if (!fin.is_open()) {
        cout << "Файл не может быть открыт!\n";
    }
    else {
        char buff[100];
        cout << "Слова с буквой 'р' в строке: ";
        while (fin >> buff) {
            for (int i = 0; i < strlen(buff); i++) {
                if (buff[i] == 'р') {
                    cout << buff << " ";
                }
            }
        }
        fin.close();
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    writeToFile();
    readFromFile();
    return 0;
}
