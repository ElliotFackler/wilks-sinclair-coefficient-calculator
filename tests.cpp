#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

// Constants and structures
const double LBS_TO_KGS = 0.453592;

struct Workout {
    std::string date;
    char sex;
    double bodyWeight;
    double totalLifted;
    std::string weightType;
    std::string formula;
};

// Forward declarations
int calculateWilks(Workout workout);
int calculateSinclair(Workout workout);

// Simple test framework
#include "doctest.h"

// Test Wilks calculation for male
TEST_CASE("Wilks calculation - Male") {
    Workout male_workout;
    male_workout.sex = 'M';
    male_workout.bodyWeight = 82.0;  // kg
    male_workout.totalLifted = 300.0;  // kg
    male_workout.weightType = "kgs";
    male_workout.formula = "Wilks";
    
    int wilks_score = calculateWilks(male_workout);
    
    // Expected range for these values (approximate)
    CHECK(wilks_score > 200);
    CHECK(wilks_score < 400);
}

// Test Wilks calculation for female
TEST_CASE("Wilks calculation - Female") {
    Workout female_workout;
    female_workout.sex = 'F';
    female_workout.bodyWeight = 65.0;  // kg
    female_workout.totalLifted = 200.0;  // kg
    female_workout.weightType = "kgs";
    female_workout.formula = "Wilks";
    
    int wilks_score = calculateWilks(female_workout);
    
    CHECK(wilks_score > 150);
    CHECK(wilks_score < 350);
}

// Test Sinclair calculation for male
TEST_CASE("Sinclair calculation - Male") {
    Workout male_workout;
    male_workout.sex = 'M';
    male_workout.bodyWeight = 82.0;  // kg
    male_workout.totalLifted = 300.0;  // kg
    male_workout.weightType = "kgs";
    male_workout.formula = "Sinclair";
    
    int sinclair_score = calculateSinclair(male_workout);
    
    // For male under 193.609 kg, there should be a coefficient applied
    CHECK(sinclair_score > 200);
    CHECK(sinclair_score < 500);
}

// Test Sinclair calculation for female
TEST_CASE("Sinclair calculation - Female") {
    Workout female_workout;
    female_workout.sex = 'F';
    female_workout.bodyWeight = 65.0;  // kg
    female_workout.totalLifted = 200.0;  // kg
    female_workout.weightType = "kgs";
    female_workout.formula = "Sinclair";
    
    int sinclair_score = calculateSinclair(female_workout);
    
    CHECK(sinclair_score > 150);
    CHECK(sinclair_score < 400);
}

// Test Sinclair with heavyweight male (above limit)
TEST_CASE("Sinclair calculation - Male above weight limit") {
    Workout heavy_male;
    heavy_male.sex = 'M';
    heavy_male.bodyWeight = 200.0;  // kg (above 193.609)
    heavy_male.totalLifted = 400.0;  // kg
    heavy_male.weightType = "kgs";
    heavy_male.formula = "Sinclair";
    
    int sinclair_score = calculateSinclair(heavy_male);
    
    // Above limit, should equal totalLifted
    CHECK(sinclair_score == 400);
}

// Test weight conversion (lbs to kg)
TEST_CASE("Weight conversion - lbs to kg") {
    double lbs = 100.0;
    double expected_kg = lbs * LBS_TO_KGS;
    
    // 100 lbs should be approximately 45.36 kg
    CHECK(expected_kg > 45.0);
    CHECK(expected_kg < 46.0);
}

// Test Wilks is higher for lighter lifters (relatively)
TEST_CASE("Wilks comparison - lighter vs heavier") {
    Workout light;
    light.sex = 'M';
    light.bodyWeight = 70.0;
    light.totalLifted = 300.0;
    light.weightType = "kgs";
    light.formula = "Wilks";
    
    Workout heavy;
    heavy.sex = 'M';
    heavy.bodyWeight = 100.0;
    heavy.totalLifted = 300.0;
    heavy.weightType = "kgs";
    heavy.formula = "Wilks";
    
    int light_score = calculateWilks(light);
    int heavy_score = calculateWilks(heavy);
    
    // Same lift but lighter person should have higher Wilks score
    CHECK(light_score > heavy_score);
}

// Test consistent calculations
TEST_CASE("Wilks - same input produces same output") {
    Workout w1, w2;
    w1.sex = 'M';
    w1.bodyWeight = 85.0;
    w1.totalLifted = 350.0;
    w1.weightType = "kgs";
    w1.formula = "Wilks";
    
    w2 = w1;
    
    int score1 = calculateWilks(w1);
    int score2 = calculateWilks(w2);
    
    CHECK(score1 == score2);
}
