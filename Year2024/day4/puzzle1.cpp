#include <iostream>
#include <fstream>
#include <vector>
#include "verifyXMAS.h"

#define SIZE 140

using namespace std;

int year2024_day4_puzzle1() {
    ifstream f("ressources/Year2024/day4.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    vector<vector<char>> tableau;
    string s;
    int xmas = 0;
    while (getline(f, s)) {
        tableau.emplace_back(s.begin(), s.end());
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (horizontal(i, j, tableau)) xmas++;
            if (vertical(i, j, tableau)) xmas++;
            if (diag_right(i, j, tableau)) xmas++;
            if (diag_left(i, j, tableau)) xmas++;
        }
    }

    cout << xmas << endl;
    return 0;
}