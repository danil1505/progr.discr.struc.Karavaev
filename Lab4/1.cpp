#include <iostream>
#include <cmath>

using namespace std;

//функция для вычисления суммы цифр числа
int sum_of_digits(int n) {
    if (n == 0) return 0;
    return n % 10 + sum_of_digits(n / 10);
}

//функция для вычисления цифрового корня числа
int digital_root(int n) {
    if (n < 10) return n;
    return digital_root(sum_of_digits(n)); // рекурсивно находим сумму цифр, пока не получим одноцифровое число
}

//функция для вычисления факториала числа
int fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

//функция для вычисления суммы чисел от 1 до N
int sum_to_n(int n) {
    if (n <= 1) return n;
    return n + sum_to_n(n - 1);
}

int main() {
    int num = 12345;
    cout << "Сумма цифр числа " << num << " = " << sum_of_digits(num) << endl;
    cout << "Цифровой корень числа " << num << " = " << digital_root(num) << endl;

    int n = 5;
    cout << "Факториал числа " << n << " = " << fact(n) << endl;
    cout << "Сумма чисел от 1 до " << n << " = " << sum_to_n(n) << endl;

    return 0;
}
