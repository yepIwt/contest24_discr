#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

// https://informatics.msk.ru/mod/statements/view.php?id=262&chapterid=2783#1

const int INF = 1e9;

int n, m;
vector<vector<int>> capacity;
vector<vector<int>> residual_capacity;
vector<int> parent;

bool bfs(int source, int sink) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent.assign(n + 1, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 1; v <= n; ++v) {
            if (!visited[v] && residual_capacity[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[sink];
}

int fordFulkerson(int source, int sink) {
    residual_capacity = capacity;

    int maxFlow = 0;

    while (bfs(source, sink)) {
        int pathFlow = INF;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residual_capacity[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residual_capacity[u][v] -= pathFlow;
            residual_capacity[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    cin >> n >> m;

    capacity.assign(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        capacity[a][b] = c;
    }

    int maxFlow = fordFulkerson(1, n);
    cout << maxFlow << endl;

    return 0;
}
