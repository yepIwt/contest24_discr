#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>


// https://informatics.msk.ru/mod/statements/view.php?id=259&chapterid=177#1


using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
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
    cout << a << " " << b << " " << c << endl;
    return 0;
}
