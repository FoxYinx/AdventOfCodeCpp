#include <iostream>
#include <vector>
#include "intcode.h"

using namespace std;


Intcode::Intcode() {
    this->pointer = 0;
}

void Intcode::processInstruction(int instruction, vector<int>& program) {
    switch (instruction) {
        case 1:
            program[program[pointer + 3]] = program[program[pointer + 1]] + program[program[pointer + 2]];
            this->pointer += 4;
            break;
        case 2:
            program[program[pointer + 3]] = program[program[pointer + 1]] * program[program[pointer + 2]];
            this->pointer += 4;
            break;
        case 3:
            cout << "input: ";
            cin >> program[program[pointer + 1]];
            this->pointer += 2;
            break;
        case 4:
            cout << "output: " << program[program[pointer + 1]] << endl;
            this->pointer += 2;
            break;
        default:
            cerr << "Unknown opcode: " << instruction << endl;
            break;
    }
}
