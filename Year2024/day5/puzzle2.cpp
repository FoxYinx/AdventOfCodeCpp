#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int year2024_day5_puzzle2() {
    ifstream f("ressources/Year2024/day5.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    while (getline(f, s)) {

    }

    return 0;
}