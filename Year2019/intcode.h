#ifndef ADVENTOFCODE_INTCODE_H
#define ADVENTOFCODE_INTCODE_H

class Intcode {
public:
    int pointer;

    Intcode();
    void processInstruction(int instruction, std::vector<int>& program);
};

#endif
