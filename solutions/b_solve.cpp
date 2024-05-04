#include <iostream>
#include <algorithm>
#include <vector>

// https://informatics.msk.ru/mod/statements/view.php?id=211&chapterid=85#1

int main() {
    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) numbers[i] = i + 1;
    for (int num : numbers) std::cout << num;

    std::cout << std::endl;

       while (std::next_permutation(numbers.begin(), numbers.end())) {
        for (int num : numbers) std::cout << num;
        std::cout << std::endl;
    }  

    return 0;
}
