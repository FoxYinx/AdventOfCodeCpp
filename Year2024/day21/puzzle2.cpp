#include <regex>
#include <fstream>
#include <iostream>

#include "robots.h"

#define MAX_DEPTH 25

using namespace std;

int year2024_day21_puzzle2() {
    ifstream f("ressources/Year2024/day21.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    const regex regexp(R"((\d+))");
    smatch sm;
    uint64_t total = 0;
    map<MapKey, uint64_t> cache = {};
    while (getline(f, s)) {
        vector<uint8_t> line(s.begin(), s.end());
        const uint64_t len = findShortestSequence<4>(line, MAX_DEPTH, true, cache);
        if (regex_search(s, sm, regexp)) {
            cout << sm[1] << " got len " << len << endl;
            total += len * stoi(sm[1]);
        } else {
            cerr << "Regex error!" << endl;
        }
    }

    cout << total << endl;
    return 0;
}
