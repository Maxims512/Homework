#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

//обход графа в ширину
void BFS(vector<vector<int>> adj_list, int start_node) {
    //вектор чтобы отмечать посещенные вершины
    vector<bool> visited(adj_list.size(), false); //1-размер, 2-чем сначало заполнен
    queue<int> q;

    visited[start_node] = true;
    q.push(start_node);

    while(!q.empty()) {
        int curr_node = q.front();
        q.pop();
        cout << curr_node << " ";

        for(int adj_node : adj_list[curr_node]) {
            if(!visited[adj_node]) {
                visited[adj_node] = true;
                q.push(adj_node);
            }
        }
    }
}

//обход графа в глубину
void DFS(vector<vector<int>> adj_list, int start_node) {
    vector<bool> visited(adj_list.size(), false);
    stack<int> s;

    visited[start_node] = true;
    s.push(start_node);

    while(!s.empty()) {
        int curr_node = s.top();
        s.pop();
        cout << curr_node << " ";

        for(int adj_node : adj_list[curr_node]) {
            if(!visited[adj_node]) {
                visited[adj_node] = true;
                s.push(adj_node);
            }
        }
    }
}

int main() {
    //Пример списка смежности для графа с 6 узлами и 7 ребрами
    vector<vector<int>> adj_list = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 4},
        {1, 4, 5},
        {2, 3},
        {3}
    };

    // Выполнить BFS, начиная с узла 0
    cout << "BFS: ";
    BFS(adj_list, 5);
    cout << endl;

    // Выполнить DFS, начиная с узла 0 
    cout << "DFS: ";
    DFS(adj_list, 5);
    cout << endl;

    return 0;
}