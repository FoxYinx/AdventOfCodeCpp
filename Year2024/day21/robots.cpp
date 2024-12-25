#include "robots.h"

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct StackElement {
    int x;
    int y;
    std::vector<uint8_t> path;

    StackElement(const int x, const int y, std::vector<uint8_t> path)
        : x(x), y(y), path(std::move(path)) {}
};

template<size_t N>
vector<vector<uint8_t>> findShortestPaths(const array<array<uint8_t, 3>, N>& keypad, uint8_t from, uint8_t to) {
    if (from == to) {
        vector<vector<uint8_t>> result = {{{'A'}}};
        return result;
    }

    array start = {0, 0};
    array end = {0, 0};

    for (int32_t y = 0; y < N; y++) {
        for (int32_t x = 0; x < 3; x++) {
            if (keypad[y][x] == from) {
                start = array{x, y};
            }
            if (keypad[y][x] == to) {
                end = {x, y};
            }
        }
    }

    vector dists(N, vector(3, UINT64_MAX));
    queue<array<int32_t, 3>> file;
    file.push({start[0], start[1], 0});

    while (!file.empty()) {
        const int32_t x = file.front()[0];
        const int32_t y = file.front()[1];
        const int32_t steps = file.front()[2];
        dists[y][x] = steps;
        file.pop();

        for (const auto &[dx, dy] : directions) {
            int32_t nx = x + dx;
            int32_t ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < 3 && ny < keypad.size() && keypad[ny][nx] != ' ' && dists[ny][nx] == UINT64_MAX) {
                file.push({nx, ny, steps + 1});
            }
        }
    }

    vector<vector<uint8_t>> paths = {};
    stack<StackElement> stack = {};
    stack.emplace(end[0], end[1], vector<uint8_t>{'A'});

    while (!stack.empty()) {
        const int32_t x = stack.top().x;
        const int32_t y = stack.top().y;
        vector<uint8_t> path = stack.top().path;
        stack.pop();

        if (x == start[0] && y == start[1]) {
            paths.push_back(path);
            continue;
        }
        int iteration = 0;
        for (const auto &[dx, dy] : directions) {
            int32_t nx = x + dx;
            int32_t ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < 3 && ny < keypad.size() && dists[ny][nx] < dists[y][x]) {
                uint8_t c = 0;
                switch (iteration) {
                    case 0: c = '<'; break;
                    case 1: c = '^'; break;
                    case 2: c = '>'; break;
                    case 3: c = 'v'; break;
                    default: cerr << "Error in findShortestPaths" << endl;
                }
                vector newPath = {c};
                newPath.insert(newPath.end(), path.begin(), path.end());
                stack.emplace(nx, ny, newPath);
            }
            iteration++;
        }
    }

    return paths;
}

template<size_t N>
uint64_t findShortestSequence(const vector<uint8_t> &s, const uint8_t depth, const bool highest) {
    uint8_t cursor = 'A';
    uint64_t result = 0;
    for (auto& c : s) {
        const void* keypad = highest ? static_cast<const void*>(&numeric) : static_cast<const void*>(&directional);
        vector<vector<uint8_t>> paths = findShortestPaths<N>(*static_cast<const array<array<uint8_t, 3>, N>*>(keypad), cursor, c);

        if (depth == 0) {
            result += paths[0].size();
        } else {
            vector<uint64_t> path_lengths(paths.size());
            transform(paths.begin(), paths.end(), path_lengths.begin(),
                [depth](const vector<uint8_t>& p) {
                    return findShortestSequence<2>(p, depth - 1, false);
                });
            result += *ranges::min_element(path_lengths);
        }

        cursor = c;
    }

    return result;
}

template vector<vector<uint8_t>> findShortestPaths<4>(const array<array<uint8_t, 3>, 4>& keypad, uint8_t from, uint8_t to);
template vector<vector<uint8_t>> findShortestPaths<2>(const array<array<uint8_t, 3>, 2>& keypad, uint8_t from, uint8_t to);
template uint64_t findShortestSequence<4>(const vector<uint8_t>& s, uint8_t depth, bool highest);
template uint64_t findShortestSequence<2>(const vector<uint8_t>& s, uint8_t depth, bool highest);