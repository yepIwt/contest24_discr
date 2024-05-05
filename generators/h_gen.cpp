#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#include <fstream>
#include <random>

using namespace std;

// https://informatics.msk.ru/mod/statements/view.php?id=218#1


const int MAX_WEIGHT = 1000000;
const int MAX_N = 50;

// Генерация случайного числа в диапазоне [min, max]
int random(int min, int max) {
    static mt19937 mt(time(nullptr));
    uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}

const int INF = numeric_limits<int>::max(); // Используем константу для представления бесконечности

int dijkstra(const vector<vector<int>>& graph, int source, int target) {
    int n = graph.size();
    vector<int> dist(n, INF); // Инициализируем расстояния до всех вершин бесконечностью
    dist[source] = 0; // Расстояние от исходной вершины до самой себя равно 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Очередь с приоритетом

    pq.push({ 0, source }); // Добавляем исходную вершину в очередь

    while (!pq.empty()) {
        int u = pq.top().second; // Получаем вершину с наименьшим расстоянием из очереди
        pq.pop();

        // Проверяем все смежные вершины
        for (int v = 0; v < n; ++v) {
            // Если есть ребро между вершинами u и v
            if (graph[u][v] != -1) {
                // Пытаемся улучшить расстояние до вершины v, используя вершину u
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    pq.push({ dist[v], v });
                }
            }
        }
    }

    return (dist[target] == INF) ? -1 : dist[target]; // Возвращаем минимальное расстояние до целевой вершины
}

int main() {
    int N, s, t;
    for (int testNum = 1; testNum <= 12; testNum++) {
        std::string filename = "tests\\";
        if (testNum < 10) filename += "0";
        string inputFilename = filename + to_string(testNum);
        string outputFilename = inputFilename + ".a";
        
        ofstream inputFile(inputFilename);
        ofstream outputFile(outputFilename);

        int N = random(2, MAX_N); // Генерация случайного количества вершин
        int s = random(1, N); // Генерация случайной начальной вершины
        int t = random(1, N); // Генерация случайной конечной вершины
        while (s == t) { // Гарантируем различие начальной и конечной вершин
            t = random(1, N);
        }

        inputFile << N << " " << s << " " << t << endl;;

        vector<vector<int>> graph(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) {
                    inputFile << "0 ";
                    graph[i][j] = 0;
                }
                else
                {
                    int weight = random(-1, MAX_WEIGHT);
                    inputFile << weight << " ";
                    graph[i][j] = weight;

                };
            }
            inputFile << endl;
        }

        int shortest_path_length = dijkstra(graph, s - 1, t - 1);
        outputFile << shortest_path_length << endl;
    }

    return 0;
}
