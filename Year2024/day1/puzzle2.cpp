#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int year2024_day1_puzzle2() {
    ifstream f("ressources/Year2024/day1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    vector<int> left;
    vector<int> right;
    while (getline(f, s)) {
        int l;
        int r;
        sscanf(s.c_str(), "%d %d", &l, &r);
        left.push_back(l);
        right.push_back(r);
    }

    int similarityScore = 0;
    for (const int leftValue: left) {
        int appearance = 0;
        for (const int rightValue: right) {
            if (leftValue == rightValue) appearance++;
        }
        similarityScore += leftValue * appearance;
    }

    cout << similarityScore << endl;
    return 0;
}