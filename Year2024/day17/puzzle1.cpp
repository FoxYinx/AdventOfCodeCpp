#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void decodeOpcode(int32_t opcode);
int64_t operatorCombo(int32_t operand);

int64_t regA = 25986278;
int64_t regB = 0;
int64_t regC = 0;
int32_t pc = 0;
vector<int32_t> program = {};

int year2024_day17_puzzle1() {
    ifstream f("ressources/Year2024/day17.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    while (getline(f, s)) {
        program.push_back(stoi(s));
    }

    while (true) {
        if (pc >= program.size()) break;

        decodeOpcode(program[pc]);
        pc += 2;
    }
    printf("\b ");

    return 0;
}

void decodeOpcode(const int32_t opcode) {
    switch (opcode) {
        case 0: {
            regA >>= operatorCombo(program[pc + 1]);
            break;
        }
        case 1: {
            regB ^= program[pc + 1];
            break;
        }
        case 2: {
            regB = operatorCombo(program[pc + 1]) % 8;
            break;
        }
        case 3: {
            if (regA == 0) break;
            pc = program[pc + 1] - 2;
            break;
        }
        case 4: {
            regB ^= regC;
            break;
        }
        case 5: {
            cout << operatorCombo(program[pc + 1]) % 8 << ',';
            break;
        }
        case 6: {
            regB = regA >> operatorCombo(program[pc + 1]);
            break;
        }
        case 7: {
            regC = regA >> operatorCombo(program[pc + 1]);
            break;
        }
        default: cerr << "Invalid opcode: " << opcode << endl;
    }
}

int64_t operatorCombo(const int32_t operand) {
    switch (operand) {
        case 0: case 1: case 2: case 3: return operand;
        case 4: return regA;
        case 5: return regB;
        case 6: return regC;
        default: cerr << "Invalid operand: " << operand << endl;
    }
    return -1;
}