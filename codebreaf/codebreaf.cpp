#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <queue>

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

void generateTest(string filename) {
    ofstream file(filename);

    // Генерация случайного числа вершин и рёбер
    n = 2 + rand() % 9;
    m = 1 + rand() % (n * (n - 1));

    file << n << " " << m << endl;

    capacity.assign(n + 1, vector<int>(n + 1, 0));

    // Генерация случайных рёбер с пропускными способностями
    for (int i = 0; i < m; ++i) {
        int a = 1 + rand() % n;
        int b = 1 + rand() % n;
        while (a == b) {
            b = 1 + rand() % n;
        }
        int c = 1 + rand() % 100;
        capacity[a][b] = c;
        file << a << " " << b << " " << c << endl;
    }

    file.close();

    // Вычисление максимального потока с помощью предложенного решения
    int maxFlow = fordFulkerson(1, n);

    // Запись результата в файл
    ofstream outputFile(filename + ".a");
    outputFile << maxFlow << endl;
    outputFile.close();

}

int main() {
    // Инициализация генератора случайных чисел
    srand(time(0));

    // Генерация 11 тестов
    for (int i = 1; i <= 23; ++i) {

        string filename = "tests\\";
        if (i < 10) filename += "0"; 
        filename += to_string(i);
        generateTest(filename);
    }

    return 0;
}
