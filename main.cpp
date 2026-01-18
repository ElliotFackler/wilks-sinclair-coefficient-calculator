#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// csv rows will be date, gender, bodyweight, totallifted, weight type (metric or imperial), formula type

struct Workout {
    std::string date;
    char sex;
    double bodyWeight;
    double totalLifted;
    std::string weightType;
    std::string formula;
};

int main() {
    std::ifstream file("workouts.txt");
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error opening csv file." << std::endl;
        return 1;
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
            std::cout << cell << std::endl;
        }

        if (!row.empty()) {
            std::cout << "Value" << row[0] << std::endl;
        }
    }

    file.close();
    return 0;
}