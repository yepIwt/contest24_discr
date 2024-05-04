#include <iostream>
#include <vector>

// https://informatics.msk.ru/mod/statements/view.php?id=211&chapterid=89#1


void recursion(int summa, std::vector<int> prefix) {
    if (summa == 0) {
        for(int i : prefix) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    } else {
        for (int i = 1; i <= summa; i++) {
            if (prefix.empty() || prefix.back() >= i) {
                prefix.push_back(i);
                recursion(summa - i, prefix);
                prefix.pop_back();
            }
        }
    }
}

int main() {
    int summa;
    std::cin >> summa;
    recursion(summa, {});
    return 0;
}
