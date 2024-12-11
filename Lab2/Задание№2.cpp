#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

//функция для двоичного поиска элемента в массиве
int binser(const vector<int>& arr, int x, int& comparisons) {
    int left = 0;
    int right = arr.size() - 1;
    comparisons = 0; 
    while (left <= right) {
        comparisons++;
        int middle = left + (right - left) / 2;

        if (arr[middle] == x) {
            return middle;
        }
        if (arr[middle] < x) {
            left = middle + 1; 
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int main() {
    srand(time(0));
    vector<int> sizes = {20, 40, 60, 80, 100, 200, 500};
    for (int size : sizes) {
        vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100;
        }

        //сортируем массив для двоичного поиска
        sort(arr.begin(), arr.end());
        int target = rand() % 100;
        int comparisons = 0;
        int index = binser(arr, target, comparisons);
        cout << "Размер массива: " << size << endl;
        cout << "Искомый элемент: " << target << endl;
        if (index != -1) {
            cout << "Элемент найден на позиции: " << index << endl;
        } else {
            cout << "Элемент не найден" << endl;
        }
        cout << "Количество выполненных сравнений: " << comparisons << endl;
        cout << "------------------------------------" << endl;
    }

    return 0;
}
