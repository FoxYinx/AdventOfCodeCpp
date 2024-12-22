#include <cstdint>
#include <fstream>
#include <iostream>
#include "utils.h"

using namespace std;

int year2024_day22_puzzle1() {
    ifstream f("ressources/Year2024/day22.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    uint64_t sum = 0;
    while (getline(f, s)) {
        uint64_t initialValue = stoull(s);
        for (int i = 0; i < 2000; i++) {
            initialValue = deriveSecret(initialValue);
        }
        sum += initialValue;
    }

    cout << sum << endl;
    return 0;
}
