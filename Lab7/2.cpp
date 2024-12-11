#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <unordered_map>

using namespace std;


//метод полного перебора для дискретного логарифмирования
long long longBF(long long a, long long b, long long mod) {
    long long result = 1;
    for (long long x = 0; x < mod; ++x) {
        if (result == b) {
            return x;
        }
        result = (result * a) % mod;
    }
    return -1; // Если логарифм не найден
}


//етод Шаг младенца – шаг великана
long long logBaby(long long a, long long b, long long mod) {
    long long n = static_cast<long long>(sqrt(mod)) + 1;

    //таблица младенческих шагов
    unordered_map<long long, long long> babySteps;
    long long value = 1;
    for (long long i = 0; i < n; ++i) {
        babySteps[value] = i;
        value = (value * a) % mod;
    }
    

    //Гигантские шаги
    long long giantStep = 1;
    for (long long i = 0; i < n; ++i) {
        giantStep = (giantStep * a) % mod;
    }
    value = b;
    for (long long j = 0; j < n; ++j) {
        if (babySteps.find(value) != babySteps.end()) {
            return j * n + babySteps[value];
        }
        value = (value * giantStep) % mod;
    }

    return -1;
}



int main() {
    long long a, b, mod;
    cout << "Введите основание (a): ";
    cin >> a;
    cout << "Введите значение (b): ";
    cin >> b;
    cout << "Введите модуль (mod): ";
    cin >> mod;


    auto startBruteForce = chrono::high_resolution_clock::now();
    long long resultBruteForce = longBF(a, b, mod);
    auto endBruteForce = chrono::high_resolution_clock::now();
    chrono::duration<double> durationBruteForce = endBruteForce - startBruteForce;


    auto startShanks = chrono::high_resolution_clock::now();
    long long resultShanks = logBaby(a, b, mod);
    auto endShanks = chrono::high_resolution_clock::now();
    chrono::duration<double> durationShanks = endShanks - startShanks;
    cout << fixed << setprecision(6);
    cout << "Результат (полный перебор): " << resultBruteForce << endl;
    cout << "Время выполнения (полный перебор): " << durationBruteForce.count() * 1000 << " мс" << endl;
    

    cout << "Результат (метод Шэнкса): " << resultShanks << endl;
    cout << "Время выполнения (метод Шэнкса): " << durationShanks.count() * 1000 << " мс" << endl;

    //таблицы с результатами для разных размеров входных данных
    cout << "\nТаблица сравнения:\n";
    cout << "Размер\tПолный перебор (мс)\tМетод Шэнкса (мс)\n";
    for (long long size = 10; size <= 1e6; size *= 10) {
        auto startBruteTest = chrono::high_resolution_clock::now();
        longBF(a, b, size);
        auto endBruteTest = chrono::high_resolution_clock::now();
        chrono::duration<double> timeBruteTest = endBruteTest - startBruteTest;
        

        auto startShanksTest = chrono::high_resolution_clock::now();
        logBaby(a, b, size);
        auto endShanksTest = chrono::high_resolution_clock::now();
        chrono::duration<double> timeShanksT = endShanksTest - startShanksTest;

        cout << size << "\t" << timeBruteTest.count() * 1000 << "\t\t" << timeShanksT.count() * 1000 << endl;
    }

    return 0;
}
