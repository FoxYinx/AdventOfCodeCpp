#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include "utils.h"

#define ITER 25

using namespace std;

int year2024_day11_puzzle1() {
    ifstream f("ressources/Year2024/day11.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    getline(f, s);
    istringstream iss(s);
    vector<unsigned long> values;
    unsigned long value;
    while (iss >> value) {
        values.push_back(value);
    }

    for (int j = 0; j < ITER; j++) {
        for (int i = 0; i < values.size(); i++) {
            unsigned int length = GetNumberOfDigits(values[i]);
            if (values[i] == 0) {
                values[i] = 1;
            } else if ((length & 1) == 0) {
                values.insert(values.begin() + i + 1, values[i] % (long) pow(10, length / 2));
                values[i] /= (long) pow(10, length / 2);
                i++;
            } else {
                values[i] *= 2024;
            }
        }
    }

    cout << values.size() << endl;
    return 0;
}