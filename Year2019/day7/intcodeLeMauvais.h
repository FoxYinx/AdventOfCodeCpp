#ifndef ADVENTOFCODE_INTCODE_H
#define ADVENTOFCODE_INTCODE_H

class IntcodeLeMauvais {
public:
    int pointer;
    int io;
    std::vector<int> order;
    bool stuck;

    IntcodeLeMauvais();
    void processInstruction(int instruction, std::vector<int>& program);
    void reset();
};

#endif
