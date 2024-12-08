#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int year2024_day2_puzzle2() {
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
        string number;
        bool safeA = true;
        bool safeD = true;
        vector<string> values;
        while (iss >> number) {
            values.push_back(number);
        }
        for (int i = 0; i < values.size(); i++) {
            vector reduced(values);
            reduced.erase(reduced.begin() + i);
            safeA = true;
            safeD = true;
            compare = "";
            for (const string &value: reduced) {
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
            if (safeA || safeD) break;
        }

        if (safeA || safeD) safe++;
    }

    cout << safe << endl;
    return 0;
}