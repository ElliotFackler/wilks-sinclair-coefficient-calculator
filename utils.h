// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

// Constant to convert from pounds to kilograms
const double LBS_TO_KGS = 0.453592;

struct Workout {
    std::string date;
    char sex;
    double bodyWeight;
    double totalLifted;
    std::string weightType;
    std::string formula;
};

void analyzeHistory(Workout workout);
void displayAllWorkouts(const std::vector<Workout>& workouts);
void displayMenu();
int getUserChoice();
void handleMenuSelection(int choice, const std::vector<Workout>& workouts);

#endif