#include <fstream>
#include <iostream>
#include <array>

#define SIZE 50

using namespace std;

bool mayIUp(int x, int y, const array<array<char, SIZE * 2>, SIZE>& map);
bool mayIDown(int x, int y, const array<array<char, SIZE * 2>, SIZE>& map);
void moveUp(int x, int y, array<array<char, SIZE * 2>, SIZE>& map);
void moveDown(int x, int y, array<array<char, SIZE * 2>, SIZE>& map);
void print(const array<array<char, SIZE * 2>, SIZE>& map);

int year2024_day15_puzzle2() {
    ifstream f("ressources/Year2024/day15.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    array<array<char, SIZE * 2>, SIZE> map = {};
    int line = 0;
    int rx = 0;
    int ry = 0;
    while (getline(f, s)) {
        if (line < SIZE) {
            for (int i = 0; i < SIZE; i++) {
                switch (s[i]) {
                    case '@': {
                        map[line][i * 2] = '@';
                        map[line][i * 2 + 1] = '.';
                        rx = i * 2;
                        ry = line;
                        break;
                    }
                    case '.': {
                        map[line][i * 2] = '.';
                        map[line][i * 2 + 1] = '.';
                        break;
                    }
                    case 'O': {
                        map[line][i * 2] = '[';
                        map[line][i * 2 + 1] = ']';
                        break;
                    }
                    case '#': {
                        map[line][i * 2] = '#';
                        map[line][i * 2 + 1] = '#';
                        break;
                    }
                    default: cerr << "Unknown character: " << s[i] << endl;
                }
            }
        } else if (line > SIZE) {
            for (const char i : s) {
                switch (i) {
                    case '^': {
                        switch (map[ry - 1][rx]) {
                            case '.': {
                                map[ry - 1][rx] = '@';
                                map[ry][rx] = '.';
                                ry--;
                                break;
                            }
                            case '[': case ']': {
                                if (mayIUp(rx, ry - 1, map)) {
                                    moveUp(rx, ry - 1, map);
                                    map[ry - 1][rx] = '@';
                                    map[ry][rx] = '.';
                                    ry--;
                                }
                                break;
                            }
                            default: break;
                        }
                        break;
                    }
                    case '>': {
                        switch (map[ry][rx + 1]) {
                            case '.': {
                                map[ry][rx + 1] = '@';
                                map[ry][rx] = '.';
                                rx++;
                                break;
                            }
                            case '[': case ']': {
                                int nb = 1;
                                bool flag = false;
                                for (int j = rx + 1; j <= SIZE * 2; j++) {
                                    switch (map[ry][j + 1]) {
                                        case '[': case ']': {
                                            nb++;
                                            break;
                                        }
                                        case '.': {
                                            for (int l = 0; l < nb + 1; l++) {
                                                map[ry][j - l + 1] = map[ry][j - l];
                                                map[ry][j - l] = '.';
                                            }
                                            rx++;
                                        }
                                        default: flag = true;
                                    }
                                    if (flag) break;
                                }
                                break;
                            }
                            default: break;
                        }
                        break;
                    }
                    case 'v': {
                        switch (map[ry + 1][rx]) {
                            case '.': {
                                map[ry + 1][rx] = '@';
                                map[ry][rx] = '.';
                                ry++;
                                break;
                            }
                            case '[': case ']': {
                                if (mayIDown(rx, ry + 1, map)) {
                                    moveDown(rx, ry + 1, map);
                                    map[ry + 1][rx] = '@';
                                    map[ry][rx] = '.';
                                    ry++;
                                }
                                break;
                            }
                            default: break;
                        }
                        break;
                    }
                    case '<': {
                        switch (map[ry][rx - 1]) {
                            case '.': {
                                map[ry][rx - 1] = '@';
                                map[ry][rx] = '.';
                                rx--;
                                break;
                            }
                            case '[': case ']': {
                                int nb = 1;
                                bool flag = false;
                                for (int j = rx - 1; j >= 0; j--) {
                                    switch (map[ry][j - 1]) {
                                        case '[': case ']': {
                                            nb++;
                                            break;
                                        }
                                        case '.': {
                                            for (int l = 0; l < nb + 1; l++) {
                                                map[ry][j + l - 1] = map[ry][j + l];
                                                map[ry][j + l] = '.';
                                            }
                                            rx--;
                                        }
                                        default: flag = true;
                                    }
                                    if (flag) break;
                                }
                            }
                            default: break;
                        }
                        break;
                    }
                    default: cerr << "Direction impossible: " << i << endl;
                }
            }
        }
        line++;
    }

    int score = 0;
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE * 2; x++) {
            if (map[y][x] == '[') score += 100 * y + x;
        }
    }

    cout << score << endl;
    return 0;
}

