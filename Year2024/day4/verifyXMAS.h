#ifndef ADVENTOFCODE_VERIFYXMAS_H
#define ADVENTOFCODE_VERIFYXMAS_H

#include <vector>

using namespace std;

bool horizontal(int i, int j, vector<vector<char>> &tableau);

bool vertical(int i, int j, vector<vector<char>> &tableau);

bool diag_right(int i, int j, vector<vector<char>> &tableau);

bool diag_left(int i, int j, vector<vector<char>> &tableau);

bool crossmas(int i, int j, vector<vector<char>> &tableau);

bool cross_right(int i, int j, vector<vector<char>> &tableau);

bool cross_left(int i, int j, vector<vector<char>> &tableau);

#endif