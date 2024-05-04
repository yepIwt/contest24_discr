#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>

// https://informatics.msk.ru/mod/statements/view.php?id=256&chapterid=111540#1

using namespace std;

vector<vector<int>> g;
vector<bool> used;
vector<set<int>> components;

void dfs(int v) {
    used[v] = true;
    components.back().insert(v);
    for (int u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

void generate_graph(int n, int m, vector<pair<int, int>>& edges) {
    for (int i = 0; i < m; i++) {
        int u = rand() % n + 1;
        int v = rand() % n + 1;
        while (u == v) {
            v = rand() % n + 1;
        }
        edges.push_back({ u, v });
    }
}

void generate_test(int test_num) {
    std::string filename = "tests/";
    if (test_num < 10)
        filename += "0";

    ofstream input_file(filename + to_string(test_num));
    ofstream output_file(filename + to_string(test_num) + ".a");

    int n = rand() % 100000 + 1;
    int m = rand() % 100000;

    input_file << n << " " << m << endl;

    vector<pair<int, int>> edges;
    generate_graph(n, m, edges);

    for (const auto& edge : edges) {
        input_file << edge.first << " " << edge.second << endl;
    }

    g.resize(n + 1);
    used.assign(n + 1, false);

    for (const auto& edge : edges) {
        g[edge.first].push_back(edge.second);
        g[edge.second].push_back(edge.first);
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            components.push_back(set<int>());
            dfs(i);
        }
    }

    output_file << components.size() << endl;

    for (const auto& component : components) {
        output_file << component.size() << endl;
        for (int v : component) {
            output_file << v << " ";
        }
        output_file << endl;
    }

    g.clear();
    used.clear();
    components.clear();

    input_file.close();
    output_file.close();
}

int main() {
    srand(time(0));

    for (int i = 1; i <= 20; i++) {
        generate_test(i);
    }

    return 0;
}
