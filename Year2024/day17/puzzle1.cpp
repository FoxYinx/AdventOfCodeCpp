#include <regex>
#include <cstdint>
#include <fstream>
#include <iostream>

#include "computer.h"

using namespace std;

int year2024_day17_puzzle1() {
    ifstream f("ressources/Year2024/day17.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    const regex regexp1(R"(Register\s\w:\s(\d+))");
    const regex regexp2(R"((\d+))");
    smatch sm;

    int64_t registers[3];
    for (long long & i : registers) {
        getline(f, s);
        regex_search(s, sm, regexp1);
        i = stoll(sm[1]);
    }

    Computer computer(registers[0], registers[1], registers[2]);

    getline(f, s);
    getline(f, s);
    while (regex_search(s, sm, regexp2)) {
        computer.appendProgram(stoi(sm[1]));
        s = sm.suffix();
    }

    computer.run();

    return 0;
}