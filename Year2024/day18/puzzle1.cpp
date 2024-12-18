#include <array>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <regex>
#include "dijkstra.h"

#define ERRORS 1024

using namespace std;

int year2024_day18_puzzle1() {
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
    while (getline(f, s) && line < ERRORS) {
        if (regex_search(s, sm, regexp)) {
            map[stoi(sm[2])][stoi(sm[1])] = '#';
            line++;
            s = sm.suffix();
        }
    }

    const int distance = dijkstra(map);

    if (distance == -1) {
        cerr << "Erreur lors de dijkstra" << endl;
    } else {
        cout << distance << endl;
    }

    return 0;
}