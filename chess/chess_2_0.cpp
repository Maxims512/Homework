#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 8;

int dx[N] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[N] = {1, 2, 2, 1, -1, -2, -2, -1};

int get_index(char c) {
    return c - 'A';
}

bool is_valid(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

void print_path(vector<pair<int, int>> &path) {
    for (int i = path.size() - 1; i >= 0; i--) {
        char c = path[i].second + 'A';
        cout << c << path[i].first + 1 << " ";
    }
    cout << endl;
}

void bfs(int x, int y, int x1, int y1) {
    bool visited[8][8];
    vector<pair<int, int>> path[8][8];
    memset(visited, false, sizeof visited);
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < N; i++) {
            int x2 = cur.first + dx[i];
            int y2 = cur.second + dy[i];
            if (is_valid(x2, y2) && !visited[x2][y2]) {
                q.push({x2, y2});
                visited[x2][y2] = true;
                path[x2][y2] = path[cur.first][cur.second];
                path[x2][y2].push_back({cur.first, cur.second});
                if (x2 == x1 && y2 == y1) {
                    cout<<endl<<x2<<" "<<y2<<endl;
                    print_path(path[x2][y2]);
                    return;
                }
            }
        }
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int x1 = get_index(s1[0]), y1 = s1[1] - '1';
    int x2 = get_index(s2[0]), y2 = s2[1] - '1';
    bfs(x1, y1, x2, y2);
    return 0;
}