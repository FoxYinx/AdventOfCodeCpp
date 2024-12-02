#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int year2024_day2_puzzle1() {
    ifstream f("ressources/Year2024/day2.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    int safe = 0;
    while (getline(f, s)) {
        istringstream iss(s);
        string compare;
        string value;
        bool safeA = true;
        bool safeD = true;
        while (iss >> value) {
            if (compare.empty()) {
                compare = value;
                continue;
            }
            if (stoi(value) - stoi(compare) == 0) {
                safeA = false;
                safeD = false;
                break;
            }
            if (stoi(value) - stoi(compare) > 0 || stoi(value) - stoi(compare) < -3) safeD = false;
            if (stoi(value) - stoi(compare) < 0 || stoi(value) - stoi(compare) > 3) safeA = false;
            compare = value;
        }
        if (safeA || safeD) safe++;
    }

    cout << safe << endl;
    return 0;
}