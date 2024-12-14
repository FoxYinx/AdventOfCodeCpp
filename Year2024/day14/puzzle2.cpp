#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
#include <array>
#include "utils.h"

#define WIDTH 101
#define HEIGHT 103

using namespace std;

struct robot {
    int x;
    int y;
    int vx;
    int vy;
};

int year2024_day14_puzzle2() {
    ifstream f("ressources/Year2024/day14.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    const regex regexp(R"(p=(-?\d+),(-?\d+) v=(-?\d+),(-?\d+))");
    smatch sm;
    vector<robot> robots;
    while (getline(f, s)) {
        while (regex_search(s, sm, regexp)) {
            robots.push_back(robot{stoi(sm[1]), stoi(sm[2]), stoi(sm[3]), stoi(sm[4])});
            s = sm.suffix();
        }
    }

    int iterations = 0;
    string escape;
    do {
        iterations++;
        for (auto& [x, y, vx, vy] : robots) {
            x = positive_mod(x + vx, WIDTH);
            y = positive_mod(y + vy, HEIGHT);
        }
        cout << "Iteration nb " << iterations << ":" << endl;

        array<array<char, WIDTH>, HEIGHT> area = {};
        for (auto& row : area) {
            row.fill('.');
        }

        for (auto rb : robots) {
            area[rb.y][rb.x] = '#';
        }
        for (auto a : area) {
            for (auto b : a) {
                cout << b << " ";
            }
            cout << endl;
        }
        getline(cin, escape);
    } while (escape.empty());

    return 0;
}