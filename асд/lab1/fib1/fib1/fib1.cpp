#include <iostream>
#include <time.h>
using namespace std;

long long fib(int n) {
    if (n == 1) return 0;
    if (n == 2 || n == 3) return 1;
    long long num1 = 0, num2 = 1;
    for (int i = 2; i != n; ++i) {
        long long num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
    }
    return num2;
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    int n;
    cout << "Введите число N в последовательности Фибоначи: ";
    cin >> n;
    if (isalpha(n)||n <= 0) {
        cout << "ERROR!" << endl;
        return 1;
    }

    clock_t start = clock();
    cout << "Этой последовательности соответствует цифра: " << fib(n) << endl;
    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    int minutes = static_cast<int>(time_taken) / 60;
    int seconds = static_cast<int>(time_taken) % 60;
    int nanoseconds = static_cast<int>((time_taken - static_cast<int>(time_taken)) * 1e3);

    cout << "Время выполнения (рекурсивный метод): "
        << minutes << " минут "
        << seconds << " секунд "
        << nanoseconds << " наносекунд" << endl;

    return 0;
}
