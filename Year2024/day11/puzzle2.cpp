#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <map>
#include <array>
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
    map<unsigned long, array<unsigned long, 2>> memory;
    unsigned long value;
    while (iss >> value) {
        memory.emplace(value, array<unsigned long, 2>{1, 1});
    }

    for (int j = 0; j < ITER; j++) {
        vector<unsigned long> keys;
        for (auto & it : memory) {
            keys.push_back(it.first);
        }

        for (auto& key : keys) {
            if (key == 0) {
                memory[1][1] += memory[0][0];
            } else {
                unsigned int length = GetNumberOfDigits(key);
                if ((length & 1) == 0) {
                    memory[key / (long) pow(10, length / 2)][1] += memory[key][0];
                    memory[key % (long) pow(10, length / 2)][1] += memory[key][0];
                } else {
                    memory[key * 2024][1] += memory[key][0];
                }
            }
            memory[key][1] -= memory[key][0];
        }

        vector<unsigned long> toDelete;
        for (auto& [key, valeur] : memory) {
            memory[key][0] = memory[key][1];
            if (memory[key][1] == 0) toDelete.push_back(key);
        }
        for (auto remove : toDelete) {
            memory.erase(remove);
        }
    }

    unsigned long nbStones = 0;
    for (auto& [key, valeur] : memory) {
        nbStones += valeur[0];
    }
    cout << nbStones << endl;
    return 0;
}