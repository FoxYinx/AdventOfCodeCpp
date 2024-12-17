#include <regex>
#include <fstream>
#include <iostream>

#include "computer.h"

using namespace std;

int year2024_day17_puzzle2() {
    ifstream f("ressources/Year2024/testCopy.txt");

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

    Computer computer(0, 0, 0);

    const regex regexp(R"((\d+))");
    smatch sm;
    while (regex_search(s, sm, regexp)) {
        computer.appendProgram(stoi(sm[1]));
        s = sm.suffix();
    }

    while (true) {
        computer.run();
        if (computer.verifyIdentity()) break;
        computer.increaseA();
        computer.reset();
    }

    cout << computer.getInitialA();
    return 0;
}