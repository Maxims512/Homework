#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int hod_x[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int hod_y[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int dis[8][8];
int pre[8][8];
char A[3], B[3];

void bfs(int x, int y, int z, int u) {
    memset(dis, -1, sizeof(dis));
    memset(pre, -1, sizeof(pre));
    queue<pair<int, int>> q;
    q.push({x, y});
    dis[x][y] = 0;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int xx = t.first + hod_x[i];
            int yy = t.second + hod_y[i];

            if (xx < 0 || xx >= 8 || yy < 0 || yy >= 8) continue;

            if (dis[xx][yy] != -1) continue;

            dis[xx][yy] = dis[t.first][t.second] + 1;
            pre[xx][yy] = i;
            q.push({xx, yy});
        }
    }
}

int main() {
    cin >> A >> B;
    int x = A[0] - 'A';
    int y = A[1] - '1';
    int z = B[0] - 'A';
    int u = B[1] - '1';
    bfs(x, y, z, u);
    string answer;

    while (x != z || y != u) {
        int i = pre[z][u];
        char cx = 'A' + z, cy = '1' + u;
        answer = cx + string(1, cy) + " " + answer;
        z -= hod_x[i];
        u -= hod_y[i];
    }

    char nach_x = 'A' + z;
    char nach_y = '1' + u;
    answer =nach_x + string(1, nach_y) + " " + answer;
    cout << answer << endl;
}