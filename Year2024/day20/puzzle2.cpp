#include <array>
#include <climits>
#include <fstream>
#include <iostream>
#include <queue>
#include "utils.h"

#define RANGE 20

using namespace std;

constexpr array<pair<int, int>, 4> directions = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

int findBiggerCheats(const array<array<int, SIZE>, SIZE>& distances, int startX, int startY);

int year2024_day20_puzzle2() {
    ifstream f("ressources/Year2024/day20.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    int startX = 0;
    int startY = 0;

    string s;
    array<array<char, SIZE>, SIZE> map = {};
    array<array<int, SIZE>, SIZE> distances = {};
    for (auto& row : distances) {
        row.fill(INT_MAX);
    }
    int line = 0;
    while (getline(f, s)) {
        for (int i = 0; i < SIZE; i++) {
            map[line][i] = s[i];
            if (s[i] == 'S') {
                startX = i;
                startY = line;
            }
        }
        line++;
    }

    bfs(map, distances, startX, startY);
    const int cheats = findBiggerCheats(distances, startX, startY);

    cout << cheats << endl;
    return 0;
}

int findBiggerCheats(const array<array<int, SIZE>, SIZE>& distances, const int startX, const int startY) {
    queue<array<int, 2>> file;
    file.push({startY, startX});

    int possibleCheats = 0;

    while (!file.empty()) {
        array<int, 2> node = file.front();
        const int y = node[0];
        const int x = node[1];
        file.pop();

        for (const auto &[dx, dy]: directions) {
            const int nx = x + dx;
            const int ny = y + dy;
            if (distances[ny][nx] == distances[y][x] + 1) {
                file.push({ny, nx});
            }
        }

        for (int i = -RANGE; i <= RANGE; i++) {
            for (int j = -RANGE + abs(i); j <= RANGE - abs(i); j++) {
                int nx = x + j;
                int ny = y + i;
                if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
                    if (distances[ny][nx] != INT_MAX && distances[ny][nx] - distances[y][x] - abs(i) - abs(j) >= 100) possibleCheats++;
                }
            }
        }
    }

    return possibleCheats;
}