#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int year2024_day9_puzzle2() {
    ifstream f("ressources/Year2024/test.txt");

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
        int size = 0;
        do {
            size++;
            fin--;
        } while (disk[fin] == disk[fin + 1]);

        int emptySize = 0;
        while (disk[j] == -1) {
            emptySize++;
            j++;
        }
        if (emptySize >= size) {
            for (int i = 0; i < size; i++) {
                disk[j - i] = disk[fin];
                disk[fin - 1] = -1;
            }
            do {
                fin--;
            } while (disk[fin] == -1);
        } else {
            //fixme: que faire quand le premier gap n'est pas bon
        }

        if (j == fin) break;
    }

    for (auto c : disk) {
        if (c == -1) cout << '.';
        else cout << c;
    }
    cout << endl;

    unsigned long checksum = 0;
    for (int i = 0; i < disk.size(); i++) {
        if (disk[i] != -1) checksum += i * disk[i];
    }

    cout << checksum << endl;
    return 0;
}
