#include "utils.h"
#include <iostream>
#include <string>
#include <vector>

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

void analyzeHistory(Workout workout) {
    std::cout << "--- 📜 Historical Strength Analysis ---\n";
    std::cout << "Date       | Bodyweight | Wilks | Sinclair\n";
    std::cout << "------------------------------------------\n";

    int output;

    if ((workout.formula == "Wilks")) {
        // calculate wilks formula
        output = calculateWilks(workout);
    } else {
        // calculate sinclair formula
        output = calculateSinclair(workout);
    }

    std::cout << workout.date << "    " << workout.bodyWeight << "    " << output << std::endl;
}