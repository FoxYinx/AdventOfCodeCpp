#include <array>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include "dijkstra.h"

using namespace std;

struct Node {
    int x, y, dist;
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

int dijkstra(const array<array<char, SIZE>, SIZE>& map) {
    constexpr array<pair<int, int>, 4> directions = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

    array<array<int, SIZE>, SIZE> dist = {};
    for (auto& row : dist) {
        row.fill(numeric_limits<int>::max());
    }

    priority_queue<Node, vector<Node>, greater<>> pq;
    pq.push({0, 0, 0});
    dist[0][0] = 0;

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        if (node.y == SIZE - 1 && node.x == SIZE - 1) return node.dist;

        for (const auto &[dx, dy]: directions) {
            const int nx = node.x + dx;
            const int ny = node.y + dy;
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && map[ny][nx] != '#' && node.dist + 1 < dist[ny][nx]) {
                dist[ny][nx] = node.dist + 1;
                pq.push({nx, ny, dist[ny][nx]});
            }
        }
    }

    return -1;
}

