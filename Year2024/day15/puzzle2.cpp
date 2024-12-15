#include <fstream>
#include <iostream>
#include <array>

#define SIZE 10

using namespace std;

int year2024_day15_puzzle2() {
    ifstream f("ressources/Year2024/test2.txt");

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
                        rx = i;
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
                }
            }
        }
        line++;
    }

    for (auto a : map) {
        for (const auto b : a ) {
            cout << b;
        }
        cout << endl;
    }

    return 0;
}