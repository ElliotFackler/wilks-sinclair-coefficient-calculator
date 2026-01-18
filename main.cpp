#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


void helloWorld() {
    std::cout << "Heja" << std::endl;
}

int main() {
    std::ifstream file("data.csv");
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error opening csv file." << std::endl;
        return 1;
    }
    helloWorld();

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        if (!row.empty()) {
            std::cout << "Value" << row[0] << std::endl;
        }
    }

    file.close();
    return 0;
}