void moveUp(const int x, const int y, array<array<char, SIZE * 2>, SIZE>& map) {
    if (map[y][x] == '[') {
        if (map[y - 1][x] == '[' || map[y - 1][x] == ']') moveUp(x, y - 1, map);
        if (map[y - 1][x + 1] == '[' || map[y - 1][x + 1] == ']') moveUp(x + 1, y - 1, map);
        map[y - 1][x] = map[y][x];
        map[y][x] = '.';
        map[y - 1][x + 1] = map[y][x + 1];
        map[y][x + 1] = '.';
    } else {
        if (map[y - 1][x] == '[' || map[y - 1][x] == ']') moveUp(x, y - 1, map);
        if (map[y - 1][x - 1] == '[' || map[y - 1][x - 1] == ']') moveUp(x - 1, y - 1, map);
        map[y - 1][x] = map[y][x];
        map[y][x] = '.';
        map[y - 1][x - 1] = map[y][x - 1];
        map[y][x - 1] = '.';
    }
}

void moveDown(const int x, const int y, array<array<char, SIZE * 2>, SIZE>& map) {
    if (map[y][x] == '[') {
        if (map[y + 1][x] == '[' || map[y + 1][x] == ']') moveDown(x, y + 1, map);
        if (map[y + 1][x + 1] == '[' || map[y + 1][x + 1] == ']') moveDown(x + 1, y + 1, map);
        map[y + 1][x] = map[y][x];
        map[y][x] = '.';
        map[y + 1][x + 1] = map[y][x + 1];
        map[y][x + 1] = '.';
    } else {
        if (map[y + 1][x] == '[' || map[y + 1][x] == ']') moveDown(x, y + 1, map);
        if (map[y + 1][x - 1] == '[' || map[y + 1][x - 1] == ']') moveDown(x - 1, y + 1, map);
        map[y + 1][x] = map[y][x];
        map[y][x] = '.';
        map[y + 1][x - 1] = map[y][x - 1];
        map[y][x - 1] = '.';
    }
}

bool mayIUp(const int x, const int y, const array<array<char, SIZE * 2>, SIZE>& map) {
    bool left = false;
    bool right = false;
    if (map[y][x] == '[') {
        if (map[y - 1][x] == '#') return false;
        if (map[y - 1][x] == '.') left = true;
        if (map[y - 1][x] == '[' || map[y - 1][x] == ']') left = mayIUp(x, y - 1, map);
        if (map[y - 1][x + 1] == '#') return false;
        if (map[y - 1][x + 1] == '.') right = true;
        if (map[y - 1][x + 1] == '[' || map[y - 1][x + 1] == ']') right = mayIUp(x + 1, y - 1, map);
    } else {
        if (map[y - 1][x] == '#') return false;
        if (map[y - 1][x] == '.') right = true;
        if (map[y - 1][x] == '[' || map[y - 1][x] == ']') right = mayIUp(x, y - 1, map);
        if (map[y - 1][x - 1] == '#') return false;
        if (map[y - 1][x - 1] == '.') left = true;
        if (map[y - 1][x - 1] == '[' || map[y - 1][x - 1] == ']') left = mayIUp(x - 1, y - 1, map);
    }

    return left && right;
}

bool mayIDown(const int x, const int y, const array<array<char, SIZE * 2>, SIZE>& map) {
    bool left = false;
    bool right = false;
    if (map[y][x] == '[') {
        if (map[y + 1][x] == '#') return false;
        if (map[y + 1][x] == '.') left = true;
        if (map[y + 1][x] == '[' || map[y + 1][x] == ']') left = mayIDown(x, y + 1, map);
        if (map[y + 1][x + 1] == '#') return false;
        if (map[y + 1][x + 1] == '.') right = true;
        if (map[y + 1][x + 1] == '[' || map[y + 1][x + 1] == ']') right = mayIDown(x + 1, y + 1, map);
    } else {
        if (map[y + 1][x] == '#') return false;
        if (map[y + 1][x] == '.') right = true;
        if (map[y + 1][x] == '[' || map[y + 1][x] == ']') right = mayIDown(x, y + 1, map);
        if (map[y + 1][x - 1] == '#') return false;
        if (map[y + 1][x - 1] == '.') left = true;
        if (map[y + 1][x - 1] == '[' || map[y + 1][x - 1] == ']') left = mayIDown(x - 1, y + 1, map);
    }

    return left && right;
}