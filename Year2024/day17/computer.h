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
    vector<int32_t> output = {};

    int64_t initialRegA = 0;
    int64_t initialRegB = 0;
    int64_t initialRegC = 0;
    vector<int32_t> initialProgram = {};

    int64_t copyValue = INT64_MAX;

public:
    Computer();
    Computer(int64_t a, int64_t b, int64_t c);

    void decodeOpcode(int32_t opcode);
    [[nodiscard]] int64_t operatorCombo(int32_t operand) const;
    void setProgram(const vector<int32_t>& p);
    void appendProgram(int32_t value);
    void run();
    void printOutput();
    void increaseA();
    [[nodiscard]] bool verifyIdentity() const;
    [[nodiscard]] int64_t getInitialA() const;
    void setInitialA(int64_t a);
    [[nodiscard]] vector<int32_t> getProgram() const;
    [[nodiscard]] vector<int32_t> getOutput() const;
    [[nodiscard]] bool verifyOutput(unsigned long long length);
    [[nodiscard]] int64_t getCopyValue() const;
    void reset();
};
#endif /*COMPUTER_H*/
