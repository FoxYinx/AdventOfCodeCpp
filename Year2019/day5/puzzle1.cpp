#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "../intcode.h"

using namespace std;

int year2019_day5_puzzle1() {
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

    int pointer = 0;
    while (true) {
        int instruction = program[pointer];
        if (instruction == 99) break;
        int increase = processInstruction(pointer, instruction, program);
        if (increase == 0) return 1;
        pointer += increase;
    }

    return 0;
}
