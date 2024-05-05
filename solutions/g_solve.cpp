#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// https://informatics.msk.ru/mod/statements/view.php?id=193#1


const int INF = numeric_limits<int>::max();

int main() {
    int N, S, F;
    cin >> N >> S >> F;

    vector<vector<int>> graph(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> graph[i][j];
        }
    }

    --S;
    --F;

    vector<int> distance(N, INF);
    vector<bool> visited(N, false);

    distance[S] = 0;

    for (int i = 0; i < N; ++i) {
        int minDistance = INF, minIndex = -1;

        for (int j = 0; j < N; ++j) {
            if (!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                minIndex = j;
            }
        }

        if (minIndex == -1) break;

        visited[minIndex] = true;

        for (int j = 0; j < N; ++j) {
            if (graph[minIndex][j] != -1 && distance[minIndex] + graph[minIndex][j] < distance[j]) {
                distance[j] = distance[minIndex] + graph[minIndex][j];
            }
        }
    }

    if (distance[F] == INF)
        cout << -1 << endl;
    else
        cout << distance[F] << endl;

    return 0;
}
