Wilks & Sinclair Coefficient Calculator 🏋️‍♂️
A high-performance C++ desktop application for powerlifters and weightlifters to calculate their relative strength scores. This tool provides a professional-grade interface for comparing strength across different weight classes using the industry-standard Wilks and Sinclair formulas.

🚀 Overview
In strength sports, absolute weight lifted doesn't tell the whole story. This application uses sophisticated mathematical coefficients to normalize lifting totals against body weight, allowing a 60kg lifter to fairly compete against a 120kg lifter for the title of "Best Lifter."

Current Features
Wilks Formula Integration: Accurate calculations for powerlifting totals (Squat + Bench + Deadlift).

Sinclair Formula Integration: Modern coefficients for Olympic weightlifting totals (Snatch + Clean & Jerk).

Immediate Mode UI: Built with Dear ImGui for a lightning-fast, hardware-accelerated user experience.

Data Persistence: Ability to load and parse workout history from local flat files (workouts.txt).

Cross-Platform Core: Robust C++17 backend with a modular architecture.

🛠️ The Tech Stack
Language: C++17

Graphics: OpenGL 3 / GLFW

Interface: Dear ImGui

Build System: Modern CMake (utilizing FetchContent for seamless dependency management)

⏸️ Project Status: Hiatus & Future Goals
I am currently taking a scheduled break from active development on this project to focus on other ventures. The current version represents a stable proof-of-concept for the core calculation engine and UI.

When I return, the roadmap for v2.0 includes:

📈 Phase 1: Data Visualization
ImPlot Integration: Transform static workout history into dynamic progress graphs.

Strength Projections: Visualize "What If" scenarios (e.g., "If I lose 2kg of body weight but maintain my total, how does my Wilks score change?").

📱 Phase 2: User Experience
JSON/SQLite Backend: Move away from .txt files to a more robust database for personal record (PR) tracking.

Profile Management: Support for multiple athlete profiles.

Unit Conversion: Seamless toggling between Metric (kg) and Imperial (lbs) systems.

🧪 Phase 3: Advanced Analytics
Additional Formulas: Integration of the IPF GL and Dots scores to cover all modern powerlifting federations.

RPE/1RM Calculators: Add-on tools to help athletes select attempts for their next meet.

🔨 How to Build
This project uses CMake to automatically handle dependencies.

Clone the repo:

Bash
git clone https://github.com/ElliotFackler/wilks-sinclair-coefficient-calculator.git
Generate Build Files:

Bash
cmake -B build
Compile:

Bash
cmake --build build --config Release


Maintained by Elliot Fackler
