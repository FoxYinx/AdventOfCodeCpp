#include <fstream>
#include <iostream>

using namespace std;

int fuelCalculation(int fuel);

int year2019_day1_puzzle2() {
    ifstream f("ressources/Year2019/day1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    int fuel = 0;
    while (getline(f, s)) {
        fuel += fuelCalculation(stoi(s));
    }

    cout << fuel << endl;
    return 0;
}

int fuelCalculation(int fuel) {
    int weight = fuel / 3 - 2;
    if (weight <= 0) return 0;
    return weight + fuelCalculation(weight);
}
