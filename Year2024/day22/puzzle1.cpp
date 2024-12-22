#include <cstdint>
#include <fstream>
#include <iostream>

using namespace std;

uint64_t deriveSecret(unsigned long long secret);

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

uint64_t deriveSecret(unsigned long long secret) {
    const uint64_t mul64 = secret << 6;
    secret ^= mul64;
    secret %= 16777216;
    const uint64_t div32 = secret >> 5;
    secret ^= div32;
    secret %= 16777216;
    const uint64_t game = secret << 11;
    secret ^= game;
    secret %= 16777216;
    return secret;
}