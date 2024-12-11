#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//функция для последовательного поиска элемента в массиве
int seqser(const vector<int>& arr, int x, int& comparisons) {
    comparisons = 0; 
    for (int i = 0; i < arr.size(); i++) {
        comparisons++;
        if (arr[i] == x) {
            return i; 
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
        int target = rand() % 100;

    
    
            int comparisons = 0;
        int index = seqser(arr, target, comparisons);

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
