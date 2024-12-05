#include <iostream>
#include <vector>
#include "intcode.h"

using namespace std;


Intcode::Intcode() {
    this->pointer = 0;
    this->stuck = false;
}

void Intcode::processInstruction(int instruction, vector<int>& program) {

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
            cout << "input: ";
            cin >> program[program[pointer + 1]];
            this->pointer += 2;
            break;
        case 4:
            if ((instruction / 100) % 10 == 1) {
                cout << "output: " << program[pointer + 1] << endl;
            } else {
                cout << "output: " << program[program[pointer + 1]] << endl;
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
