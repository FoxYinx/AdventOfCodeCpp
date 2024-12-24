#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <array>

using namespace std;

int year2024_day24_puzzle1() {
    ifstream f("ressources/Year2024/day24.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    map<string, int> states = {};
    map<string, array<string, 3>> operations = {};
    const regex regexp(R"(([x|y]\d{2}): (\d{1}))");
    const regex regexp2(R"(([\w|\d]{3}) (\w{2,3}) ([\w|\d]{3}) -> ([\w|\d]{3}))");
    smatch sm;
    while (getline(f, s)) {
        if (regex_search(s, sm, regexp)) {
            states.emplace(sm[1], stoi(sm[2]));
            continue;
        }
        if (regex_search(s, sm, regexp2)) {
            states.emplace(sm[4], -1);
            operations.emplace(sm[4].str(), array{sm[1].str(), sm[2].str(), sm[3].str()});
        }
    }

    bool flag = true;
    while (flag) {
        flag = false;
        for (auto &[key, value] : states) {
            if (value == -1) {
                flag = true;
                if (states[operations[key][0]] != -1 && states[operations[key][2]] != -1) {
                    if (const string op = operations[key][1]; op == "AND") {
                        states[key] = states[operations[key][0]] & states[operations[key][2]];
                    } else if (op == "OR") {
                        states[key] = states[operations[key][0]] | states[operations[key][2]];
                    } else if (op == "XOR") {
                        states[key] = states[operations[key][0]] ^ states[operations[key][2]];
                    } else {
                        cerr << "Impossible operator: " << op << endl;
                    }
                }
            }
        }
    }

    uint64_t output = 0;
    int nb = 0;
    for (const auto& [key, value] : states) {
        if (key.at(0) == 'z') {
            output += static_cast<uint64_t>(value) << nb;
            nb++;
        }
    }

    cout << output << endl;
    return 0;
}
