#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

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

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    used.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            components.push_back(set<int>());
            dfs(i);
        }
    }

    cout << components.size() << endl;

    for (const auto& component : components) {
        cout << component.size() << endl;
        for (int v : component) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
