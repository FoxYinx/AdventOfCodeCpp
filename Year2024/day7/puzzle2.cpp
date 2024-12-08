#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <valarray>

using namespace std;

vector<vector<char>> getAllCombinations2(int k);

void generateCombinations2(vector<vector<char>> &allCombinations, vector<char> &combination, int k, int index);

unsigned GetNumberOfDigits(unsigned i);

int year2024_day7_puzzle2() {
    ifstream f("ressources/Year2024/day7.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    char colon;
    long totalValid = 0;
    while (getline(f, s)) {
        stringstream ss(s);
        long goal;
        long num;
        vector<long> possibleLongs;
        ss >> goal >> colon;
        while (ss >> num) {
            possibleLongs.push_back(num);
        }
        vector<long> memory(possibleLongs);

        vector<vector<char>> combinations = getAllCombinations2(possibleLongs.size() - 1);
        bool flag = false;
        for (const auto &combination: combinations) {
            for (int i = 0; i < combination.size(); i++) {
                switch (combination[i]) {
                    case '+':
                        possibleLongs[i + 1] = possibleLongs[i] + possibleLongs[i + 1];
                        break;
                    case '*':
                        possibleLongs[i + 1] = possibleLongs[i] * possibleLongs[i + 1];
                        break;
                    case '|':
                        possibleLongs[i + 1] = possibleLongs[i] * pow(10, GetNumberOfDigits(possibleLongs[i + 1])) +
                                               possibleLongs[i + 1];
                        break;
                }
            }
            if (possibleLongs[possibleLongs.size() - 1] == goal) {
                flag = true;
                break;
            } else {
                possibleLongs = memory;
            }
        }
        if (flag) totalValid += goal;
    }

    cout << totalValid << endl;
    return 0;
}

vector<vector<char>> getAllCombinations2(int k) {
    vector<vector<char>> allCombinations;
    vector<char> combination(k);
    generateCombinations2(allCombinations, combination, k, 0);
    return allCombinations;
}

void generateCombinations2(vector<vector<char>> &allCombinations, vector<char> &combination, int k, int index) {
    if (index == k) {
        allCombinations.push_back(combination);
        return;
    }

    combination[index] = '+';
    generateCombinations2(allCombinations, combination, k, index + 1);

    combination[index] = '*';
    generateCombinations2(allCombinations, combination, k, index + 1);

    combination[index] = '|';
    generateCombinations2(allCombinations, combination, k, index + 1);
}

unsigned GetNumberOfDigits(unsigned i) {
    return i > 0 ? (int) log10((double) i) + 1 : 1;
}