#include "utils.h"
#include <iostream>
#include <string>
#include <vector>

void analyzeHistory(Workout workout) {
    std::cout << "--- 📜 Historical Strength Analysis ---\n";
    std::cout << "Date       | Bodyweight | Wilks | Sinclair\n";
    std::cout << "------------------------------------------\n";

    if ((workout.formula == "Wilks")) {
        // calculate wilks formula
    } else {
        // calculate sinclair formula
    }


}