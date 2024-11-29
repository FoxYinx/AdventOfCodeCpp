#include <fstream>
#include <iostream>

using namespace std;

int year2022_day2_puzzle1() {
    ifstream f("ressources/day2.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    int score = 0;
    while (getline(f, s)) {
        switch (s[0]) {
            case 'A': {
                switch (s[2]) {
                    case 'X': score += 4; break;
                    case 'Y': score += 8; break;
                    case 'Z': score += 3; break;
                }
                break;
            }
            case 'B': {
                switch (s[2]) {
                    case 'X': score += 1; break;
                    case 'Y': score += 5; break;
                    case 'Z': score += 9; break;
                }
                break;
            }
            case 'C': {
                switch (s[2]) {
                    case 'X': score += 7; break;
                    case 'Y': score += 2; break;
                    case 'Z': score += 6; break;
                }
                break;
            }
        }
    }

    cout << score << endl;
    return 0;
}