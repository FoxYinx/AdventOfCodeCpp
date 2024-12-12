#include <fstream>
#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <ranges>

#define SIZE 140

using namespace std;

void bfsSide(int i, int j, vector<array<int, 2>>& fields, const array<array<char, SIZE>, SIZE>& farm, array<array<bool, SIZE>, SIZE>& marquage);

int year2024_day12_puzzle2() {
    ifstream f("ressources/Year2024/day12.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    array<array<char, SIZE>, SIZE> farm = {};
    int line = 0;
    while (getline(f, s)) {
        for (int i = 0; i < SIZE; i++) {
            farm[line][i] = s.at(i);
        }
        line++;
    }

    vector<array<int, 2>> fields;
    array<array<bool, SIZE>, SIZE> marquage = {};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!marquage[i][j]) bfsSide(i, j, fields, farm, marquage);
        }
    }

    int price = 0;
    for (const auto& value : fields) {
        price += value[0] * value[1];
    }

    cout << price << endl;
    return 0;
}

void bfsSide(const int i, const int j, vector<array<int, 2>>& fields, const array<array<char, SIZE>, SIZE>& farm, array<array<bool, SIZE>, SIZE>& marquage) {
    queue<array<int, 2>> file;
    file.push({i, j});
    marquage[i][j] = true;

    fields.push_back({1, 0});

    while (!file.empty()) {
        array<int, 2> node = file.front();
        const int y = node[0];
        const int x = node[1];
        file.pop();

        int neighbor = 0;

        if (y - 1 >= 0) {
            if (farm[y - 1][x] == farm[y][x]) {
                neighbor++;
                if (!marquage[y - 1][x]) {
                    fields[fields.size() - 1][0]++;
                    file.push({y - 1, x});
                    marquage[y - 1][x] = true;
                }
            }
        }
        if (y + 1 < SIZE) {
            if (farm[y + 1][x] == farm[y][x]) {
                neighbor++;
                if (!marquage[y + 1][x]) {
                    fields[fields.size() - 1][0]++;
                    file.push({y + 1, x});
                    marquage[y + 1][x] = true;
                }
            }
        }
        if (x - 1 >= 0) {
            if (farm[y][x - 1] == farm[y][x]) {
                neighbor++;
                if (!marquage[y][x - 1]) {
                    fields[fields.size() - 1][0]++;
                    file.push({y, x - 1});
                    marquage[y][x - 1] = true;
                }
            }
        }
        if (x + 1 < SIZE) {
            if (farm[y][x + 1] == farm[y][x]) {
                neighbor++;
                if (!marquage[y][x + 1]) {
                    fields[fields.size() - 1][0]++;
                    file.push({y, x + 1});
                    marquage[y][x + 1] = true;
                }
            }
        }

        switch (neighbor) {
            case 0: fields[fields.size() - 1][1] = 4; break;
            case 1: {
                fields[fields.size() - 1][1] += 2;
                break;
            }
            case 2: {
                if (x > 0 && x < SIZE - 1 && farm[y][x] == farm[y][x + 1] && farm[y][x] == farm[y][x - 1]) {
                    break;
                }
                if (y > 0 && y < SIZE - 1 && farm[y][x] == farm[y + 1][x] && farm[y][x] == farm[y - 1][x]) {
                    break;
                }
                if (y - 1 >= 0 && x - 1 >= 0 && farm[y][x] == farm[y - 1][x] && farm[y][x] == farm[y][x - 1]) {
                    if (farm[y][x] == farm[y - 1][x - 1]) fields[fields.size() - 1][1] += 1;
                    else fields[fields.size() - 1][1] += 2;
                } else if (y - 1 >= 0 && x + 1 < SIZE && farm[y][x] == farm[y - 1][x] && farm[y][x] == farm[y][x + 1]) {
                    if (farm[y][x] == farm[y - 1][x + 1]) fields[fields.size() - 1][1] += 1;
                    else fields[fields.size() - 1][1] += 2;
                } else if (y + 1 < SIZE && x - 1 >= 0 && farm[y][x] == farm[y + 1][x] && farm[y][x] == farm[y][x - 1]) {
                    if (farm[y][x] == farm[y + 1][x - 1]) fields[fields.size() - 1][1] += 1;
                    else fields[fields.size() - 1][1] += 2;
                } else if (y + 1 < SIZE && x + 1 < SIZE && farm[y][x] == farm[y + 1][x] && farm[y][x] == farm[y][x + 1]) {
                    if (farm[y][x] == farm[y + 1][x + 1]) fields[fields.size() - 1][1] += 1;
                    else fields[fields.size() - 1][1] += 2;
                }
                break;
            }
            case 3: {
                if (y == 0 || farm[y][x] != farm[y - 1][x]) {
                    fields[fields.size() - 1][1] += 2;
                    if (farm[y][x] == farm[y + 1][x + 1]) fields[fields.size() - 1][1]--;
                    if (farm[y][x] == farm[y + 1][x - 1]) fields[fields.size() - 1][1]--;
                } else if (x == 0 || farm[y][x] != farm[y][x - 1]) {
                    fields[fields.size() - 1][1] += 2;
                    if (farm[y][x] == farm[y + 1][x + 1]) fields[fields.size() - 1][1]--;
                    if (farm[y][x] == farm[y - 1][x + 1]) fields[fields.size() - 1][1]--;
                } else if (y == SIZE - 1 || farm[y][x] != farm[y + 1][x]) {
                    fields[fields.size() - 1][1] += 2;
                    if (farm[y][x] == farm[y - 1][x + 1]) fields[fields.size() - 1][1]--;
                    if (farm[y][x] == farm[y - 1][x - 1]) fields[fields.size() - 1][1]--;
                } else if (x == SIZE - 1 || farm[y][x] != farm[y][x + 1]) {
                    fields[fields.size() - 1][1] += 2;
                    if (farm[y][x] == farm[y + 1][x - 1]) fields[fields.size() - 1][1]--;
                    if (farm[y][x] == farm[y - 1][x - 1]) fields[fields.size() - 1][1]--;
                }
                break;
            }
            case 4: {
                if (farm[y + 1][x + 1] != farm[y][x]) fields[fields.size() - 1][1]++;
                if (farm[y + 1][x - 1] != farm[y][x]) fields[fields.size() - 1][1]++;
                if (farm[y - 1][x + 1] != farm[y][x]) fields[fields.size() - 1][1]++;
                if (farm[y - 1][x - 1] != farm[y][x]) fields[fields.size() - 1][1]++;
                break;
            }
            default: cerr << neighbor << " voisins détectés (IMPOSSIBLE)";
        }
    }
}

