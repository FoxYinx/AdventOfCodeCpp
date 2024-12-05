#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "intcodeLeMauvais.h"

using namespace std;

int year2019_day7_puzzle1() {
    ifstream f("ressources/Year2019/day7.txt");

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

    int order[] = {0, 1, 2, 3, 4};
    int n = sizeof(order) / sizeof(order[0]);
    sort(order, order + n);
    int io = 0;
    IntcodeLeMauvais intcode;
    bool secondInput = false;
    int maxValue = 0;

    do {
        for (int i : order) {
            while (true) {
                int instruction = program[intcode.pointer];
                if (instruction % 10 == 3 && !secondInput) {
                    secondInput = true;
                    intcode.io = i;
                } else if (instruction % 10 == 3 && secondInput) {
                    intcode.io = io;
                }
                if (instruction == 99) break;
                intcode.processInstruction(instruction, program);
                if (intcode.stuck) return 1;
            }
            secondInput = false;
            io = intcode.io;
            if (io > maxValue) maxValue = io;
            intcode.reset();
        }
        intcode.io = 0;
        io = 0;
    } while (next_permutation(order, order + n));


    cout << maxValue;
    return 0;
}
