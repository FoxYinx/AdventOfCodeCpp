#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
#include "utils.h"

#define SECONDS 100
#define WIDTH 101
#define HEIGHT 103

using namespace std;

struct robot {
    int x;
    int y;
    int vx;
    int vy;
};

int year2024_day14_puzzle1() {
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

    for (int i = 0; i < SECONDS; i++) {
        for (auto& [x, y, vx, vy] : robots) {
            x = positive_mod(x + vx, WIDTH);
            y = positive_mod(y + vy, HEIGHT);
        }
    }

    int firstQuadrant = 0;
    int secondQuadrant = 0;
    int thirdQuadrant = 0;
    int fourthQuadrant = 0;

    for (const robot rb: robots) {
        if (rb.x < (WIDTH - 1) / 2) {
            if (rb.y < (HEIGHT - 1) / 2) firstQuadrant++;
            if (rb.y > (HEIGHT - 1) / 2) thirdQuadrant++;
        } else if (rb.x > (WIDTH - 1) / 2) {
            if (rb.y < (HEIGHT - 1) / 2) secondQuadrant++;
            if (rb.y > (HEIGHT - 1) / 2) fourthQuadrant++;
        }
    }

    cout << firstQuadrant * secondQuadrant * thirdQuadrant * fourthQuadrant << endl;
    return 0;
}