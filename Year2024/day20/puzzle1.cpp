#include <array>
#include <fstream>
#include <iostream>
#include <queue>

#include "utils.h"

using namespace std;

constexpr array<pair<int, int>, 4> directions = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

int findCheats(const array<array<int, SIZE>, SIZE>& distances, int startX, int startY);

int year2024_day20_puzzle1() {
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
    const int cheats = findCheats(distances, startX, startY);

    cout << cheats << endl;
    return 0;
}

int findCheats(const array<array<int, SIZE>, SIZE>& distances, const int startX, const int startY) {
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

            const int nnx = x + dx * 2;
            const int nny = y + dy * 2;
            if (nnx >= 0 && nnx < SIZE && nny >= 0 && nny < SIZE) {
                if (distances[nny][nnx] != INT_MAX && distances[nny][nnx] - distances[y][x] - 2 >= 100 && distances[ny][nx] == INT_MAX) possibleCheats++;
            }
        }
    }

    return possibleCheats;
}