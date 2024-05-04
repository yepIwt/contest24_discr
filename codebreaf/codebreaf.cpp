#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 500;
const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

int n, m;
int grid[MAXN][MAXN];
int dist[MAXN][MAXN];

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs() {
    queue<pii> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                q.push({ i, j });
                dist[i][j] = 0;
            }
            else {
                dist[i][j] = -1;
            }
        }
    }
    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int x = u.first + dx[k];
            int y = u.second + dy[k];
            if (valid(x, y) && dist[x][y] == -1) {
                dist[x][y] = dist[u.first][u.second] + 1;
                q.push({ x, y });
            }
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
