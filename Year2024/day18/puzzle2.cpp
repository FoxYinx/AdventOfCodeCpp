#include <array>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <regex>
#include "dijkstra.h"

using namespace std;

int year2024_day18_puzzle2() {
    ifstream f("ressources/Year2024/day18.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    array<array<char, SIZE>, SIZE> map = {};
    for (auto& row : map) {
        row.fill('.');
    }

    string s;
    const regex regexp(R"((\d+),(\d+))");
    smatch sm;
    int line = 0;
    while (getline(f, s)) {
        if (regex_search(s, sm, regexp)) {
            map[stoi(sm[2])][stoi(sm[1])] = '#';

            int distance = dijkstra(map);
            if (distance == -1) {
                cout << sm[1] << ',' << sm[2] << endl;
                break;
            }

            line++;
            s = sm.suffix();
        }
    }

    return 0;
}