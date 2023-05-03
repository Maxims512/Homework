#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1000; // максимальное число вершин в графе

vector<int> g[MAXN]; // граф в виде списков смежности
vector<int> sources; // список истоков графа

void print(vector<int> vec){
    for (int i=0; i < vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void BFS(int kolvo_versh, int start_node) {
    //вектор чтобы отмечать посещенные вершины
    vector<bool> visited(kolvo_versh, false); //1-размер, 2-чем сначало заполнен
    queue<int> q;

    visited[start_node] = true;
    q.push(start_node);

    while(!q.empty()) {
        int curr_node = q.front();
        q.pop();
        int k;
        for(int node : g[curr_node]) {
            if(!visited[node]) {
                visited[node] = true;
                q.push(node);
            }
        }
        if (g[curr_node].size()==kolvo_versh-1){
            cout<<curr_node<<" ";
        }
    }
}

int main() {
    int n, m;
    cout<<"vvedite kolvo vershin: ";
    cin >> n;
    cout<<endl;
    cout<<"vvedite kolvo reber: ";
    cin >> m;
    cout<<endl;
    int u, v; // ребро между вершинами u и v
    for (int i = 0; i < m; i++) {
        cout<<"vvedite konci rebra: "<<endl;
        cin >> u >> v;
        cout<<endl;
        g[u].push_back(v);
        u=v=0;
    }
    cout<<"istoki grafa: ";
    BFS(n, u);
}