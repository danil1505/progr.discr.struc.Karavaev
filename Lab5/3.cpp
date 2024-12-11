#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//функция для выполнения обхода графа в ширину и построения каркаса
void bfs_tree(int start, const vector<vector<int>>& adj, vector<pair<int, int>>& tree_edges) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q; 
    visited[start] = true; 
    q.push(start); 
    cout << "Обход графа в ширину и построение каркаса, начиная с вершины " << start << ":\n";



    //делаем обход пока очерель не пуста
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " "; 
        for (int neighbor : adj[node]) { //проходим по всем соседям текущей вершины
            if (!visited[neighbor]) { 
                visited[neighbor] = true;
                q.push(neighbor); 
                tree_edges.push_back({node, neighbor});//ребро для каркасного дерева
            }
        }
    }
    cout << endl;}

int main() {
    int n = 5;
    vector<vector<int>> adj = {
        {1, 2},    // вершина 0 соединена с 1 и 2
        {0, 3, 4}, // вершина 1 соединена с 0, 3 и 4
        {0, 4},    // вершина 2 соединена с 0 и 4
        {1},       // вершина 3 соединена с 1
        {1, 2}     // вершина 4 соединена с 1 и 2
    };
    int start = 0;
    cout << "Вершины графа и их связи:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Вершина " << i << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    cout << "\nНачало обхода BFS для построения каркаса с вершины " << start << ":\n";


    vector<pair<int, int>> tree_edges; //хранение ребера каркасного дерева
    bfs_tree(start, adj, tree_edges); //фуункцию обхода в ширину


    cout << "\nРебра каркасного дерева:\n";
    for (const auto& edge : tree_edges) {
        cout << edge.first << " - " << edge.second << endl;
    }

    return 0;
}
