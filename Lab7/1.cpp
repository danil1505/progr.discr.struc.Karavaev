#include <iostream>
#include <chrono>

using namespace std;



//наивный метод возведения в степень по модулю
long long naivMod(long long base, long long exponent, long long mod) {
    long long result = 1;
    for (long long i = 0; i < exponent; ++i) {
        result = (result * base) % mod;
    }
    return result;
}


//быстрый метод возведения в степень по модулю
long long fastMod(long long base, long long exponent, long long mod) {
    long long result = 1;
    base = base % mod; 

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}




int main() {
    long long base, exponent, mod;

    cout << "Введите основание: ";
    cin >> base;
    cout << "Введите показатель степени: ";
    cin >> exponent;
    cout << "Введите модуль: ";
    cin >> mod;


    //время для наивного метода
    auto startNaive = chrono::high_resolution_clock::now();
    
    long long resultNaive = naivMod(base, exponent, mod);
    auto endNaive = chrono::high_resolution_clock::now();
    chrono::duration<double> durationNaive = endNaive - startNaive;


    //время для быстрого метода
    auto startFast = chrono::high_resolution_clock::now();
    long long resultFast = fastMod(base, exponent, mod);
    auto endFast = chrono::high_resolution_clock::now();
    chrono::duration<double> durationFast = endFast - startFast;



    cout << "Результат (наивный метод): " << resultNaive << endl;
    cout << "Время выполнения (наивный метод): " << durationNaive.count() << " сек" << endl;
    cout << "Результат (быстрый метод): " << resultFast << endl;
    cout << "Время выполнения (быстрый метод): " << durationFast.count() << " сек" << endl;



    //таблица с результатами
    cout << "\nТаблица сравнения:\n";
    cout << "Размер\tНаивный метод (сек)\tБыстрый метод (сек)\n";
    for (long long exp = 1; exp <= 1e6; exp *= 10) {
        auto SnavTest = chrono::high_resolution_clock::now();
        naivMod(base, exp, mod);
        auto endnavTest = chrono::high_resolution_clock::now();
        chrono::duration<double> timeNaiveTest = endnavTest - SnavTest;
        auto startFastTest = chrono::high_resolution_clock::now();
        fastMod(base, exp, mod);
        auto endFastTest = chrono::high_resolution_clock::now();
        chrono::duration<double> timeFastTest = endFastTest - startFastTest;
        cout << exp << "\t" << timeNaiveTest.count() << "\t\t" << timeFastTest.count() << endl;
    }

    return 0;
}
