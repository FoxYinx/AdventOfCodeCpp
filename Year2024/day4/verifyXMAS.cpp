#include <vector>
#include "verifyXMAS.h"

#define SIZE 140

using namespace std;

bool horizontal(int i, int j, vector<vector<char>>& tableau) {
    bool h = false;
    if (SIZE - j < 4) return h;
    if (tableau[i][j] == 'X' && tableau[i][j+1] == 'M' && tableau[i][j+2] == 'A' && tableau[i][j+3] == 'S') h = true;
    if (tableau[i][j] == 'S' && tableau[i][j+1] == 'A' && tableau[i][j+2] == 'M' && tableau[i][j+3] == 'X') h = true;
    return h;
}

bool vertical(int i, int j, vector<vector<char>>& tableau) {
    bool v = false;
    if (SIZE - i < 4) return v;
    if (tableau[i][j] == 'X' && tableau[i+1][j] == 'M' && tableau[i+2][j] == 'A' && tableau[i+3][j] == 'S') v = true;
    if (tableau[i][j] == 'S' && tableau[i+1][j] == 'A' && tableau[i+2][j] == 'M' && tableau[i+3][j] == 'X') v = true;
    return v;
}

bool diag_right(int i, int j, vector<vector<char>>& tableau) {
    bool dr = false;
    if (SIZE - i < 4 || SIZE - j < 4) return dr;
    if (tableau[i][j] == 'X' && tableau[i+1][j+1] == 'M' && tableau[i+2][j+2] == 'A' && tableau[i+3][j+3] == 'S') dr = true;
    if (tableau[i][j] == 'S' && tableau[i+1][j+1] == 'A' && tableau[i+2][j+2] == 'M' && tableau[i+3][j+3] == 'X') dr = true;
    return dr;
}

bool diag_left(int i, int j, vector<vector<char>>& tableau) {
    bool dl = false;
    if (SIZE - i < 4 || j < 3) return dl;
    if (tableau[i][j] == 'X' && tableau[i+1][j-1] == 'M' && tableau[i+2][j-2] == 'A' && tableau[i+3][j-3] == 'S') dl = true;
    if (tableau[i][j] == 'S' && tableau[i+1][j-1] == 'A' && tableau[i+2][j-2] == 'M' && tableau[i+3][j-3] == 'X') dl = true;
    return dl;
}

bool crossmas(int i, int j, vector<vector<char>>& tableau) {
    if (SIZE - i < 3 || SIZE - j < 3) return false;
    if (cross_right(i, j, tableau) && cross_left(i, j, tableau)) return true;
    return false;
}

bool cross_right(int i, int j, vector<vector<char>>& tableau) {
    bool right = false;
    if (SIZE - i < 3 || SIZE - j < 3) return right;
    if (tableau[i][j] == 'M' && tableau[i+1][j+1] == 'A' && tableau[i+2][j+2] == 'S') right = true;
    if (tableau[i][j] == 'S' && tableau[i+1][j+1] == 'A' && tableau[i+2][j+2] == 'M') right = true;
    return right;
}

bool cross_left(int i, int j, vector<vector<char>>& tableau) {
    bool left = false;
    if (SIZE - i < 3 || SIZE - j < 3) return left;
    if (tableau[i][j+2] == 'M' && tableau[i+1][j+1] == 'A' && tableau[i+2][j] == 'S') left = true;
    if (tableau[i][j+2] == 'S' && tableau[i+1][j+1] == 'A' && tableau[i+2][j] == 'M') left = true;
    return left;
}