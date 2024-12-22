#include <cmath>
#include <fstream>
#include <iostream>
#include <regex>

#include "computer.h"

int64_t vecToInt(const vector<int8_t>& values);
void findCopyProgram(Computer& computer, vector<int8_t> vecRegA, int iteration);

using namespace std;

int year2024_day17_puzzle2() {
    ifstream f("ressources/Year2024/day17.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    getline(f, s);
    getline(f, s);
    getline(f, s);
    getline(f, s);
    getline(f, s);

    Computer computer;

    const regex regexp(R"((\d+))");
    smatch sm;
    while (regex_search(s, sm, regexp)) {
        computer.appendProgram(stoi(sm[1]));
        s = sm.suffix();
    }

    vector<int8_t> vecRegA = {};
    findCopyProgram(computer,vecRegA, 1);

    if (computer.getCopyValue() == INT64_MAX) {
        cout << "Part 2 failed!" << endl;
        return 1;
    }

    cout << computer.getCopyValue() << endl;

    return 0;
}

void findCopyProgram(Computer& computer, vector<int8_t> vecRegA, const int iteration) {
    vecRegA.push_back(0);

    for (int8_t i = iteration == 1 ? 1 : 0; i < 8; i++) {
        vecRegA[vecRegA.size() - 1] = i;
        computer.setInitialA(vecToInt(vecRegA));
        computer.reset();

        computer.run();

        if (computer.verifyOutput(vecRegA.size())) {
            findCopyProgram(computer, vecRegA, iteration + 1);
        }
    }
}

int64_t vecToInt(const vector<int8_t>& values) {
    int64_t value = 0;
    int64_t power = 1;
    for (int i = values.size() - 1; i >= 0; --i) {
        value += values[i] * power;
        power *= 8;
    }
    return value;
}