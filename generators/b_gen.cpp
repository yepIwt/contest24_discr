#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

// https://informatics.msk.ru/mod/statements/view.php?id=211&chapterid=85#1


int generate_n() {
    std::srand((unsigned)std::time(0));
    return (rand() % 10) + 1;
}


int main() {

    int n;

    for (int i = 0; i < 10; i++) {

        n = i;
        int test_case = i + 1;

        std::ofstream input_file;
        std::string filename = "tests\\";
        if (test_case < 10) filename += "0";
        std::string input_path = filename + std::to_string(test_case);
        input_file.open(input_path.c_str());
        input_file << n;
        input_file.close();


        std::ofstream output_file;
        std::string output_path = input_path + ".a";
        output_file.open(output_path.c_str());


        std::vector<int> numbers(n);
        for (int i = 0; i < n; ++i) {
            numbers[i] = i + 1;
        }

        for (int num : numbers) {
            output_file << num;
        }
        output_file << std::endl;

        while (std::next_permutation(numbers.begin(), numbers.end())) {
            for (int num : numbers) {
                output_file << num;
            }
            output_file << std::endl;
        }
        output_file.close();
    }

    return 0;
}
