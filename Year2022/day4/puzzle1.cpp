#include <fstream>
#include <iostream>

using namespace std;

int year2022_day4_puzzle1() {
    ifstream f("ressources/day4.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    int total = 0;
    while (getline(f, s)) {
    }

    return 0;
}