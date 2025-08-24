#include <iostream>
#include <Windows.h>
#include <climits>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(int a[], int n) {
    int i, j, t;
    for (i = 1; i < n; i++) {
        for (j = n - 1; j >= i; j--) {
            if (a[j - 1] < a[j]) {
                t = a[j - 1];
                a[j - 1] = a[j];
                a[j] = t;
            }
        }
    }
}

void heapify(int A[], int pos, int n) {
    int t, tm;
    while (2 * pos + 1 < n) {
        t = 2 * pos + 1;
        if (2 * pos + 2 < n && A[2 * pos + 2] < A[t]) 
            t = 2 * pos + 2;
        if (A[pos] > A[t]) {
            tm = A[pos];
            A[pos] = A[t];
            A[t] = tm;
            pos = t;
        }
        else {
            break;
        }
    }
}

void piramSort(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(A, i, n);
    }
    while (n > 0) {
        int tm = A[0];
        A[0] = A[n - 1];
        A[n - 1] = tm;
        n--;
        heapify(A, 0, n);
    }
}

void measureSortingTime(void (*sortFunction)(int[], int), int arr[], int size, const string& sortName) {
    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    sortFunction(arr, size);

    QueryPerformanceCounter(&end);
    long long elapsedNanoseconds = ((end.QuadPart - start.QuadPart) * 1000000000) / frequency.QuadPart;
    long long elapsedSeconds = elapsedNanoseconds / 1000000000;
    long long remainingNanoseconds = elapsedNanoseconds % 1000000000;

    cout << sortName << " выполнена за " << elapsedSeconds << " секунд и " << remainingNanoseconds << " наносекунд" << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(0)); 

    int size;
    cout << "Введите размеры массивов: ";
    cin >> size;

    int* A = new int[size];
    int* B = new int[size];
    int* C = new int[size];
    int max = INT_MIN;

    cout << "Массив А:" << endl;
    for (int i = 0; i < size; i++) {
        A[i] = rand() % 101; 
        cout<<i+1<<" элемент:" << A[i]<<endl;
    }

    cout << "Массив B:" << endl;
    for (int i = 0; i < size; i++) {
        B[i] = rand() % 51; 
        cout << i + 1 << " элемент:" << B[i]<<endl;
        if (max < B[i]) {
            max = B[i];
        }
    }

    int j = 0;
    for (int i = 0; i < size; i++) {
        if (A[i] > max) {
            C[j] = A[i];
            j++;
        }
    }

    if (j < 2) {
        while (j < 2) {
            C[j] = rand() % 101;
            j++;
        }
    }

    int* C1 = new int[j];
    copy(C, C + j, C1);

    cout << "Массив C до сортировки пузырьком: ";
    for (int i = 0; i < j; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    measureSortingTime(bubbleSort, C, j, "Пузырьковая сортировка");

    cout << "Массив C после сортировки пузырьком: ";
    for (int i = 0; i < j; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    cout << "Массив C1 до сортировки пирамидальной: ";
    for (int i = 0; i < j; i++) {
        cout << C1[i] << " ";
    }
    cout << endl;

    measureSortingTime(piramSort, C1, j, "Пирамидальная сортировка");

    cout << "Массив C1 после сортировки пирамидальной: ";
    for (int i = 0; i < j; i++) {
        cout << C1[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;
    delete[] C1;

    return 0;
}
