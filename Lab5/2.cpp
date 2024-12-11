#include <iostream>
#include <vector>

using namespace std;

//функция для выполнения обхода графа в глубину
void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true; 
    cout << node << " "; 


    //проходим по всем соседям текущей вершины
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}



int main() {
    int n = 5; 
    vector<vector<int>> adj = {
        {1, 2},    //вершина 0 соединена с 1 и 2
        {0, 3, 4}, //вершина 1 соединена с 0, 3 и 4
        {0, 4},    //вершина 2 соединена с 0 и 4
        {1},       //ершина 3 соединена с 1
        {1, 2}     //вершина 4 соединена с 1 и 2
    };


    int start = 0; //начаная вершина для обхода
    cout << "Вершины графа и их связи:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Вершина " << i << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }


    cout << "\nНачало обхода DFS с вершины " << start << ":\n";
    vector<bool> visited(n, false);
    dfs(start, adj, visited); 
    cout << endl;

    return 0;
}
