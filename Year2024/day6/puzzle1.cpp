#include <iostream>
#include <fstream>
#include "guardMap.h"

using namespace std;

int year2024_day6_puzzle1() {
    ifstream f("ressources/Year2024/day6.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    GuardMap map;
    int line = 0;
    while (getline(f, s)) {
        for (int i = 0; i < s.length(); i++) {
            map.map[line][i] = s[i];
            if (s[i] == '^') {
                map.gardX = i;
                map.gardY = line;
                map.hasBeenThere[line][i] = true;
            }
        }
        line++;
    }

    while (map.move()) {}

    cout << map.allCases() << endl;
    return 0;
}