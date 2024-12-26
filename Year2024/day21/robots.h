#ifndef ROBOTS_H
#define ROBOTS_H
#include <array>
#include <cstdint>
#include <map>
#include <utility>
#include <vector>

using namespace std;

struct MapKey {
    vector<uint8_t> s;
    uint8_t depth;

    MapKey(vector<uint8_t> s, const uint8_t depth)
        : s(std::move(s)), depth(depth) {}

    bool operator<(const MapKey& other) const {
        return tie(s, depth) < tie(other.s, other.depth);
    }
};

constexpr array<pair<int32_t, int32_t>, 4> directions = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};

constexpr array<array<uint8_t, 3>, 4> numeric = {{{'7', '8', '9'},
                                                     {'4', '5', '6'},
                                                     {'1', '2', '3'},
                                                     {' ', '0', 'A'}}};

constexpr array<array<uint8_t, 3>, 2> directional = {{{' ', '^', 'A'},
                                                         {'<', 'v', '>'}}};

template<size_t N>
vector<vector<uint8_t>> findShortestPaths(const array<array<uint8_t, 3>, N>& keypad, uint8_t from, uint8_t to);

template<size_t N>
uint64_t findShortestSequence(const vector<uint8_t> &s, uint8_t depth, bool highest, map<MapKey, uint64_t>& cache);
#endif /*ROBOTS_H*/
