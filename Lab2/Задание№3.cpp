#include <iostream>
#include <vector>
#include <algorithm> 
#include <cstdlib>
#include <ctime>

using namespace std;


//функция для последовательного поиска элемента
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


//функция для двоичного поиска элемента
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
    const int step = 20;
    const int maxSize = 500;
    cout << "Размер массива (N) | Последовательный поиск | Двоичного поиск" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;

    for (int size = step; size <= maxSize; size += step) {
        vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100; 
        }
        sort(arr.begin(), arr.end());  //сортировка массива для двоичного поиска
        int target = rand() % 100;

        //оследовательный поиск
        int compseq = 0;
        seqser(arr, target, compseq);

        //двоичный поиск
        int compbin = 0;
        binser(arr, target, compbin);
        
        cout << size << "                | " 
             << compseq << "                       | " 
             << compbin << endl;
    }

    return 0;
}
