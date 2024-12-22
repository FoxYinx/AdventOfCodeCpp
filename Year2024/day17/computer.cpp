#include "computer.h"

#include <iostream>

using namespace std;

Computer::Computer() {
    regA = 0;
    initialRegA = 0;
    regB = 0;
    initialRegB = 0;
    regC = 0;
    initialRegC = 0;
}

Computer::Computer(const int64_t a, const int64_t b, const int64_t c) {
    regA = a;
    initialRegA = a;
    regB = b;
    initialRegB = b;
    regC = c;
    initialRegC = c;
}

void Computer::decodeOpcode(const int32_t opcode) {
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
            output.push_back(operatorCombo(program[pc + 1]) % 8);
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

int64_t Computer::operatorCombo(const int32_t operand) const {
    switch (operand) {
        case 0: case 1: case 2: case 3: return operand;
        case 4: return regA;
        case 5: return regB;
        case 6: return regC;
        default: cerr << "Invalid operand: " << operand << endl;
    }
    return -1;
}

void Computer::setProgram(const vector<int32_t>& p) {
    initialProgram = p;
    program = p;
}

void Computer::appendProgram(const int32_t value) {
    initialProgram.push_back(value);
    program.push_back(value);
}

void Computer::run() {
    while (true) {
        if (pc >= program.size()) break;

        decodeOpcode(program[pc]);
        pc += 2;
    }
}

void Computer::printOutput() {
    for (const auto & value : output) {
        cout << value << ',';
    }
    printf("\b ");
    cout << endl;
}

void Computer::increaseA() {
    initialRegA++;
}

bool Computer::verifyIdentity() const {
    return output == initialProgram;
}

int64_t Computer::getInitialA() const {
    return initialRegA;
}

void Computer::setInitialA(const int64_t a) {
    initialRegA = a;
    regA = a;
}

vector<int32_t> Computer::getProgram() const {
    return program;
}

vector<int32_t> Computer::getOutput() const {
    return output;
}

bool Computer::verifyOutput(const unsigned long long length) {
    if (output.empty()) return false;
    if (output.size() < length) return false;
    bool flag = true;
    for (int i = 0; i < length; i++) {
        if (program[program.size() - 1 - i] != output[output.size() - 1 - i]) flag = false;
    }
    if (flag && output.size() == program.size() && initialRegA < copyValue) {
        copyValue = initialRegA;
    }
    return flag;
}

int64_t Computer::getCopyValue() const {
    return copyValue;
}


void Computer::reset() {
    regA = initialRegA;
    regB = initialRegB;
    regC = initialRegC;
    pc = 0;
    program = initialProgram;
    output = {};
}


