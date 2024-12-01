#include <fstream>
#include <iostream>

using namespace std;

int year2022_day3_puzzle1() {
    ifstream f("ressources/Year2022/day3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    int totalPriority = 0;
    while (getline(f, s)) {
        char toFind = 'A';
        for (int i = 0; i < s.length() / 2; i++) {
            bool flag = false;
            for (int j = s.length() / 2; j < s.length(); j++) {
                if (s[i] == s[j]) {
                    flag = true;
                    toFind = s[i];
                    break;
                }
            }
            if (flag) break;
        }
        int number = toFind - 96;
        if (number < 0) number += 58;
        totalPriority += number;
    }

    cout << totalPriority << endl;
    return 0;
}