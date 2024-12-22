#include <array>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

uint64_t findSequence(const vector<vector<int>>& memory, const array<int, 4>& sequence);
void addAndRotateLeft(array<int, 4>& evolution, const int& value);

int year2024_day22_puzzle2() {
    ifstream f("ressources/Year2024/day22.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    uint64_t mostBananas = 0;
    vector<vector<int>> memory = {};
    while (getline(f, s)) {
        memory.emplace_back();
        uint64_t value = stoull(s);
        memory.back().push_back(value % 10);
        for (int i = 0; i < 2000; i++) {
            value = deriveSecret(value);
            memory.back().push_back(value % 10);
        }
    }

    for (int i = -9; i <= 9; i++) {
        for (int j = -9; j <= 9; j++) {
            for (int k = -9; k <= 9; k++) {
                for (int l = -9; l <= 9; l++) {
                    if (const uint64_t bananas = findSequence(memory, {i, j, k, l}); bananas > mostBananas) {
                        mostBananas = bananas;
                    }
                }
            }
        }
    }

    cout << mostBananas << endl;
    return 0;
}

uint64_t findSequence(const vector<vector<int>>& memory, const array<int, 4>& sequence) {
    uint64_t allbananas = 0;
    for (const auto& secrets : memory) {
        array evolution = {-99, -99, -99, -99};
        for (int i = 1; i < secrets.size(); i++) {
            addAndRotateLeft(evolution, secrets[i] - secrets[i - 1]);
            if (sequence == evolution) {
                allbananas += secrets[i];
                break;
            }
        }
    }
    return allbananas;
}

void addAndRotateLeft(array<int, 4>& evolution, const int& value) {
    for (int i = 0; i < evolution.size() - 1; i++) {
        evolution[i] = evolution[i + 1];
    }
    evolution.back() = value;
}
