#include <iostream>

using namespace std;

//процедура для вывода чисел от 1 до N
void printAsc(int n) {
    if (n <= 0) return;
    printAsc(n - 1);  // рекурсивный вызов
    cout << n << " ";
}

//процедура для вывода чисел от N до 1
void printDesc(int n) {
    if (n <= 0) return;
    cout << n << " ";
    printDesc(n - 1);  
}

//процедура для вывода чисел от -N до N
void printMinusToPlus(int n) {
    if (n < 0) return;
    cout << "-" << n << " ";
    printMinusToPlus(n - 1);  
    cout << n << " ";
}

//процедура для вывода всех четных чисел от 0 до N
void printEven(int n) {
    if (n < 0) return;
    printEven(n - 2);  
    if (n % 2 == 0) {
        cout << n << " ";
    }
}

//процедура для вывода всех нечетных чисел от N до 0
void printOddDesc(int n) {
    if (n < 0) return;
    if (n % 2 != 0) {
        cout << n << " ";
    }
    printOddDesc(n - 2);  
}

int main() {
    cout << "Последовательность от 1 до N:" << endl;
    printAsc(10);
    cout << endl;

    cout << "Последовательность от N до 1:" << endl;
    printDesc(10);
    cout << endl;

    cout << "Последовательность от -N до N:" << endl;
    printMinusToPlus(10);
    cout << endl;

    cout << "Четные числа от 0 до N:" << endl;
    printEven(10);
    cout << endl;

    cout << "Нечетные числа от N до 0:" << endl;
    printOddDesc(10);
    cout << endl;

    return 0;
}
