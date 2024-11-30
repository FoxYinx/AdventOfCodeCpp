#include <fstream>
#include <iostream>

using namespace std;

int year2022_day3_puzzle2() {
    ifstream f("ressources/day3.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string first_line;
    string second_line;
    string third_line;
    int totalPriority = 0;
    while (f.peek() != EOF) {
        getline(f, first_line);
        getline(f, second_line);
        getline(f, third_line);
        char toFind = 'A';
        for (int i = 0; i < first_line.length(); i++) {
            bool flag = false;
            for (int j = 0; j < second_line.length(); j++) {
                if (first_line[i] == second_line[j]) {
                    for (int k = 0; k < third_line.length(); k++) {
                        if (second_line[j] == third_line[k]) {
                            flag = true;
                            toFind = first_line[i];
                            break;
                        }
                    }
                }
                if (flag) break;
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