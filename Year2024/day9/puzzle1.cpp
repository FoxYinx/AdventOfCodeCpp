#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int year2024_day9_puzzle1() {
    ifstream f("ressources/Year2024/day9.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    vector<int> disk;
    getline(f, s);

    int id = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.at(i) - '0'; j++) {
            disk.push_back(id);
        }
        id++;
        i++;
         if (i == s.size()) break;
        for (int j = 0; j < s.at(i) - '0'; j++) {
            disk.push_back(-1);
        }
    }

    unsigned long fin = disk.size() - 1;
    for (int j = 0; j < disk.size(); j++) {
        if (disk[j] == -1) {
            disk[j] = disk[fin];
            disk[fin] = -1;
            do {
                fin--;
            } while (disk[fin] == -1);
        }
        if (j == fin) break;
    }

    long long checksum = 0;
    for (int i = 0; i < disk.size(); i++) {
        if (disk[i] != -1) checksum += i * disk[i];
    }

    cout << checksum << endl;
    return 0;
}
