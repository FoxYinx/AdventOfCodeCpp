#include <array>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>

#define SIZE 141

using namespace std;

struct Node {
    int x, y, dist;
    char dir;
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

int dijkstra(const array<array<char, SIZE>, SIZE>& map);

int year2024_day16_puzzle1() {
    ifstream f("ressources/Year2024/day16.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    array<array<char, SIZE>, SIZE> map = {};
    int line = 0;
    while (getline(f, s)) {
        for (int i = 0; i < SIZE; i++) {
            map[line][i] = s[i];
        }
        line++;
    }

    const int distance = dijkstra(map);

    if (distance == -1) {
        cerr << "Erreur lors de dijkstra" << endl;
    } else {
        cout << distance << endl;
    }
    return 0;
}

int dijkstra(const array<array<char, SIZE>, SIZE>& map) {
    constexpr array<tuple<int, int, char>, 4> directions = {{{0, 1, 'd'}, {1, 0, 'r'}, {0, -1, 'u'}, {-1, 0, 'l'}}};

    array<array<int, SIZE>, SIZE> dist = {};
    for (auto& row : dist) {
        row.fill(numeric_limits<int>::max());
    }

    priority_queue<Node, vector<Node>, greater<>> pq;
    pq.push({1, SIZE - 2, 0, 'r'});
    dist[SIZE - 2][1] = 0;

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        if (map[node.y][node.x] == 'E') return node.dist;

        for (const auto &[dx, dy, dir]: directions) {
            const int nx = node.x + dx;
            const int ny = node.y + dy;
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && map[ny][nx] != '#' && node.dist + 1001 < dist[ny][nx]) {
                dist[ny][nx] = node.dir == dir ? node.dist + 1 : node.dist + 1001;
                pq.push({nx, ny, dist[ny][nx], dir});
            }
        }
    }

    return -1;
}
