#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>

using namespace std;

// https://informatics.msk.ru/mod/statements/view.php?id=193#1

const int INF = numeric_limits<int>::max();

void generateTest(int testNumber, int N, int minWeight, int maxWeight) {
    std::string filename = "tests\\";
    if (testNumber < 10) filename += "0";

    ofstream inputFile(filename + to_string(testNumber));
    ofstream outputFile(filename + to_string(testNumber) + ".a");

    // Generate S and F
    int S = rand() % N + 1;
    int F;
    do {
        F = rand() % N + 1;
    } while (F == S);

    // Write N, S, and F to input file
    inputFile << N << " " << S << " " << F << endl;

    // Generate graph
    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                if (rand() % 2 == 0) {
                    graph[i][j] = rand() % (maxWeight - minWeight + 1) + minWeight;
                }
                else {
                    graph[i][j] = -1; // No edge
                }
            }
            else {
                graph[i][j] = 0; // Zero weight for self loop
            }
        }
    }

    // Write graph to input file
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inputFile << graph[i][j] << " ";
        }
        inputFile << endl;
    }

    // Calculate shortest distance using Dijkstra's algorithm
    vector<int> distance(N, INF);
    vector<bool> visited(N, false);

    distance[S - 1] = 0;

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

    // Write shortest distance to output file
    outputFile << (distance[F - 1] == INF ? -1 : distance[F - 1]) << endl;

    // Close files
    inputFile.close();
    outputFile.close();
}

int main() {
    srand(time(nullptr)); // Initialize random seed

    int numTests = 12;
    int N = 5; // Number of vertices in graph
    int minWeight = 1; // Minimum weight of an edge
    int maxWeight = 10; // Maximum weight of an edge

    for (int i = 1; i <= numTests; ++i) {
        generateTest(i, N, minWeight, maxWeight);
    }

    return 0;
}
