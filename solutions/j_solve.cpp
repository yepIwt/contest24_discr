#include <iostream>
#include <vector>

using namespace std;

// https://informatics.msk.ru/mod/statements/view.php?id=261#1

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
    int n;
    cin >> n;

    vector<vector<int>> adj_matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj_matrix[i][j];
        }
    }

    if (isTree(adj_matrix)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
