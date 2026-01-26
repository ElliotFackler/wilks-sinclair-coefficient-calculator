// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <string>

struct Workout {
    std::string date;
    char sex;
    double bodyWeight;
    double totalLifted;
    std::string weightType;
    std::string formula;
};

void analyzeHistory(Workout workout);

#endif