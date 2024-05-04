#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// https://informatics.msk.ru/mod/statements/view.php?id=211&chapterid=89#1

void recursion(int summa, std::vector<int> prefix, std::ofstream& file) {
    if (summa == 0) {
        for (int i : prefix) {
            file << i << " ";
        }
        file << std::endl;
    }
    else {
        for (int i = 1; i <= summa; i++) {
            if (prefix.empty() || prefix.back() >= i) {
                prefix.push_back(i);
                recursion(summa - i, prefix, file);
                prefix.pop_back();
            }
        }
    }
}

int main() {
    for (int summa = 1; summa <= 40; summa++) {

        std::string filename = "tests/";
        if (summa < 10) {
            filename += "0";
        }
        filename += std::to_string(summa);

        std::ofstream inputFile(filename);
        inputFile << summa;
        inputFile.close();

        std::ofstream outputFile(filename + ".a");
        recursion(summa, {}, outputFile);
        outputFile.close();
    }

    return 0;
}
