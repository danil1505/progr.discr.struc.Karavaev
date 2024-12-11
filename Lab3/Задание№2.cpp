#include <iostream>
#include <cmath>
#include <chrono>
#include <vector>
#include <iomanip>
#include <random>

using namespace std;
using namespace chrono;

//роверка полным перебором от 2 до N
bool PBasic(int n) {
    if (n < 2) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

//проверки перебором только нечетных чисел от 2 до N
bool Podd(int n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;  
    for (int i = 3; i < n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

//проверки перебором от 2 до sqrt(N)
bool Psqrt(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

//проверки перебором только нечетных чисел от 2 до sqrt(N)
bool PoddN(int n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}




int main() {
    cout << fixed << setprecision(6);
    const int TRIALS = 1000; //кол попыток для усреднения времени выполнения
    random_device rd;
    mt19937 gen(rd());
    vector<int> test_sizes = {10000, 50000, 100000, 500000, 1000000};
    cout << "Размер данных\tот 2 до N\t\tот 2 до N(мс)\t\tот 2 до sqrt(N)(мс)\t2 до sqrt(N)(мс)\n";
    for (int n : test_sizes) {
        vector<double> times(4, 0.0);
        for (int i = 0; i < TRIALS; i++) {
            int num = uniform_int_distribution<>(n, n * 2)(gen);
            

             // Измерение времени от 2 до N
            auto start = high_resolution_clock::now();
            PBasic(num);
            auto end = high_resolution_clock::now();
            times[0] += duration<double, milli>(end - start).count();


            // Измерение времени для нечетных чисел от 2 до N
            start = high_resolution_clock::now();
            Podd(num);
            end = high_resolution_clock::now();
            times[1] += duration<double, milli>(end - start).count();

            // Измерение времени от 2 до sqrt(N)
            start = high_resolution_clock::now();
            Psqrt(num);
            end = high_resolution_clock::now();
            times[2] += duration<double, milli>(end - start).count();


            // Измерение времени для нечетных чисел от 2 до sqrt(N)
            start = high_resolution_clock::now();
            PoddN(num);
            end = high_resolution_clock::now();
            times[3] += duration<double, milli>(end - start).count();
        }
        cout << n << "\t\t";
        for (double time : times) {
            cout << time / TRIALS << "\t\t";
        }
        cout << endl;
    }

    return 0;
}
