#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>


// https://informatics.msk.ru/mod/statements/view.php?id=259&chapterid=177#1


using namespace std;


void findMinSumTriangle(int n, vector<vector<int>>& dist, int test_counter) {
    int min_sum = INT_MAX;
    int a = -1, b = -1, c = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum = dist[i][j] + dist[j][k] + dist[k][i];
                if (sum < min_sum) {
                    min_sum = sum;
                    a = i + 1;
                    b = j + 1;
                    c = k + 1;
                }
            }
        }
    }
    std::ofstream outputFile("tests/0" + std::to_string(test_counter) + ".a", std::ios_base::app);
    outputFile << a << " " << b << " " << c << std::endl;
    outputFile.close();
}

void logInput(int n, vector<vector<int>>& dist, int test_counter) {
    std::ofstream inputFile("tests/0" + std::to_string(test_counter), std::ios_base::app);
    inputFile << n << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inputFile << dist[i][j] << " ";
        }
        inputFile << std::endl;
    }
    inputFile.close();
}

int main() {
    srand(time(0));
    int test_counter = 1;
    for (int i = 0; i < 7; i++) {
        int n = rand() % 100 + 1;
        vector<vector<int>> dist(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                dist[j][k] = rand() % 1000 + 1;
                dist[k][j] = dist[j][k];
                if (j == k) {
                    dist[j][k] = 0;
                }
            }
        }
        logInput(n, dist, test_counter);
        findMinSumTriangle(n, dist, test_counter);
        test_counter++;
    }
    return 0;
}
