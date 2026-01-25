#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// Constant to convert from pounds to kilograms
const double LBS_TO_KGS = 0.453592;

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
    // Choose the file to open.
    std::ifstream file("workouts.txt");
    std::string line;

    // If the file does not open, return an error statement and terminate the run.
    if (!file.is_open()) {
        std::cerr << "Error opening csv file." << std::endl;
        return 1;
    }

    // Iterate past the title line.
    std::getline(file, line);

    // Iterate through each line of the file
    while (std::getline(file, line)) {
        // Convert the line into a string
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;

        // Iterate through each item in the line
        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
            std::cout << cell << std::endl;
        }

        // If the file contains no data
        if (!row.empty()) {
            std::cout << "Value" << row[0] << std::endl;
        }
    }


    // Close the file and terminate the run
    file.close();
    return 0;
}