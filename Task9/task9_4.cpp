#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAXN = 100; // максимальное число вершин в графе

vector<int> g[MAXN]; // граф в виде списков смежности
bool visited[MAXN]; 
int parent[MAXN]; 

bool dfs(int v, int p, stack<int>& path) {
    visited[v] = true;
    parent[v] = p;
    path.push(v);
    for (int u : g[v]) {
        if (!visited[u]) {
            if (dfs(u, v, path)) {
                return true;
            }
        } else if (u != p) {
            // найден цикл
            vector<int> cycle;
            while (!path.empty() && path.top() != u) {
                cycle.push_back(path.top());
                path.pop();
            }
            cycle.push_back(u);
            cout << "nashli cikl: ";
            for (int x : cycle) {
                cout << x << " ";
            }
            cout << endl;
            return true;
        }
    }
    path.pop();
    return false;
}

int main() {
    int n, m;
    cout<<"vvedite kolvo vershin: ";
    cin >> n;
    cout<<endl;
    cout<<"vvedite kolvo reber: ";
    cin >> m;
    cout<<endl;
    for (int i = 0; i < m; i++) {
        int u, v; // ребро между вершинами u и v
        cout<<"vvedite konci rebra: "<<endl;
        cin >> u >> v;
        cout<<endl;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int v = 0; v < n; v++) {
        if (!visited[v]) {
            stack<int> path;
            dfs(v, -1, path);
        }
    }
    return 0;
}