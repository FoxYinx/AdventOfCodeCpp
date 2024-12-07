#include <iostream>
#include <fstream>
#include "guardMap.h"

using namespace std;

int year2024_day6_puzzle2() {
    ifstream f("ressources/Year2024/day6.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    GuardMap map;
    int guardX = 0;
    int guardY = 0;
    int line = 0;
    while (getline(f, s)) {
        for (int i = 0; i < s.length(); i++) {
            map.map[line][i] = s[i];
            if (s[i] == '^') {
                map.gardX = i;
                map.gardY = line;
                guardX = i;
                guardY = line;
                map.hasBeenThere[line][i] = true;
            }
        }
        line++;
    }

    int nbLoop = 0;
    for (auto & i : map.map) {
        for (char & j : i) {
            if (j == '#' || j == '^') continue;
            j = '#';
            for (int k = 0; k < GuardMap::size * GuardMap::size; k++) {
                map.move();
            }
            if (!map.willBeOutside()) nbLoop++;
            j = '.';
            map.reset(guardX, guardY);
        }
    }

    cout << nbLoop << endl;
    return 0;
}