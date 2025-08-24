#include <iostream>
#include <ctime>
using namespace std;

long long fib(int n) {
    if (n == 1) {
        return 0;
    }
    else if (n == 2 || n==3) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    int num = 0;
    cout << "Введите число N в последовательности Фибоначи: ";
    cin >> num;

    clock_t start = clock();
    cout << "Этой последовательности соответствует цифра: ";
    cout << fib(num) << endl << endl;
    clock_t end = clock();


    double time_taken = double(end - start) / CLOCKS_PER_SEC; 
    int minutes = static_cast<int>(time_taken) / 60;
    int seconds = static_cast<int>(time_taken) % 60;
    int nanoseconds = static_cast<int>((time_taken - static_cast<int>(time_taken)) * 1e9); 

    cout << "Время выполнения (рекурсивный метод): "
        << minutes << " минут "
        << seconds << " секунд "
        << nanoseconds << " наносекунд" << endl;

    return 0;
}

