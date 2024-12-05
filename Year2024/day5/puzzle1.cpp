#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

int year2024_day5_puzzle1() {
    ifstream f("ressources/Year2024/day5.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    map<int, vector<int>> apres;
    int correctMiddle = 0;
    bool secondPart = false;
    while (getline(f, s)) {
        if (s.empty()) {
            secondPart = true;
            continue;
        }
        if (!secondPart) {
            int num1, num2;
            char delimiter;
            istringstream iss(s);
            iss >> num1 >> delimiter >> num2 && delimiter == '|';

            if (apres.contains(num1)) {
                apres.at(num1).push_back(num2);
            } else {
                vector tmp = {num2};
                apres[num1] = tmp;
            }
        } else {
            vector<int> pages;
            string tmp;
            stringstream ss(s);
            while (getline(ss, tmp, ',')) {
                pages.push_back(stoi(tmp));
            }
            bool isValid = true;
            for (int i = 1; i < pages.size(); i++) {
                if (apres.contains(pages[i])) {
                    for (int j = 0; j < i; j++) {
                        vector<int> numbers = apres[pages[i]];
                        if (auto it = ranges::find(numbers, pages[j]); it != numbers.end()) {
                            isValid = false;
                            break;
                        }
                    }
                    if (!isValid) break;
                }
            }
            if (isValid) correctMiddle += pages[(pages.size() - 1) / 2];
        }
    }

    cout << correctMiddle << endl;
    return 0;
}