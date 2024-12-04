#include <fstream>
#include <iostream>
#include <sstream>
#include "../intcode.h"

#define SIZE 100
#define TARGET 19690720

using namespace std;

int year2019_day2_puzzle2() {
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
    vector<int> initialMemory(program);

    for (int noun = 0; noun < SIZE; noun++) {
        for (int verb = 0; verb < SIZE; verb++) {
            program = initialMemory;
            program[1] = noun;
            program[2] = verb;

            int pointer = 0;
            while (true) {
                int instruction = program[pointer];
                if (instruction == 99) break;
                processInstruction(pointer, instruction, program);
                pointer += 4;
            }
            if (program[0] == TARGET) {
                cout << 100 * noun + verb << endl;
                return 0;
            }
        }
    }

    cerr << "The program failed to find the target" << endl;
    return 1;
}
