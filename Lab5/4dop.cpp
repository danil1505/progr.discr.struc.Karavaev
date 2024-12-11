#include <iostream>
#include <vector>

using namespace std;

// Функция для выполнения обхода графа в глубину и построения каркасного дерева
void dfs_tree(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<pair<int, int>>& tree_edges) {
    visited[node] = true;

    // Идем по всем соседям текущей вершины
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            tree_edges.push_back({node, neighbor});
            dfs_tree(neighbor, adj, visited, tree_edges);
        }
    }
}

int main() {
    int n = 6;  // Количество вершин в графе
    vector<vector<int>> adj = {
        {1, 2},    // Вершина 0 соединена с 1 и 2
        {0, 3, 4}, // Вершина 1 соединена с 0, 3 и 4
        {0, 4},    // Вершина 2 соединена с 0 и 4
        {1},       // Вершина 3 соединена с 1
        {1, 2},    // Вершина 4 соединена с 1 и 2
        {2}        // Вершина 5 соединена с 2
    };

    // Выводим связи вершин графа
    cout << "Вершины графа и их связи:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Вершина " << i << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    // Цикл обхода для каждой вершины
    for (int start = 0; start < n; start++) {
        cout << "\nНачало обхода DFS для построения каркасного дерева с вершины " << start << ":\n";

        vector<bool> visited(n, false); // Массив для отслеживания посещенных вершин
        vector<pair<int, int>> tree_edges; // Для хранения ребер каркасного дерева

        dfs_tree(start, adj, visited, tree_edges); // Запускаем DFS для построения каркаса

        // Выводим ребра каркасного дерева
        cout << "\nРебра каркасного дерева:\n";
        for (const auto& edge : tree_edges) {
            cout << edge.first << " - " << edge.second << endl;
        }
    }

    return 0;
}
