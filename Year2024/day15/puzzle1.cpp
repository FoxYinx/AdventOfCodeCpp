#include <fstream>
#include <iostream>
#include <array>

#define SIZE 50

using namespace std;

int year2024_day15_puzzle1() {
    ifstream f("ressources/Year2024/day15.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    array<array<char, SIZE>, SIZE> map = {};
    int line = 0;
    int rx = 0;
    int ry = 0;
    while (getline(f, s)) {
        if (line < SIZE) {
            for (int i = 0; i < SIZE; i++) {
                map[line][i] = s[i];
                if (s[i] == '@') {
                    rx = i;
                    ry = line;
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
                            case 'O': {
                                int nb = 1;
                                bool flag = false;
                                for (int j = ry - 1; j >= 0; j--) {
                                    switch (map[j - 1][rx]) {
                                        case 'O': {
                                            nb++;
                                            break;
                                        }
                                        case '.': {
                                            for (int l = 0; l < nb + 1; l++) {
                                                map[j + l - 1][rx] = map[j + l][rx];
                                                map[j + l][rx] = '.';
                                            }
                                            ry--;
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
                    case '>': {
                        switch (map[ry][rx + 1]) {
                            case '.': {
                                map[ry][rx + 1] = '@';
                                map[ry][rx] = '.';
                                rx++;
                                break;
                            }
                            case 'O': {
                                int nb = 1;
                                bool flag = false;
                                for (int j = rx + 1; j <= SIZE; j++) {
                                    switch (map[ry][j + 1]) {
                                        case 'O': {
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
                            case 'O': {
                                int nb = 1;
                                bool flag = false;
                                for (int j = ry + 1; j <= SIZE; j++) {
                                    switch (map[j + 1][rx]) {
                                        case 'O': {
                                            nb++;
                                            break;
                                        }
                                        case '.': {
                                            for (int l = 0; l < nb + 1; l++) {
                                                map[j - l + 1][rx] = map[j - l][rx];
                                                map[j - l][rx] = '.';
                                            }
                                            ry++;
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
                    case '<': {
                        switch (map[ry][rx - 1]) {
                            case '.': {
                                map[ry][rx - 1] = '@';
                                map[ry][rx] = '.';
                                rx--;
                                break;
                            }
                            case 'O': {
                                int nb = 1;
                                bool flag = false;
                                for (int j = rx - 1; j >= 0; j--) {
                                    switch (map[ry][j - 1]) {
                                        case 'O': {
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
                    default: cerr << "Direction impossible:" << i << endl;
                }
            }
        }
        line++;
    }

    int score = 0;
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            if (map[y][x] == 'O') score += 100 * y + x;
        }
    }

    cout << score << endl;
    return 0;
}