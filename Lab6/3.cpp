#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

// Структура для Union-Find (система непересекающихся множеств)
class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // Сжатие пути
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false; // Уже в одном множестве
        if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

// Структура для хранения ребра
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight; // Для минимальной кучи
    }
};

// Класс для минимальной кучи
class MinHeap {
    vector<Edge> heap;

    void heapifyUp(int idx) {
        while (idx > 0 && heap[idx] < heap[(idx - 1) / 2]) {
            swap(heap[idx], heap[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    void heapifyDown(int idx) {
        int smallest = idx;
        int left = 2 * idx + 1, right = 2 * idx + 2;

        if (left < heap.size() && heap[left] < heap[smallest]) smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest]) smallest = right;

        if (smallest != idx) {
            swap(heap[idx], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void push(Edge edge) {
        heap.push_back(edge);
        heapifyUp(heap.size() - 1);
    }

    Edge top() {
        return heap[0];
    }

    void pop() {
        swap(heap[0], heap.back());
        heap.pop_back();
        heapifyDown(0);
    }

    bool empty() {
        return heap.empty();
    }

    // Функция для получения всех ребер пирамиды
    vector<Edge> getAllEdges() {
        return heap;
    }
};

// Алгоритм Крускала с использованием пирамиды
void kruskal(int V, vector<tuple<int, int, int>>& edges) {
    UnionFind uf(V);
    MinHeap heap;
    vector<Edge> mst;

    // Добавление всех ребер в пирамиду
    for (auto& edge : edges) {
        int u = std::get<0>(edge);
        int v = std::get<1>(edge);
        int weight = std::get<2>(edge);
        heap.push({u, v, weight});
    }

    // Пока пирамида не пуста и MST не завершен
    while (!heap.empty() && mst.size() < V - 1) {
        Edge edge = heap.top();
        heap.pop();

        // Если ребро не создает цикл, добавляем его в MST
        if (uf.unite(edge.u, edge.v)) {
            mst.push_back(edge);
        }
    }

    // Вывод результата
    cout << "Минимальный остов содержит ребра:\n";
    for (auto edge : mst) {
        cout << edge.u << " - " << edge.v << " (вес: " << edge.weight << ")\n";
    }
}

// Функции для добавления и удаления ребер в пирамиду
void removeMinEdge(MinHeap& heap) {
    if (!heap.empty()) {
        Edge minEdge = heap.top();
        cout << "Удалено ребро с минимальным весом: "
             << minEdge.u << " - " << minEdge.v
             << " (вес: " << minEdge.weight << ")\n";
        heap.pop();
    } else {
        cout << "Пирамида пуста, нет ребер для удаления.\n";
    }
}

void displayHeap(MinHeap& heap) {
    cout << "Ребра в пирамиде:\n";
    vector<Edge> allEdges = heap.getAllEdges();
    for (auto& edge : allEdges) {
        cout << edge.u << " - " << edge.v << " (вес: " << edge.weight << ")\n";
    }
}

int main() {
    // Количество вершин и начальные ребра
    int V = 9;
    vector<tuple<int, int, int>> edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11},
        {2, 3, 7}, {2, 8, 2}, {2, 5, 4}, {3, 4, 9},
        {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1},
        {6, 8, 6}, {7, 8, 7}
    };

    MinHeap heap;
    // Добавление всех ребер в пирамиду
    for (auto& edge : edges) {
        int u = std::get<0>(edge);
        int v = std::get<1>(edge);
        int weight = std::get<2>(edge);
        heap.push({u, v, weight});
    }

    // Меню для работы с пирамидой
    int option;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Удалить ребро с минимальным весом\n";
        cout << "2. Показать все ребра в пирамиде\n";
        cout << "3. Завершить выполнение программы\n";
        cout << "Выберите опцию: ";
        cin >> option;

        switch (option) {
            case 1:
                removeMinEdge(heap);
                break;
            case 2:
                displayHeap(heap);
                break;
            case 3:
                cout << "Выход...\n";
                return 0;
            default:
                cout << "Неверный выбор! Попробуйте снова.\n";
        }
    }

    return 0;
}
