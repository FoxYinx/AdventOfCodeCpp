#include <iostream>
#include <vector>
#include "intcodeLeMauvais.h"

using namespace std;


IntcodeLeMauvais::IntcodeLeMauvais() {
    this->pointer = 0;
    this->io = 0;
    this->stuck = false;
}

void IntcodeLeMauvais::processInstruction(int instruction, vector<int>& program) {

    int realInstruction = instruction % 100;

    int arg1;
    int arg2;

    switch (realInstruction) {
        case 1:
            arg1 = ((instruction / 100) % 10 == 1) ? program[pointer + 1] : program[program[pointer + 1]];
            arg2 = ((instruction / 1000) % 10 == 1) ? program[pointer + 2] : program[program[pointer + 2]];
            if ((instruction / 10000) % 10 == 1) {
                program[pointer + 3] = arg1 + arg2;
            } else {
                program[program[pointer + 3]] = arg1 + arg2;
            }
            this->pointer += 4;
            break;
        case 2:
            arg1 = ((instruction / 100) % 10 == 1) ? program[pointer + 1] : program[program[pointer + 1]];
            arg2 = ((instruction / 1000) % 10 == 1) ? program[pointer + 2] : program[program[pointer + 2]];
            if ((instruction / 10000) % 10 == 1) {
                program[pointer + 3] = arg1 + arg2;
            } else {
                program[program[pointer + 3]] = arg1 * arg2;
            }
            this->pointer += 4;
            break;
        case 3:
            program[program[pointer + 1]] = io;
            this->pointer += 2;
            break;
        case 4:
            if ((instruction / 100) % 10 == 1) {
                io = program[pointer + 1];
            } else {
                io = program[program[pointer + 1]];
            }
            this->pointer += 2;
            break;
        case 5:
            arg1 = ((instruction / 100) % 10 == 1) ? program[pointer + 1] : program[program[pointer + 1]];
            arg2 = ((instruction / 1000) % 10 == 1) ? program[pointer + 2] : program[program[pointer + 2]];
            if (arg1) {
                this->pointer = arg2;
            } else {
                this->pointer += 3;
            }
            break;
        case 6:
            arg1 = ((instruction / 100) % 10 == 1) ? program[pointer + 1] : program[program[pointer + 1]];
            arg2 = ((instruction / 1000) % 10 == 1) ? program[pointer + 2] : program[program[pointer + 2]];
            if (!arg1) {
                this->pointer = arg2;
            } else {
                this->pointer += 3;
            }
            break;
        case 7:
            arg1 = ((instruction / 100) % 10 == 1) ? program[pointer + 1] : program[program[pointer + 1]];
            arg2 = ((instruction / 1000) % 10 == 1) ? program[pointer + 2] : program[program[pointer + 2]];
            if ((instruction / 10000) % 10 == 1) {
                program[pointer + 3] = (arg1 < arg2) ? 1 : 0;
            } else {
                program[program[pointer + 3]] = (arg1 < arg2) ? 1 : 0;
            }
            this->pointer += 4;
            break;
        case 8:
            arg1 = ((instruction / 100) % 10 == 1) ? program[pointer + 1] : program[program[pointer + 1]];
            arg2 = ((instruction / 1000) % 10 == 1) ? program[pointer + 2] : program[program[pointer + 2]];
            if ((instruction / 10000) % 10 == 1) {
                program[pointer + 3] = (arg1 == arg2) ? 1 : 0;
            } else {
                program[program[pointer + 3]] = (arg1 == arg2) ? 1 : 0;
            }
            this->pointer += 4;
            break;
        default:
            cerr << "Unknown opcode: " << instruction << endl;
            stuck = true;
            break;
    }
}

void IntcodeLeMauvais::reset() {
    this->pointer = 0;
    this->stuck = false;
}
