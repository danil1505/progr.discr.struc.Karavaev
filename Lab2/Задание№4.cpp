#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

//функция пузырьковой сортировки с подсчетом кол срав
int bubbleSort(vector<int>& arr) {
    int n = arr.size();
    int comparisons = 0; 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return comparisons;
}

//последовательный поиск с подсчетом кол срав
int seqSearch(const vector<int>& arr, int target) {
    int comparisons = 0;
    for (int item : arr) {
        comparisons++;
        if (item == target) {
            return comparisons; 
        }
    }
    return comparisons; 
}


//двоичный поиск с подсчетом кол срав
int benSearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int comparisons = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (arr[mid] == target) {
            return comparisons;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return comparisons;
}



//функция для моделирования поиска при разных кол запросов K
void modelSearch(int N, int K) {
    vector<int> array(N); //генерируем случайный массив из N элементов
    for (int i = 0; i < N; ++i) {
        array[i] = rand() % 1000 + 1;
    }
    int target = array[rand() % N]; // рандомом выбираем цель из массива

    //копируем массив для сортировки
    vector<int> sortedArray = array;
    int sortComparisons = bubbleSort(sortedArray);

    //подсчет сравнений последовательным поиском
    int seqTotal = 0;
    for (int i = 0; i < K; ++i) {
        seqTotal += seqSearch(array, target);
    }

    //подсчет сравнений для K двоичных поисков после сортировки
    int binTotal = sortComparisons;
    for (int i = 0; i < K; ++i) {
        binTotal += benSearch(sortedArray, target);
    }
    cout << "N = " << N << ", K = " << K << "\n";
    cout << "Сравнений в последовательном поиске: " << seqTotal << "\n";
    cout << "Сравнений в двоичном поиске после сортировки: " << binTotal << "\n";

    //определяем эффективного метода
    if (binTotal < seqTotal) {
        cout << "Двоичный поиск с предварительной сортировкой эффективнее при K = " << K << "\n";
    } else {
        cout << "Последовательный поиск эффективнее при K = " << K << "\n";
    }
    cout << "------------------------------------\n";
}

int main() {
    srand(time(0));
    int N = 100; 
    for (int K = 1; K <= 200; K += 20) { //ест для разных значений K
        modelSearch(N, K);
    }

    return 0;
}
