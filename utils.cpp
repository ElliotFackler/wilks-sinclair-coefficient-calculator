#include "utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


// calculate wilks formula (Powerlifting)
int calculateWilks(Workout workout) {
    double a, b, c, d, e, f;

    if (workout.sex == 'M') {
        a = -214.37519; b = 15.63612; c = -0.01017; 
        d = -0.00114; e = 0.00000636; f = -0.0000000127;
    } else {
        a = 594.31747; b = -27.23842; c = 0.82112; 
        d = -0.00930; e = 0.00004731; f = -0.0000000905;
    }

    // Calculating the denominator: a + bx + cx^2 + dx^3 + ex^4 + fx^5
    double x = workout.bodyWeight;
    double denominator = a + (b * x) + (c * std::pow(x, 2)) + (d * std::pow(x, 3)) + 
                         (e * std::pow(x, 4)) + (f * std::pow(x, 5));

    double coefficient = 500.0 / denominator;
    
    return workout.totalLifted * coefficient;
}

// calculate sinclair formula (Olympic Lifts)
int calculateSinclair(Workout workout) {
    double A = (workout.sex == 'M') ? 0.722762521 : 0.787004341;
    double b = (workout.sex == 'M') ? 193.609 : 153.757;

    if (workout.bodyWeight >= b) {
        return workout.totalLifted;
    }

    // Step 1: Log10 of (bodyweight / max weight)
    double logRatio = std::log10(workout.bodyWeight / b);

    // Step 2: A * (logRatio squared)
    double exponent = A * std::pow(logRatio, 2);

    // Step 3: Sinclair Total = Actual Total * 10^exponent
    return workout.totalLifted * std::pow(10, exponent);
}

// Find formula and produce output
void analyzeHistory(Workout workout) {
    std::cout << "--- Historical Strength Analysis ---\n";
    std::cout << std::left << std::setw(12) << "Date" << std::setw(12) << "Bodyweight" 
              << std::setw(8) << "Wilks" << "Sinclair\n";
    std::cout << "------------------------------------------\n";

    int output;
    bool isWilks;

    if (workout.weightType == "lbs") {
        workout.bodyWeight = workout.bodyWeight * LBS_TO_KGS;
        workout.totalLifted = workout.totalLifted * LBS_TO_KGS;
    }

    // Calculate based on the requested formula
    if ((workout.formula == "Wilks")) {
        // calculate wilks formula
        output = calculateWilks(workout);
        isWilks = true;
    } else {
        // calculate sinclair formula
        output = calculateSinclair(workout);
        isWilks = false;
    }

    std::cout << std::left << std::setw(12) << workout.date 
              << std::setw(12) << workout.bodyWeight;
    
    // Change output spot of number based on formula type
    if (isWilks) {
        std::cout << std::setw(8) << output << "-" << std::endl;
    } else {
        std::cout << std::setw(8) << "-" << output << std::endl;
    }
}

// Display all workouts with analysis
void displayAllWorkouts(const std::vector<Workout>& workouts) {
    std::cout << "\n--- All Workouts ---\n";
    std::cout << std::left << std::setw(12) << "Date" << std::setw(12) << "Bodyweight" 
              << std::setw(8) << "Wilks" << "Sinclair\n";
    std::cout << "------------------------------------------\n";

    for (const auto& workout : workouts) {
        Workout tempWorkout = workout;
        if (tempWorkout.weightType == "lbs") {
            tempWorkout.bodyWeight = tempWorkout.bodyWeight * LBS_TO_KGS;
            tempWorkout.totalLifted = tempWorkout.totalLifted * LBS_TO_KGS;
        }
        int wilksScore = calculateWilks(tempWorkout);
        int sinclairScore = calculateSinclair(tempWorkout);

        std::cout << std::left << std::setw(12) << workout.date 
                  << std::setw(12) << tempWorkout.bodyWeight
                  << std::setw(8) << wilksScore << sinclairScore << std::endl;
    }
}

// Display menu options
void displayMenu() {
    std::cout << "\n========== Menu ==========\n";
    std::cout << "1. View all workouts\n";
    std::cout << "2. View best Wilks lift\n";
    std::cout << "3. View best Sinclair lift\n";
    std::cout << "4. Exit\n";
    std::cout << "==========================\n";
}

// Get user choice
int getUserChoice() {
    int choice;
    std::cout << "Enter your choice (1-4): ";
    std::cin >> choice;
    return choice;
}

// Handle menu selection
void handleMenuSelection(int choice, const std::vector<Workout>& workouts) {
    if (workouts.empty()) {
        std::cout << "No workouts loaded.\n";
        return;
    }

    switch (choice) {
        case 1:
            displayAllWorkouts(workouts);
            break;
        case 2: {
            int bestIndex = 0;
            Workout tempWorkout = workouts[0];
            if (tempWorkout.weightType == "lbs") {
                tempWorkout.bodyWeight = tempWorkout.bodyWeight * LBS_TO_KGS;
                tempWorkout.totalLifted = tempWorkout.totalLifted * LBS_TO_KGS;
            }
            int bestScore = calculateWilks(tempWorkout);
            for (size_t i = 1; i < workouts.size(); i++) {
                Workout w = workouts[i];
                if (w.weightType == "lbs") {
                    w.bodyWeight = w.bodyWeight * LBS_TO_KGS;
                    w.totalLifted = w.totalLifted * LBS_TO_KGS;
                }
                int score = calculateWilks(w);
                if (score > bestScore) {
                    bestScore = score;
                    bestIndex = i;
                }
            }
            std::cout << "\n--- Best Wilks Lift ---\n";
            std::cout << "Date: " << workouts[bestIndex].date << "\n";
            std::cout << "Bodyweight: " << workouts[bestIndex].bodyWeight << " " << workouts[bestIndex].weightType << "\n";
            std::cout << "Total Lifted: " << workouts[bestIndex].totalLifted << " " << workouts[bestIndex].weightType << "\n";
            std::cout << "Wilks Score: " << bestScore << "\n";
            break;
        }
        case 3: {
            int bestIndex = 0;
            Workout tempWorkout = workouts[0];
            if (tempWorkout.weightType == "lbs") {
                tempWorkout.bodyWeight = tempWorkout.bodyWeight * LBS_TO_KGS;
                tempWorkout.totalLifted = tempWorkout.totalLifted * LBS_TO_KGS;
            }
            int bestScore = calculateSinclair(tempWorkout);
            for (size_t i = 1; i < workouts.size(); i++) {
                Workout w = workouts[i];
                if (w.weightType == "lbs") {
                    w.bodyWeight = w.bodyWeight * LBS_TO_KGS;
                    w.totalLifted = w.totalLifted * LBS_TO_KGS;
                }
                int score = calculateSinclair(w);
                if (score > bestScore) {
                    bestScore = score;
                    bestIndex = i;
                }
            }
            std::cout << "\n--- Best Sinclair Lift ---\n";
            std::cout << "Date: " << workouts[bestIndex].date << "\n";
            std::cout << "Bodyweight: " << workouts[bestIndex].bodyWeight << " " << workouts[bestIndex].weightType << "\n";
            std::cout << "Total Lifted: " << workouts[bestIndex].totalLifted << " " << workouts[bestIndex].weightType << "\n";
            std::cout << "Sinclair Score: " << bestScore << "\n";
            break;
        }
        case 4:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
    }
}