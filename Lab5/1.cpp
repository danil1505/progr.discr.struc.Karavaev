#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Функция для выполнения обхода графа в ширину
void bfs(int start, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false); 
    queue<int> q; //очередь для BFS

    visited[start] = true; //отмечаем стартовую вершину как посещенную
    q.push(start);
    cout << "Обход графа в ширину, начиная с вершины " << start << ": ";


    //выполняем обход, пока очередь не станет пустой
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " "; 



        //проходим по всем соседям текущей вершины
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) { 
                visited[neighbor] = true; 
                q.push(neighbor); 
            }
        }
    }
    cout << endl;
}



int main() {
    int n = 5;
    vector<vector<int>> adj = {
        {1, 2},    //вершина 0 соединена с вершинами 1 и 2
        {0, 3, 4}, //вершина 1 соединена с вершинами 0, 3 и 4
        {0, 4},    //вершина 2 соединена с вершинами 0 и 4
        {1},       //вершина 3 соединена с вершиной 1
        {1, 2}     //вершина 4 соединена с вершинами 1 и 2
    };

    int start = 0; //стартовая вершина
    
    
    cout << "Вершины графа и их соседние вершины:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Вершина " << i << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    cout << "\nНачало обхода BFS с вершины " << start << ":\n";
    bfs(start, adj);

    return 0;
}
