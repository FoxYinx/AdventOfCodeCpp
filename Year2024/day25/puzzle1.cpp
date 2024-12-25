#include <array>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int year2024_day25_puzzle1() {
    ifstream f("ressources/Year2024/day25.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    vector<array<int, 5>> locks = {};
    vector<array<int, 5>> keys = {};
    array<array<char, 5>, 7> temp = {};
    int line = 0;
    while (getline(f, s)) {
        if (s.empty()) {
            continue;
        }
        for (int i = 0; i < 5; i++) {
            temp[line][i] = s[i];
        }
        line++;
        if (line == 7) {
            if (temp[0][0] == '.') {
                array tempkey = {0, 0, 0, 0, 0};
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 7; j++) {
                        if (temp[j][i] == '#') {
                            tempkey[i] = 7 - 1 - j;
                            break;
                        }
                    }
                }
                keys.push_back(tempkey);
            } else {
                array templock = {0, 0, 0, 0, 0};
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 7; j++) {
                        if (temp[j][i] == '.') {
                            templock[i] = j - 1;
                            break;
                        }
                    }
                }
                locks.push_back(templock);
            }
            line = 0;
        }
    }

    int unique = 0;
    for (const auto& lock : locks) {
        for (const auto& key : keys) {
            bool flag = true;
            for (int i = 0; i < 5; i++) {
                if (lock[i] + key[i] > 5) flag = false;
            }
            if (flag) unique++;
        }
    }

    cout << unique << endl;
    return 0;
}
