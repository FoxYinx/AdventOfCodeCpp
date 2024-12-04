#include <fstream>
#include <iostream>

using namespace std;

int year2019_day1_puzzle1() {
    ifstream f("ressources/Year2019/day1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    int fuel = 0;
    while (getline(f, s)) {
        fuel += stoi(s) / 3 - 2;
    }

    cout << fuel << endl;
    return 0;
}
