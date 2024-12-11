#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

// Размер массива для пирамиды
const int size = 20;

// Пирамида (куча)
int pyramid[size];
int n = 0;

// Функция для создания пробелов
void makeSpaces(int sp) {
    for (int i = 0; i < sp; i++) cout << " ";
}

// Функция для отображения пирамиды
void displayPyramidTree() {
    if (n == 0) {
        cout << "\nПирамида пуста\n";
        return;
    }

    int k = 1;
    int j = 0;
    int sp = pow(2.0, log2(n));
    for (int level = 0; level <= log2(n); level++) {
        makeSpaces(sp);
        for (int i = 0; i < k && j < n; i++) {
            cout.width(2);
            cout << pyramid[j];
            makeSpaces(sp * 2 - 1);
            j++;
        }
        k *= 2;
        sp /= 2;
        cout << endl << endl;
    }
}

// Функция для обмена элементов
void swap(int i, int j) {
    int t = pyramid[i];
    pyramid[i] = pyramid[j];
    pyramid[j] = t;
}

// Функция добавления элемента в кучу
void add(int x) {
    if (n >= size) {
        cout << "\nНет места в пирамиде!\n";
        return;
    }
    n++;
    int i = n - 1;
    pyramid[i] = x;

    // Проталкивание вверх
    while (i > 0 && pyramid[i] > pyramid[(i - 1) / 2]) {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

// Функция получения максимального элемента
int getMax() {
    if (n <= 0) {
        cout << "\nПирамида пуста!\n";
        return -1;
    }
    return pyramid[0];
}

// Функция удаления максимального элемента
void deleteMax() {
    if (n <= 0) {
        cout << "\nПирамида пуста!\n";
        return;
    }
    pyramid[0] = pyramid[n - 1];
    n--;
    int i = 0;

    // Проталкивание вниз
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
    cout << "\nМаксимальный элемент удален.\n";
}

// Функция для заполнения пирамиды случайными числами
void initializePyramid() {
    srand(time(0));
    cout << "\nИнициализация пирамиды случайными числами:\n";
    for (int i = 0; i < size; i++) {
        int randomValue = rand() % 100 + 1; // Случайное число от 1 до 100
        add(randomValue);
        cout << randomValue << " ";
    }
    cout << "\n";
}

int main() {
    initializePyramid();

    int choice;
    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Добавить элемент\n";
        cout << "2. Показать пирамиду\n";
        cout << "3. Удалить максимальный элемент\n";
        cout << "4. Показать максимальный элемент\n";
        cout << "5. Выйти\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int element;
                cout << "Введите число для добавления: ";
                cin >> element;
                add(element);
                break;
            }
            case 2:
                cout << "\nПирамида:\n";
                displayPyramidTree();
                break;
            case 3:
                deleteMax();
                break;
            case 4:
                cout << "\nМаксимальный элемент: " << getMax() << endl;
                break;
            case 5:
                cout << "\nВыход...\n";
                return 0;
            default:
                cout << "\nНеверный выбор. Попробуйте снова.\n";
        }
    }
}
