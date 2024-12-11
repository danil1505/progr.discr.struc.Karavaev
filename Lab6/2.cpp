#include <iostream>
#include <cmath>
using namespace std;

// Размер массива для пирамиды
const int size = 100;

// Пирамида (куча)
int pyramid[size];
int n = 0;

// Функции для работы с пирамидой
void swap(int i, int j) {
    int t = pyramid[i];
    pyramid[i] = pyramid[j];
    pyramid[j] = t;
}

void add(int x) {
    if (n >= size) {
        cout << "Нет места в пирамиде!\n";
        return;
    }
    pyramid[n] = x;
    int i = n;
    n++;
    while (i > 0 && pyramid[i] > pyramid[(i - 1) / 2]) {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

int top() {
    if (n > 0) return pyramid[0];
    else {
        cout << "Пирамида пуста!\n";
        return -1;
    }
}

void pop() {
    if (n <= 0) {
        cout << "Пирамида пуста!\n";
        return;
    }
    pyramid[0] = pyramid[n - 1];
    n--;
    int i = 0;

    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < n && pyramid[left] > pyramid[largest]) largest = left;
        if (right < n && pyramid[right] > pyramid[largest]) largest = right;

        if (largest != i) {
            swap(i, largest);
            i = largest;
        } else break;
    }
}

// Функция для сортировки массива с использованием пирамиды
void heapSort(int arr[], int size) {
    // Добавление всех элементов массива в пирамиду
    for (int i = 0; i < size; i++) {
        add(arr[i]);
    }

    // Извлечение элементов из пирамиды и запись их обратно в массив
    for (int i = size - 1; i >= 0; i--) {
        arr[i] = top();
        pop();
    }
}

// Инициализация массива
void initArray(int arr[], int size) {
    cout << "Введите " << size << " элементов массива: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

// Вывод массива
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10];
    int size = 10;

    // Инициализация массива
    initArray(arr, size);

    // Пирамидальная сортировка
    heapSort(arr, size);

    // Вывод отсортированного массива
    cout << "Отсортированный массив: ";
    displayArray(arr, size);

    return 0;
}
