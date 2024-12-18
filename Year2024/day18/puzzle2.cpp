#include <array>
#include <fstream>
#include <iostream>
#include <limits>

#define SIZE 7

using namespace std;


int year2024_day18_puzzle2() {
    ifstream f("ressources/Year2024/test.txt");

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
    while (getline(f, s)) {

    }

    return 0;
}