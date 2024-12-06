#include "gardMap.h"


GardMap::GardMap() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            this->map[i][j] = '.';
            this->hasBeenThere[i][j] = false;
        }
    }
    this->direction = UP;
    this->gardX = 0;
    this->gardY = 0;
}


bool GardMap::willBeOutside() const {
    switch (direction) {
        case UP:
            return gardY == 0;
        case RIGHT:
            return gardX == size - 1;
        case DOWN:
            return gardY == size - 1;
        case LEFT:
            return gardX == 0;
    }
}

bool GardMap::move() {
    if (willBeOutside()) return false;
    switch (direction) {
        case UP:
            if (map[gardY-1][gardX] == '#') {
                direction = RIGHT;
            } else {
                gardY--;
                hasBeenThere[gardY][gardX] = true;
            }
            return true;
        case RIGHT:
            if (map[gardY][gardX+1] == '#') {
                direction = DOWN;
            } else {
                gardX++;
                hasBeenThere[gardY][gardX] = true;
            }
            return true;
        case DOWN:
            if (map[gardY+1][gardX] == '#') {
                direction = LEFT;
            } else {
                gardY++;
                hasBeenThere[gardY][gardX] = true;
            }
            return true;
        case LEFT:
            if (map[gardY][gardX-1] == '#') {
                direction = UP;
            } else {
                gardX--;
                hasBeenThere[gardY][gardX] = true;
            }
            return true;
    }
}

int GardMap::allCases() {
    int nb = 0;
    for (auto & i : hasBeenThere) {
        for (bool j : i) {
            if (j) nb++;
        }
    }
    return nb;
}

void GardMap::reset(int x, int y) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasBeenThere[i][j] = false;
        }
    }
    gardX = x;
    gardY = y;
    direction = UP;
}

