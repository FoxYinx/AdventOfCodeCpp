#include <regex>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

bool verifyDesign(const vector<string>& patterns, const string& s);

int year2024_day19_puzzle1() {
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

    int possibleDesigns = 0;

    while (getline(f, s)) {
        if (flag) {
            while (regex_search(s, sm, regexp)) {
                patterns.push_back(sm[1]);
                s = sm.suffix();
            }
            flag = false;
            getline(f, s);
        } else {
            if (verifyDesign(patterns, s)) possibleDesigns++;
        }
    }

    cout << possibleDesigns << endl;
    return 0;
}

bool verifyDesign(const vector<string>& patterns, const string& s) {
    if (s.empty()) return true;
    for (const string& part : patterns) {
        bool flag = true;
        for (int i = 0; i < part.size(); i++) {
            if (part[i] != s[i]) flag = false;
        }
        if (flag && verifyDesign(patterns, s.substr(part.size()))) {
            return true;
        }
    }
    return false;
}
