#ifndef COMPUTER_H
#define COMPUTER_H
#include <cstdint>
#include <vector>

using namespace std;

class Computer {
    int64_t regA = 0;
    int64_t regB = 0;
    int64_t regC = 0;
    int32_t pc = 0;
    vector<int32_t> program = {};

    int64_t initialRegA = 0;
    int64_t initialRegB = 0;
    int64_t initialRegC = 0;
    vector<int32_t> initialProgram = {};

public:
    Computer(int64_t a, int64_t b, int64_t c);

    void decodeOpcode(int32_t opcode);
    [[nodiscard]] int64_t operatorCombo(int32_t operand) const;
    void setProgram(const vector<int32_t>& p);
    void appendProgram(int32_t value);
    void run();
    void reset();
};
#endif /*COMPUTER_H*/
