#include <iostream>
#include <cmath>
using namespace std;

//функция для быстрого возведения в степень по модулю
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



//еализация обмена ключами по Диффи-Хеллману
void diffieHellmanKeyExchange() {
    long long p, g, privateA, privateB;
    cout << "Введите простое число (p): ";
    cin >> p;
    cout << "Введите первообразный корень (g): ";
    cin >> g;
    cout << "Введите приватный ключ пользователя A: ";
    cin >> privateA;
    cout << "Введите приватный ключ пользователя B: ";
    cin >> privateB;
    if (privateA >= p || privateB >= p) {
        cout << "Приватные ключи должны быть меньше p!" << endl;
        return;
    }

    //вычисление публичных ключей
    long long publicA = modExp(g, privateA, p);
    long long publicB = modExp(g, privateB, p);

    //вычисление общего секретного ключа
    long long sharedKeyA = modExp(publicB, privateA, p);
    long long sharedKeyB = modExp(publicA, privateB, p);


    cout << "Публичный ключ A: " << publicA << endl;
    cout << "Публичный ключ B: " << publicB << endl;
    cout << "Общий секретный ключ, рассчитанный A: " << sharedKeyA << endl;
    cout << "Общий секретный ключ, рассчитанный B: " << sharedKeyB << endl;

    //проверка, совпадают ли вычисленные ключи
    if (sharedKeyA == sharedKeyB) {
        cout << "Общий секретный ключ совпадает: " << sharedKeyA << endl;
    } else {
        cout << "Ошибка! Ключи не совпали." << endl;
    }
}

int main() {
    diffieHellmanKeyExchange();
    return 0;
}
