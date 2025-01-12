#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Element {
    int item;
    Element* next;
};

const int SIZE = 10; // Размер хеш-таблицы
Element* hashTable[SIZE];

// Инициализация хеш-таблицы
void init() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = nullptr;
    }
}

// Создание нового элемента
Element* createElement(int x) {
    Element* newElement = new Element;
    newElement->item = x;
    newElement->next = nullptr;
    return newElement;
}

// Хеш-функция
int hashFunc(int x) {
    return x % SIZE; // Остаток от деления на размер таблицы
}

// Добавление элемента в хеш-таблицу
void add(int x) {
    int h = hashFunc(x); // Вычисляем хеш
    Element* newElement = createElement(x);
    if (hashTable[h] == nullptr) {
        hashTable[h] = newElement; // Если ячейка пуста, добавляем элемент
    } else {
        Element* temp = hashTable[h];
        while (temp->next != nullptr) { // Проходим по цепочке
            if (temp->item == x) {
                delete newElement; // Если элемент уже существует, выходим
                return;
            }
            temp = temp->next;
        }
        if (temp->item != x) {
            temp->next = newElement; // Добавляем элемент в конец цепочки
        } else {
            delete newElement; // Если элемент уже есть, удаляем новый
        }
    }
}

// Удаление элемента из хеш-таблицы
void remove(int x) {
    int h = hashFunc(x); // Вычисляем хеш
    Element* temp = hashTable[h];
    Element* prev = nullptr;

    while (temp != nullptr) { // Проходим по цепочке
        if (temp->item == x) {
            if (prev == nullptr) {
                hashTable[h] = temp->next; // Удаляем первый элемент в цепочке
            } else {
                prev->next = temp->next; // Пропускаем найденный элемент
            }
            delete temp; // Удаляем элемент
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Элемент " << x << " не найден." << endl;
}

// Поиск элемента в хеш-таблице
bool search(int x) {
    int h = hashFunc(x); // Вычисляем хеш
    Element* temp = hashTable[h];
    while (temp != nullptr) { // Проходим по цепочке
        if (temp->item == x) {
            return true; // Элемент найден
        }
        temp = temp->next;
    }
    return false; // Элемент не найден
}

// Вывод цепочки
void displayChain(Element* chain) {
    Element* temp = chain;
    while (temp != nullptr) { // Проходим по цепочке
        cout << temp->item << " -> ";
        temp = temp->next;
    }
    cout << " "; // Конец цепочки
}

// Вывод всей хеш-таблицы
void displayTable() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << " -> ";
        displayChain(hashTable[i]); // Вывод цепочки для текущей ячейки
        cout << endl;
    }
}

// Генерация массива случайных чисел
void generateRandomElements(int* elements, int count, int maxValue) {
    for (int i = 0; i < count; i++) {
        elements[i] = rand() % maxValue; // Генерация случайного числа от 0 до maxValue
    }
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел
    init(); // Инициализация хеш-таблицы

    // Генерация случайных элементов
    const int elementCount = 15; // Количество элементов
    const int maxValue = 100;    // Максимальное значение элемента
    int elements[elementCount];
    generateRandomElements(elements, elementCount, maxValue); // Генерация массива

    // Добавление элементов в хеш-таблицу
    for (int x : elements) {
        add(x);
    }

    // Вывод сгенерированных элементов
    cout << "Сгенерированные элементы: ";
    for (int x : elements) {
        cout << x << " ";
    }
    cout << endl;

    // Вывод хеш-таблицы
    cout << "Содержимое хеш-таблицы:" << endl;
    displayTable();

    // Пример: поиск элемента
    int searchElement = elements[rand() % elementCount]; // Выбираем случайный элемент из массива
    if (search(searchElement)) {
        cout << "\nЭлемент " << searchElement << " найден в хеш-таблице." << endl;
    } else {
        cout << "\nЭлемент " << searchElement << " не найден в хеш-таблице." << endl;
    }

    // Пример: удаление элемента
    int removeElement = elements[rand() % elementCount]; // Выбираем случайный элемент для удаления
    remove(removeElement);
    cout << "\nПосле удаления элемента " << removeElement << ":" << endl;
    displayTable();

    return 0;
}
