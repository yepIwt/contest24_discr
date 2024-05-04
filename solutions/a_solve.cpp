#include <iostream>
#include <string>
#include <vector>

// https://informatics.msk.ru/mod/statements/view.php?id=211&chapterid=82#1

using namespace std;

void generate_strings(int n, int k, string current_string, vector<string>& result) {

    if (current_string.length() == n) {
        result.push_back(current_string);
        return;
    }

    for (int i = 0; i < k; i++)
        generate_strings(n, k, current_string + to_string(i), result);

}

int main() {

    int n, k;
    cin >> n >> k;

    vector<string> result;
    generate_strings(n, k, "", result);

    for (const auto& str : result) cout << str << endl;

    return 0;
}
