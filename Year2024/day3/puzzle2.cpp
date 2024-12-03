#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int year2024_day3_puzzle2() {
    ifstream f("ressources/Year2024/day3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    const regex regexp(R"(mul\(([0-9]{1,3}),([0-9]{1,3})\)|(don't)\(\)|(do)\(\))");
    smatch sm;
    bool enabled = true;
    int total = 0;
    while (getline(f, s)) {
        while (regex_search(s, sm, regexp)) {
            if (sm[4].matched && sm[4] == "do") {
                enabled = true;
            } else if (sm[3].matched && sm[3] == "don't") {
                enabled = false;
            } else if (enabled) {
                if (sm[1].matched && sm[2].matched) {
                    total += stoi(sm[1]) * stoi(sm[2]);
                }
            }
            s = sm.suffix();
        }
    }

    cout << total;
    return 0;
}