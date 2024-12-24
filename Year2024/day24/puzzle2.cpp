#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <array>

using namespace std;

int year2024_day24_puzzle2() {
    ifstream f("ressources/Year2024/day24fixed.txt");

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

    string xoutput = "";
    string youtput = "";
    string zoutput = "";
    for (const auto& [key, value] : states) {
        if (key.at(0) == 'z') {
            zoutput = to_string(value) + zoutput;
        } else if (key.at(0) == 'y') {
            youtput = to_string(value) + youtput;
        } else if (key.at(0) == 'x') {
            xoutput = to_string(value) + xoutput;
        }
    }

    cout << "  x:  " << xoutput << endl;
    cout << "+ y:  " << youtput << endl;
    cout << "= z: " << zoutput << endl;
    return 0;
}
