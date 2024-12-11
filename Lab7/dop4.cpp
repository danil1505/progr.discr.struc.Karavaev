#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

//роверки числа на простоту
bool isPrime(long long n) {
    if (n <= 1) return false;
    for (long long i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}


//генерации случайного числа в диапазоне от 1 до max
long long genRand(long long max) {
    return rand() % max + 1;
}


//функция быстрого возведения в степень по модулю
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;  
    while (exp > 0) {
        if (exp % 2 == 1) {  
            result = (result * base) % mod;
        }
        base = (base * base) % mod;  
        exp = exp / 2;  
    }
    return result;
}

//функция для выбора параметров p и g
void chooseParam(long long& p, long long& g, long long k) {
    // Шаг 1 генерация простого числа q
    long long q;
    do {
        q = genRand(pow(2, k));  
    } while (!isPrime(q));

    // Шаг 2 вычисление p = 2*q + 1
    p = 2 * q + 1;

    // Шаг 3 выбор g
    g = genRand(p - 1);
    while (modExp(g, q, p) == 1) {  
        g = genRand(p - 1);
    }
}

//выполнение протокола Диффи-Хеллмана
void diffieHellmanKeyExchange(int N, int k) {
    srand(time(0));
    long long p, g;
    chooseParam(p, g, k);


    // Шаг 3 генерация секретных ключей
    vector<long long> privateKeys(N);
    vector<long long> publicKeys(N);
    for (int i = 0; i < N; ++i) {
        privateKeys[i] = genRand(pow(2, k)) % (p - 1);
    }

    // Шаг 4 вычисление публичных ключей
    for (int i = 0; i < N; ++i) {
        publicKeys[i] = modExp(g, privateKeys[i], p);
    }



    cout << "Номер абонента | Секретный ключ | Открытый ключ" << endl;
    for (int i = 0; i < N; ++i) {
        cout << i << " | " << privateKeys[i] << " | " << publicKeys[i] << endl;
    }

    // Шаг 5 вычисление общих секретных ключей для всех пар абонентов
    cout << "\nОбщие секретные ключи:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            long long Zij = modExp(publicKeys[j], privateKeys[i], p);
            long long Zji = modExp(publicKeys[i], privateKeys[j], p);

        
            cout << "Z(" << i << ", " << j << ") = " << Zij << " | Z(" << j << ", " << i << ") = " << Zji << endl;
            if (Zij != Zji) {
                cout << "ключи не совпали" << endl;
            }
        }
    }
}



int main() {
    int N, k;
    cout << "Введите количество абонентов (N): ";
    cin >> N;
    cout << "Введите длину секретных ключей (k) в битах: ";
    cin >> k;

    diffieHellmanKeyExchange(N, k);

    return 0;
}
