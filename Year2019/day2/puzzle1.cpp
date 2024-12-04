#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "intcode.h"

using namespace std;

int year2019_day2_puzzle1() {
    ifstream f("ressources/Year2019/day2.txt");

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

    program[1] = 12;
    program[2] = 2;

    int pointer = 0;
    while (true) {
        int instruction = program[pointer];
        if (instruction == 99) break;
        processInstruction(pointer, instruction, program);
        pointer += 4;
    }

    cout << program[0] << endl;
    return 0;
}
