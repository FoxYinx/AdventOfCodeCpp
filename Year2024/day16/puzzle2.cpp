#include <array>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <vector>

#define SIZE 141

using namespace std;

struct Node {
    int x, y, dist;
    char dir;
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

int dijkstraBis(const array<array<char, SIZE>, SIZE>& map, array<array<int, SIZE>, SIZE>& dist);
int dfs(int i, int j, const array<array<int, SIZE>, SIZE>& dist);

constexpr array<tuple<int, int, char>, 4> directions = {{{0, 1, 'd'}, {1, 0, 'r'}, {0, -1, 'u'}, {-1, 0, 'l'}}};

int year2024_day16_puzzle2() {
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

    array<array<int, SIZE>, SIZE> dist = {};
    for (auto& row : dist) {
        row.fill(numeric_limits<int>::max());
    }

    if (const int distance = dijkstraBis(map, dist); distance == numeric_limits<int>::max()) {
        cerr << "Erreur dans Dijkstra" << endl;
        return -1;
    }

    cout << dfs(SIZE - 2, 1, dist) << endl;
    return 0;
}

int dijkstraBis(const array<array<char, SIZE>, SIZE>& map, array<array<int, SIZE>, SIZE>& dist) {
    priority_queue<Node, vector<Node>, greater<>> pq;
    pq.push({1, SIZE - 2, 0, 'r'});
    dist[SIZE - 2][1] = 0;

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        if (map[node.y][node.x] == 'E') continue;

        for (const auto &[dx, dy, dir]: directions) {
            const int nx = node.x + dx;
            const int ny = node.y + dy;
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && map[ny][nx] != '#') {
                if (const int new_dist = node.dist + (node.dir == dir ? 1 : 1001); new_dist < dist[ny][nx]) {
                    dist[ny][nx] = new_dist;
                    pq.push({nx, ny, new_dist, dir});
                }
            }
        }
    }

    return dist[1][SIZE - 2];
}

int dfs(const int i, const int j, const array<array<int, SIZE>, SIZE>& dist) {
    stack<array<int, 2>> pile;
    pile.push({j, i});
    array<array<bool, SIZE>, SIZE> marquage = {};
    marquage[j][i] = true;

    while (!pile.empty()) {
        array<int, 2> node = pile.top();
        const int y = node[0];
        const int x = node[1];
        pile.pop();

        for (const auto &[dx, dy, dir]: directions) {
            const int nx = x + dx;
            const int ny = y + dy;
            if (dist[ny][nx] == dist[y][x] - 1 || dist[ny][nx] == dist[y][x] - 1001) {
                pile.push({ny, nx});
                marquage[ny][nx] = true;
            } else if (dist[ny][nx] == dist[y][x] + 999) {
                const int nnx = x - dx;
                const int nny = y - dy;
                if (dist[nny][nnx] == dist[ny][nx] + 2) {
                    marquage[ny][nx] = true;
                    marquage[nny][nnx] = true;
                    pile.push({ny, nx});
                }
            }
        }
    }

    int nb = 0;
    for (int a = 0; a < SIZE; a++) {
        for (int b = 0; b < SIZE; b++) {
            if (marquage[a][b]) nb++;
        }
    }
    return nb;
}
