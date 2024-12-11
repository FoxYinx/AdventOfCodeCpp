#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <map>
#include "utils.h"

#define ITER 75

using namespace std;


int year2024_day11_puzzle2() {
    ifstream f("ressources/Year2024/day11.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    getline(f, s);
    istringstream iss(s);
    vector<unsigned long> values;
    unsigned long value;
    while (iss >> value) {
        values.push_back(value);
    }

    map<unsigned long, vector<unsigned long>> memory;
    memory.insert({0, {1}});

    for (int j = 0; j < ITER; j++) {
        for (int i = 0; i < values.size(); i++) {
            if (memory.contains(values[i])) {
                if (memory[values[i]].size() == 1) {
                    values[i] = memory[values[i]][0];
                } else {
                    values.insert(values.begin() + i + 1, memory[values[i]][1]);
                    values[i] = memory[values[i]][0];
                    i++;
                }
            } else {
                unsigned int length = GetNumberOfDigits(values[i]);
                if ((length & 1) == 0) {
                    memory.emplace(values[i], vector<unsigned long>{values[i] / (long) pow(10, length / 2), values[i] % (long) pow(10, length / 2)});
                    values.insert(values.begin() + i + 1, memory[values[i]][1]);
                    values[i] = memory[values[i]][0];
                    i++;
                } else {
                    memory.insert({values[i], {values[i] * 2024}});
                    values[i] = memory[values[i]][0];
                }
            }
        }
        cout << "STEP " << j + 1 << " DONE!" << endl;
    }

    cout << values.size() << endl;
    return 0;
}