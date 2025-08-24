#include <iostream>

using namespace std;

int defaultparm(int a, int b, int c, int d, int e, int f = 0, int g = 0) {
    return (a + b + c + d + e + f + g) / 7;
}

int main() {
    setlocale(LC_ALL, "rus");
    int avg1 = defaultparm(1, 2, 3, 4, 5);
    int avg2 = defaultparm(1, 2, 3, 4, 5, 6, 7);
    cout << "первое: " << avg1 << endl; // (1+2+3+4+5+0+0)/7 = 2
    cout << "второе: " << avg2 << endl; // (1+2+3+4+5+6+7)/7 = 4
}