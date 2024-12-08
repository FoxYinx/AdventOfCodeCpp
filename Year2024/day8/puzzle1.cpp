#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <array>

#define SIZE 50

using namespace std;

int year2024_day8_puzzle1() {
    ifstream f("ressources/Year2024/day8.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    map<char, vector<array<int, 2>>> antennas;
    array<array<bool, SIZE>, SIZE> antinodes = {};
    int line = 0;
    while (getline(f, s)) {
        for (int i = 0; i < SIZE; i++) {
            char c = s.at(i);
            if (c == '.') continue;
            antennas[c].push_back({i, line});
        }
        line++;
    }

    for(const auto &[key, value] : antennas) {
        for (int i = 0; i < value.size(); i++) {
            for (int j = 0; j < value.size(); j++) {
                if (i == j) continue;
                int dx = value[i][0] - value[j][0];
                int dy = value[i][1] - value[j][1];
                if (value[i][0] + dx < SIZE && value[i][0] + dx >= 0 && value[i][1] + dy < SIZE && value[i][1] + dy >= 0) antinodes[value[i][0] + dx][value[i][1] + dy] = true;
                if (value[j][0] - dx < SIZE && value[j][0] - dx >= 0 && value[j][1] - dy < SIZE && value[j][1] - dy >= 0) antinodes[value[j][0] - dx][value[j][1] - dy] = true;
            }
        }
    }

    int uniqueAntinodes = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (antinodes[i][j]) uniqueAntinodes++;
        }
    }

    cout << uniqueAntinodes << endl;
    return 0;
}