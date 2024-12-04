#include <iostream>
#include <vector>

using namespace std;

void processInstruction(int pointer, int instruction, vector<int>& program) {
    switch (instruction) {
        case 1:
            program[program[pointer + 3]] = program[program[pointer + 1]] + program[program[pointer + 2]];
            break;
        case 2:
            program[program[pointer + 3]] = program[program[pointer + 1]] * program[program[pointer + 2]];
            break;
        default:
            cerr << "Unknown opcode" << endl;
    }
}