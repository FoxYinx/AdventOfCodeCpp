#include <fstream>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

int year2024_day9_puzzle2() {
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

    vector<array<int, 2>> empty;
    vector<array<int, 2>> block;

    for (int i = 0; i < disk.size(); i++) {
        if (disk.at(i) != -1) {
            block.push_back({i, 1});
            do {
                i++;
                block.at(block.size() - 1)[1]++;
                if (i == disk.size()) break;
            } while (disk.at(i - 1) == disk.at(i));
            block.at(block.size() - 1)[1]--;
            i--;
        } else {
            empty.push_back({i, 1});
            do {
                i++;
                empty.at(empty.size() - 1)[1]++;
                if (i == disk.size()) break;
            } while (disk.at(i - 1) == disk.at(i));
            empty.at(empty.size() - 1)[1]--;
            i--;
        }
    }

    for (int i = block.size() - 1; i >= 0; i--) {
        for (auto & space : empty) {
            if (block[i][0] <= space[0]) break;
            if (space[1] >= block[i][1] ) {
                for (int j = 0; j < block[i][1]; j++) {
                    disk[space[0]] = disk[block[i][0]];
                    space[0]++;
                    space[1]--;
                }
                for (int j = 0; j < block[i][1]; j++) disk[block[i][0] + j] = -1;
                break;
            }
        }
    }

    long long checksum = 0;
    for (int i = 0; i < disk.size(); i++) {
        if (disk[i] != -1) checksum += i * disk[i];
    }

    cout << checksum << endl;
    return 0;
}
