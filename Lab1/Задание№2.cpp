#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace chrono;

// Функция для проверки простоты методом полного перебора от 2 до N
bool isPrimeFull(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Функция для проверки простоты методом перебора только нечетных чисел от 2 до N
bool isPrimeOddFull(int n) {
    if (n % 2 == 0) return (n == 2);
    for (int i = 3; i < n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Функция для проверки простоты методом перебора от 2 до sqrt(N)
bool isPrimeSqrt(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Функция для проверки простоты методом перебора нечетных чисел от 2 до sqrt(N)
bool isPrimeOddSqrt(int n) {
    if (n % 2 == 0) return (n == 2);
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Функция для измерения времени выполнения
template <typename Func>
void measureTime(Func func, int n, const string& description) {
    auto start = high_resolution_clock::now();
    bool result = func(n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    cout << description << ": " << duration << " мкс (" << (result ? "простое" : "составное") << ")" << endl;
}

int main() {
    int testNumbers[] = {101, 103, 107, 1009, 10007, 100003, 1000003, 10000019};  // Примеры чисел для тестирования

    for (int n : testNumbers) {
        cout << "Проверка числа: " << n << endl;

        // Измеряем время для каждого метода
        measureTime(isPrimeFull, n, "Полный перебор от 2 до N");
        measureTime(isPrimeOddFull, n, "Перебор нечетных чисел от 2 до N");
        measureTime(isPrimeSqrt, n, "Перебор от 2 до sqrt(N)");
        measureTime(isPrimeOddSqrt, n, "Перебор нечетных чисел от 2 до sqrt(N)");

        cout << endl;
    }

    return 0;
}
