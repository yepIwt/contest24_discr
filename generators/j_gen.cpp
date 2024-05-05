#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// https://informatics.msk.ru/mod/statements/view.php?id=261#1

int random(int min, int max) {
    return min + rand() % (max - min + 1);
}


void dfs(int node, const vector<vector<int>>& adj_matrix, vector<bool>& visited) {
    visited[node] = true;
    for (int i = 0; i < adj_matrix.size(); ++i) {
        if (adj_matrix[node][i] && !visited[i]) {
            dfs(i, adj_matrix, visited);
        }
    }
}

bool isTree(const vector<vector<int>>& adj_matrix) {
    int n = adj_matrix.size();

    // Проверяем, что количество ребер равно n-1
    int edge_count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edge_count += adj_matrix[i][j];
        }
    }
    if (edge_count != n - 1) {
        return false;
    }

    // Проверяем, что граф связный
    vector<bool> visited(n, false);
    dfs(0, adj_matrix, visited);
    for (bool v : visited) {
        if (!v) {
            return false;
        }
    }

    return true;
}



int main() {
    for (int testNum = 1; testNum <= 11; testNum++){
        srand(time(0));

        std::string filename = "tests\\";
        if (testNum < 10) filename += "0";
        string input_filename = filename + std::to_string(testNum);
        string output_filename = input_filename + ".a";
        ofstream input_file(input_filename);
        ofstream output_file(output_filename);

        int n = random(1, 100);
        
        input_file << n << endl;

        vector<vector<int>> adj_matrix(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int edge = random(0, 1);
                adj_matrix[i][j] = edge;
                adj_matrix[j][i] = edge;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                input_file << adj_matrix[i][j] << " ";
            }
            input_file << endl;
        }

        if (isTree(adj_matrix)) {
            output_file << "YES" << endl;
        }
        else {
            output_file << "NO" << endl;
        }
    }

    return 0;
}
