#ifndef UTILS_H
#define UTILS_H

#define SIZE 141
#include <array>

using namespace std;

void bfs(const array<array<char, SIZE>, SIZE>& map, array<array<int, SIZE>, SIZE>& distances, int startX, int startY);

#endif /*UTILS_H*/
