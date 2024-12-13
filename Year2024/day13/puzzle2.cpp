#include <fstream>
#include <iostream>
#include <regex>
#include <cmath>

using namespace std;

struct equation {
    double ax;
    double ay;
    double bx;
    double by;
    double goalX;
    double goalY;
};

unsigned long long solveEquationLong(const equation& equation);

int year2024_day13_puzzle2() {
    ifstream f("ressources/Year2024/day13.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    const regex regexp(R"((\d+))");
    smatch sm;
    unsigned long long total = 0;
    int field = 0;
    equation eq = {};
    while (getline(f, s)) {
        while (regex_search(s, sm, regexp)) {
            if (stoi(sm[1]) != 0) {
                switch (field) {
                    case 0: eq.ax = stod(sm[1]); break;
                    case 1: eq.ay = stod(sm[1]); break;
                    case 2: eq.bx = stod(sm[1]); break;
                    case 3: eq.by = stod(sm[1]); break;
                    case 4: eq.goalX = stod(sm[1]) + 10000000000000; break;
                    case 5: eq.goalY = stod(sm[1]) + 10000000000000; break;
                }
                field = (field + 1) % 6;
                if (field == 0) {
                    total += solveEquationLong(eq);
                }
            }
            s = sm.suffix();
        }
    }

    cout << total;
    return 0;
}

unsigned long long solveEquationLong(const equation& equation) {
    const double aPresses = (equation.by * equation.goalX - equation.bx * equation.goalY) / (equation.ax * equation.by - equation.ay * equation.bx);
    const double bPresses = (equation.ax * equation.goalY - equation.ay * equation.goalX) / (equation.ax * equation.by - equation.ay * equation.bx);

    if (aPresses < 0 || bPresses < 0) return 0;

    if (aPresses - static_cast<double>(static_cast<long long>(aPresses)) > 0.001 || aPresses - static_cast<double>(static_cast<long long>(aPresses)) < -0.001) return 0;
    if (bPresses - static_cast<double>(static_cast<long long>(bPresses)) > 0.001 || bPresses - static_cast<double>(static_cast<long long>(bPresses)) < -0.001) return 0;

    return static_cast<long long>(round(aPresses)) * 3 + static_cast<long long>(round(bPresses));
}