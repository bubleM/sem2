#include <iostream>
#include <fstream>
using namespace std;

void generateNumbers(int A, int glu, int* array, ofstream& file) {
    if (glu == A) {
        for (int i = 0; i < A; i++) {
            file << array[i];
        }
        file << endl;
        return;
    }

    for (int j = 0; j <= A; j++) {
        array[glu] = j;
        generateNumbers(A, glu + 1, array, file);
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int A;
    cout << "Введите цифру A: ";
    cin >> A;

    if (A < 0 || A > 9) {
        cout << "Цифра A должна быть от 0 до 9." << endl;
        return 1;
    }

    ofstream file("numbers.txt");
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    int* array = new int[A];

    // рекурсия функци
    generateNumbers(A, 0, array, file);

    cout << "Все числа записаны в файл numbers.txt" << endl;

    file.close();
    delete[] array;
    return 0;
}
