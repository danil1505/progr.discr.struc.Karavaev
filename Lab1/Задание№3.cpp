#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Алгоритм 1: Формирование массива общих делителей с последующим поиском максимума
int gcdWithArray(int M, int N) {
    vector<int> divisors;
    for (int i = 1; i <= min(M, N); i++) {
        if (M % i == 0 && N % i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors.back(); // Максимальный элемент в массиве
}

// Алгоритм 2: Перебор от 1 до min(M, N)
int gcdFrom1ToMin(int M, int N) {
    int nod = 1;
    for (int i = 1; i <= min(M, N); i++) {
        if (M % i == 0 && N % i == 0) {
            nod = i;
        }
    }
    return nod;
}

// Алгоритм 3: Перебор от min(M, N) до 1
int gcdFromMinTo1(int M, int N) {
    for (int i = min(M, N); i >= 1; i--) {
        if (M % i == 0 && N % i == 0) {
            return i;
        }
    }
    return 1;
}

// Алгоритм Евклида
int gcdEuclid(int M, int N) {
    while (N != 0) {
        int temp = N;
        N = M % N;
        M = temp;
    }
    return M;
}

// Функция для измерения времени выполнения
template <typename Func>
void measureTime(Func func, int M, int N, const string& description) {
    auto start = high_resolution_clock::now();
    int result = func(M, N);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();

    cout << description << ": " << duration << " мкс (НОД = " << result << ")" << endl;
}

int main() {
    // Примеры значений для тестирования
    int testPairs[][2] = {
        {252, 105}, {48, 180}, {270, 192}, {100003, 100007}, {123456, 654321}
    };

    for (auto& pair : testPairs) {
        int M = pair[0];
        int N = pair[1];
        cout << "Проверка для чисел M = " << M << ", N = " << N << endl;

        // Измеряем время для каждого метода
        measureTime(gcdWithArray, M, N, "Формирование массива общих делителей");
        measureTime(gcdFrom1ToMin, M, N, "Перебор от 1 до min(M, N)");
        measureTime(gcdFromMinTo1, M, N, "Перебор от min(M, N) до 1");
        measureTime(gcdEuclid, M, N, "Алгоритм Евклида");

        cout << endl;
    }

    return 0;
}
