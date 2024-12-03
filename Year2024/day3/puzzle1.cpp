#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int year2024_day3_puzzle1() {
    ifstream f("ressources/Year2024/day3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    const regex regexp("mul\\(([0-9]{1,3}),([0-9]{1,3})\\)");
    smatch sm;
    int total = 0;
    while (getline(f, s)) {
        while (regex_search(s, sm, regexp)) {
            total += stoi(sm[1]) * stoi(sm[2]);
            s = sm.suffix();
        }
    }

    cout << total;
    return 0;
}