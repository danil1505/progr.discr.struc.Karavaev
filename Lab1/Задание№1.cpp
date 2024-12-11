#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция для последовательного поиска
int sequentialSearch(const vector<int>& arr, int x, int& comparisons) {
    comparisons = 0;
    for (int i = 0; i < arr.size(); i++) {
        comparisons++;
        if (arr[i] == x) return i;
    }
    return -1;
}

// Функция для двоичного поиска
int binarySearch(const vector<int>& arr, int x, int& comparisons) {
    int left = 0, right = arr.size() - 1;
    comparisons = 0;
    while (left <= right) {
        comparisons++;
        int middle = left + (right - left) / 2;
        if (arr[middle] == x) return middle;
        else if (arr[middle] < x) left = middle + 1;
        else right = middle - 1;
    }
    return -1;
}

int main() {
    srand(time(0));

    const int step = 20;
    const int maxSize = 500;
    const int trials = 5;

    // Заголовок таблицы
    cout << "Размер массива (N) | Среднее кол-во сравнений (последовательный) | Среднее кол-во сравнений (двоичный)" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;

    // Увеличиваем размер массива от 20 до 500 с шагом в 20
    for (int size = step; size <= maxSize; size += step) {
        double avgSequential = 0, avgBinary = 0;

        for (int t = 0; t < trials; t++) {
            // Генерация массива случайных чисел
            vector<int> arr(size);
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 100;
            }

            // Сортировка массива для двоичного поиска
            sort(arr.begin(), arr.end());

            // Случайный выбор элемента для поиска
            int target = rand() % 100;

            // Счетчики сравнений
            int comparisonsSequential = 0, comparisonsBinary = 0;

            // Последовательный поиск
            sequentialSearch(arr, target, comparisonsSequential);
            avgSequential += comparisonsSequential;

            // Двоичный поиск
            binarySearch(arr, target, comparisonsBinary);
            avgBinary += comparisonsBinary;
        }

        // Вывод результатов для текущего размера массива
        cout << size << "               | "
             << avgSequential / trials << "                                   | "
             << avgBinary / trials << endl;
    }

    return 0;
}
