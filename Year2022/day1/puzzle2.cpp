#include <fstream>
#include <iostream>


using namespace std;

int year2022_day1_puzzle2() {
    ifstream f("ressources/day1.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    int maxCalories[]= {0, 0, 0};
    int currentCalories = 0;
    while(getline(f, s)) {
        if (s.empty()) {
            if (currentCalories > maxCalories[0]) {
                maxCalories[2] = maxCalories[1];
                maxCalories[1] = maxCalories[0];
                maxCalories[0] = currentCalories;
            } else if (currentCalories > maxCalories[1]) {
                maxCalories[2] = maxCalories[1];
                maxCalories[1] = currentCalories;
            } else if (currentCalories > maxCalories[2]) {
                maxCalories[2] = currentCalories;
            }
            currentCalories = 0;
        } else {
            currentCalories += stoi(s);
        }
    }

    cout << maxCalories[0] + maxCalories[1] + maxCalories[2] << endl;

    f.close();
    return 0;
}