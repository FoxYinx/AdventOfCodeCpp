#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <vector>
#include "utils.h"

using namespace std;

int year2024_day23_puzzle2() {
    ifstream f("ressources/Year2024/test.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    const regex regexp(R"((\w+)-(\w+))");
    smatch sm;
    map<string, vector<string>> links = {};
    while (getline(f, s)) {
        while (regex_search(s, sm, regexp)) {
            links[sm[1]].push_back(sm[2]);
            links[sm[2]].push_back(sm[1]);
            s = sm.suffix();
        }
    }
    string password;

    for (const auto &[key, value] : links) {
        for (int i = 0; i < value.size() - 1; i++) {
            if (value[i] > key) {
                for (int j = 0; j < value.size(); j++) {
                    if (links[value[i]][j] > value[i] && contains(links[key], links[value[i]][j])) password = key + "," + value[i] + "," + links[value[i]][j];
                }
            }
        }
    }

    cout << password << endl;
    return 0;
}
