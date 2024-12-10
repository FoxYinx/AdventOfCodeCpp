#include <fstream>
#include <iostream>
#include <array>
#include <vector>

#define SIZE 8

using namespace std;

int year2024_day10_puzzle1() {
    ifstream f("ressources/Year2024/test.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    array<array<int, SIZE>, SIZE> map = {};
    int line = 0;
    while (getline(f, s)) {
        for (int i = 0; i < SIZE; i++) {
            map[line][i] = s.at(i) - '0';
        }
        line++;
    }

    int trails = 0;
    vector<array<int, 2>> tmp;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (map[i][j] == 0) {
                if ()
            }
        }
    }

    return 0;
}
