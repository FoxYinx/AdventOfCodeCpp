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

int solveEquation(equation& equation);

int year2024_day13_puzzle1() {
    ifstream f("ressources/Year2024/test.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    const regex regexp(R"((\d+))");
    smatch sm;
    int total = 0;
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
                    case 4: eq.goalX = stod(sm[1]); break;
                    case 5: eq.goalY = stod(sm[1]); break;
                }
                field = (field + 1) % 6;
                if (field == 0) {
                    total += solveEquation(eq);
                    eq = {};
                }
            }
            s = sm.suffix();
        }
    }

    cout << total;
    return 0;
}

int solveEquation(equation& equation) {
    double aPresses = 0;
    double bPresses = 0;

    double da = (double) equation.ax / (double) equation.ay;

    bPresses = (equation.goalX - da * equation.goalY) / (equation.bx - da * equation.by);
    aPresses = (equation.goalX - bPresses * equation.bx) / equation.ax;

    if (aPresses > 100 || bPresses > 100 || aPresses < 0 || bPresses < 0) return 0;

    double intpart;
    if (modf(aPresses, &intpart) != 0.0) return 0;
    if (modf(bPresses, &intpart) != 0.0) return 0;

    cout << "A: " << aPresses << endl;
    cout << "B: " << bPresses << endl;

    return aPresses * 3 + bPresses;
}