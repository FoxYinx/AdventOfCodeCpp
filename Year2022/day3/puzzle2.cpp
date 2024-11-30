#include <fstream>
#include <iostream>

using namespace std;

int year2022_day3_puzzle2() {
    ifstream f("ressources/day3.txt");

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