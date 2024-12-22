#include <queue>
#include <climits>
#include "utils.h"

constexpr array<pair<int, int>, 4> directions = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

void bfs(const array<array<char, SIZE>, SIZE>& map, array<array<int, SIZE>, SIZE>& distances, const int startX, const int startY) {
    queue<array<int, 2>> file;
    file.push({startY, startX});
    distances[startY][startX] = 0;

    while (!file.empty()) {
        array<int, 2> node = file.front();
        const int y = node[0];
        const int x = node[1];
        file.pop();

        if (map[y][x] == 'E') break;

        for (const auto &[dx, dy]: directions) {
            const int nx = x + dx;
            const int ny = y + dy;
            if (map[ny][nx] != '#' && distances[ny][nx] == INT_MAX) {
                file.push({ny, nx});
                distances[ny][nx] = distances[y][x] + 1;
            }
        }
    }
}