#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

// https://informatics.msk.ru/mod/statements/view.php?id=255&chapterid=2001#1

// Функция для проверки, является ли число четырехзначным и не содержит ли оно нулей
bool isValid(int num) {
    string str = to_string(num);
    return str.size() == 4 && str.find('0') == string::npos;
}

// Функция для генерации всех возможных следующих чисел из текущего числа
vector<int> generateNext(int num) {
    vector<int> nextNumbers;
    string str = to_string(num);

    // Правило 1: увеличить первую цифру на 1
    if (str[0] != '9') {
        string nextStr = str;
        nextStr[0]++;
        nextNumbers.push_back(stoi(nextStr));
    }

    // Правило 2: уменьшить последнюю цифру на 1
    if (str[3] != '1') {
        string nextStr = str;
        nextStr[3]--;
        nextNumbers.push_back(stoi(nextStr));
    }

    // Правило 3: циклический сдвиг вправо
    string nextStr = str.substr(3, 1) + str.substr(0, 3);
    nextNumbers.push_back(stoi(nextStr));

    // Правило 4: циклический сдвиг влево
    nextStr = str.substr(1, 3) + str.substr(0, 1);
    nextNumbers.push_back(stoi(nextStr));

    return nextNumbers;
}

// Функция для поиска кратчайшего пути между двумя числами
vector<int> shortestPath(int start, int end) {
    unordered_set<int> visited;
    queue<vector<int>> q;
    q.push({ start });

    while (!q.empty()) {
        vector<int> path = q.front();
        q.pop();
        int current = path.back();

        if (current == end) {
            return path;
        }

        if (visited.find(current) == visited.end()) {
            visited.insert(current);
            vector<int> nextNumbers = generateNext(current);
            for (int num : nextNumbers) {
                vector<int> newPath = path;
                newPath.push_back(num);
                q.push(newPath);
            }
        }
    }

    return {}; // Если путь не найден
}

int main() {
    int start, end;
    cin >> start >> end;

    vector<int> path = shortestPath(start, end);
    for (int num : path) {
        cout << num << endl;
    }

    return 0;
}
