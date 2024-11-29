#include <fstream>
#include <iostream>

using namespace std;

int year2022_day1_puzzle1() {
    ifstream f("ressources/day1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    int maxCalories = 0;
    int currentCalories = 0;
    while (getline(f, s)) {
        if (s.empty()) {
            if (currentCalories > maxCalories) maxCalories = currentCalories;
            currentCalories = 0;
        } else {
            currentCalories += stoi(s);
        }
    }

    cout << maxCalories << endl;

    f.close();
    return 0;
}
