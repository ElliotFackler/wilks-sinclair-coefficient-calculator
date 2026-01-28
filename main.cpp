#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "utils.h"

int main() {
    // Choose the file to open.
    std::ifstream file("workouts.txt");
    std::string line;

    // If the file does not open, return an error statement and terminate the run.
    if (!file.is_open()) {
        std::cerr << "Error opening csv file." << std::endl;
        return 1;
    }

    // Vector to store all workout structs
    std::vector<Workout> workouts;

    // Iterate past the title line.
    std::getline(file, line);

    // Iterate through each line of the file
    while (std::getline(file, line)) {
        // Convert the line into a string
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;

        Workout workout;

        // Iterate through each item in the line
        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        // Populate the workout struct with parsed data
        if (!row.empty()) {
            workout.date = row[0];
            workout.sex = row[1][0];  // First character of gender
            workout.bodyWeight = std::stod(row[2]);
            workout.totalLifted = std::stod(row[3]);
            workout.weightType = row[4];
            workout.formula = row[5];

            // Add the workout to the array
            workouts.push_back(workout);
        }
    }

    // Display summary of loaded workouts
    std::cout << "Loaded " << workouts.size() << " workout(s)." << std::endl;

    // Close the file
    file.close();

    // Menu loop
    int choice;
    do {
        displayMenu();
        choice = getUserChoice();
        handleMenuSelection(choice, workouts);
    } while (choice != 4);

    return 0;
}