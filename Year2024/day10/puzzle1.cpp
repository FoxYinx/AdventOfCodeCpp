#include <fstream>
#include <iostream>
#include <array>
#include <queue>
#include <set>

#define SIZE 43

using namespace std;

void searchUnique(const array<array<int, SIZE>, SIZE>& map, int i, int j, set<array<int, 4>>& trails);

int year2024_day10_puzzle1() {
    ifstream f("ressources/Year2024/day10.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    array<array<int, SIZE>, SIZE> map = {};
    int line = 0;
    while (getline(f, s)) {
        for (int i = 0; i < SIZE; i++) {
            map[line][i] = s.at(i) - '0';
        }
        line++;
    }

    set<array<int, 4>> trails;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (map[i][j] == 0) searchUnique(map, i, j, trails);
        }
    }

    cout << trails.size() << endl;
    return 0;
}

void searchUnique(const array<array<int, SIZE>, SIZE>& map, const int i, const int j, set<array<int, 4>>& trails) {
    queue<array<int, 2>> file;
    file.push({i, j});

    while (!file.empty()) {
        array<int, 2> node = file.front();
        const int y = node[0];
        const int x = node[1];
        file.pop();

        if (y - 1 >= 0 && map[y - 1][x] == map[y][x] + 1) {
            if (map[y - 1][x] == 9) trails.insert({i, j, y - 1, x});
            else file.push({y - 1, x});
        }
        if (y + 1 < SIZE && map[y + 1][x] == map[y][x] + 1) {
            if (map[y + 1][x] == 9) trails.insert({i, j, y + 1, x});
            else file.push({y + 1, x});
        }

        if (x - 1 >= 0 && map[y][x - 1] == map[y][x] + 1) {
            if (map[y][x - 1] == 9) trails.insert({i, j, y, x - 1});
            else file.push({y, x - 1});
        }
        if (x + 1 < SIZE && map[y][x + 1] == map[y][x] + 1) {
            if (map[y][x + 1] == 9) trails.insert({i, j, y, x + 1});
            else file.push({y, x + 1});
        }
    }
}
