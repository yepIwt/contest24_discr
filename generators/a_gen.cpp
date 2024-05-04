#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include <fstream>

// https://informatics.msk.ru/mod/statements/view.php?id=211&chapterid=82#1


void generate_strings(int n, int k, std::string current_string, std::vector<std::string>& result) {
    if (current_string.length() == n) {
        result.push_back(current_string);
        return;
    }

    for (int i = 0; i < k; i++) {
        generate_strings(n, k, current_string + std::to_string(i), result);
    }
}

std::pair<int, int> generate_n_k() {
    std::srand((unsigned)std::time(0));
    int i, j;
    while (true) {
        i = (rand() % 10) + 1;
        j = (rand() % 10) + 1;
        if ((i + j) < 15) {
            return std::make_pair(i, j);
        }
    }
}


int main() {

    int n, k;

    for (int i = 1; i <= 17; i++) {

        std::pair<int, int> new_input = generate_n_k();
        
        n = new_input.first;
        k = new_input.second;

        std::string filename = "tests\\";
        if (i < 10) filename += "0";

        std::ofstream input_file;
        std::string input_path = filename + std::to_string(i);
        input_file.open(input_path.c_str());
        input_file << n << " " << k;
        input_file.close();

        std::ofstream output_file;
        std::string output_path = input_path + ".a";
        output_file.open(output_path.c_str());

        std::vector<std::string> result;
        generate_strings(n, k, "", result);

        for (const auto& str : result) {
            output_file << str << std::endl;
        }
        output_file.close();
    }

    return 0;
}
