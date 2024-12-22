#include <regex>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

uint64_t verifyMultiDesign(const vector<string>& patterns, const string& s);

map<string, uint64_t> savedPatterns = {};

int year2024_day19_puzzle2() {
    ifstream f("ressources/Year2024/day19.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    vector<string> patterns = {};

    string s;
    const regex regexp(R"((\w+))");
    smatch sm;
    bool flag = true;
    uint64_t possibleDesigns = 0;
    while (getline(f, s)) {
        if (flag) {
            while (regex_search(s, sm, regexp)) {
                patterns.push_back(sm[1]);
                s = sm.suffix();
            }
            flag = false;
            getline(f, s);
        } else {
            possibleDesigns += verifyMultiDesign(patterns, s);
        }
    }

    cout << possibleDesigns << endl;
    return 0;
}

uint64_t verifyMultiDesign(const vector<string>& patterns, const string& s) {
    if (s.empty()) return 1;
    if (savedPatterns.contains(s)) return savedPatterns[s];

    uint64_t possibilities = 0;
    for (const string& part : patterns) {
        bool flag = true;
        for (int i = 0; i < part.size(); i++) {
            if (part[i] != s[i]) flag = false;
        }
        if (flag) {
            possibilities += verifyMultiDesign(patterns, s.substr(part.size()));
        }
    }
    savedPatterns[s] = possibilities;
    return possibilities;
}
