#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int year2024_day1_puzzle1() {
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

    ranges::sort(left);
    ranges::sort(right);

    int sum = 0;
    for (int i = 0; i < left.size(); i++) {
        sum += abs(left[i] - right[i]);
    }

    cout << sum << endl;
    return 0;
}
