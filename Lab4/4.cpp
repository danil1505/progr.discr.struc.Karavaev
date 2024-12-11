#include <iostream>
#include <vector>

using namespace std;

//рекурсивная реализация без оптимизации
int fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

//пекурсивная реализация с кеш-памятью (мемоизация)
int fibonacci_recursive_memo(int n, std::vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fibonacci_recursive_memo(n - 1, memo) + fibonacci_recursive_memo(n - 2, memo);
    return memo[n];
}

//итеративная реализация с временным массивом
int fibonacci_iterative_with_array(int n) {
    if (n <= 1) return n;
    std::vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

//итеративная реализация с вычислением “на лету” (без использования массива)
int fibonacci_iterative_in_place(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1;

    for (int i = 2; i <= n; ++i) {
        int temp = a + b;
        a = b;
        b = temp; //обновляем значения без использования массива
    }
    return b;
}

int main() {
    int n = 10;

    std::cout << "Рекурсивно без оптимизации: " << fibonacci_recursive(n) << std::endl;
    std::vector<int> memo(n + 1, -1); 
    std::cout << "Рекурсивно с мемоизацией: " << fibonacci_recursive_memo(n, memo) << std::endl;
    std::cout << "Итеративно с массивом: " << fibonacci_iterative_with_array(n) << std::endl;
    std::cout << "Итеративно в месте (на лету): " << fibonacci_iterative_in_place(n) << std::endl;

    return 0;
}
