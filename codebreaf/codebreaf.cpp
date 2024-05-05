#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// https://informatics.msk.ru/mod/statements/view.php?id=260#1


const int INF = 30000;

struct Edge {
    int to;
    int weight;
};

void shortestPaths(int N, const vector<vector<Edge>>& graph, vector<int>& distances) {
    distances.assign(N, INF);
    distances[0] = 0; // Начальная вершина

    for (int i = 0; i < N - 1; ++i) {
        for (int u = 0; u < N; ++u) {
            for (const Edge& e : graph[u]) {
                if (distances[u] != INF && distances[e.to] > distances[u] + e.weight) {
                    distances[e.to] = distances[u] + e.weight;
                }
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> graph(N);
    for (int i = 0; i < M; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from - 1].push_back({ to - 1, weight });
    }

    vector<int> distances;
    shortestPaths(N, graph, distances);

    for (int i = 0; i < N; ++i) {
        if (distances[i] == INF) {
            cout << "30000 ";
        }
        else {
            cout << distances[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
