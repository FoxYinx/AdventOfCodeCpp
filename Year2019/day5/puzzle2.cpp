#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "../intcode.h"

using namespace std;

int year2019_day5_puzzle2() {
    ifstream f("ressources/Year2019/day5.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    string tmp;
    vector<int> program;
    while (getline(f, s)) {
        stringstream ss(s);
        while (getline(ss, tmp, ',')) {
            program.push_back(stoi(tmp));
        }
    }

    Intcode intcode;
    while (true) {
        int instruction = program[intcode.pointer];
        if (instruction == 99) break;
        intcode.processInstruction(instruction, program);
        if (intcode.stuck) return 1;
    }

    return 0;
}
