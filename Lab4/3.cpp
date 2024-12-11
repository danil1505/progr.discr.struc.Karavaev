#include <iostream>
using namespace std;

//рекурсивная функция возведения числа в степень
int power(int base, int exponent) {
    if (exponent == 0) {
        return 1; //базовый случай: любое число в степени 0 равно 1
    }
    if (exponent < 0) {
        return 1 / power(base, -exponent); //обработка отриц степеней
    }
    return base * power(base, exponent - 1); //рекурсивный вызов
}

int main() {
    int base = 2;
    int exponent = 5;
    
    cout << base << " ^ " << exponent << " = " << power(base, exponent) << endl;

    exponent = -3;
    cout << base << " ^ " << exponent << " = " << power(base, exponent) << endl;

    return 0;
}
