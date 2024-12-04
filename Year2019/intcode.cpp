#include <iostream>
#include <vector>

using namespace std;

int processInstruction(const int pointer, const int instruction, vector<int>& program) {
    switch (instruction) {
        case 1:
            program[program[pointer + 3]] = program[program[pointer + 1]] + program[program[pointer + 2]];
            return 4;
        case 2:
            program[program[pointer + 3]] = program[program[pointer + 1]] * program[program[pointer + 2]];
            return 4;
        case 3:
            cout << "input: ";
            cin >> program[program[pointer + 1]];
            return 2;
        case 4:
            cout << "output: " << program[program[pointer + 1]] << endl;
            return 2;
        default:
            cerr << "Unknown opcode: " << instruction << endl;
        return 0;
    }
}