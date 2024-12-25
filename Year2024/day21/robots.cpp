#include "robots.h"

#include <algorithm>

using namespace std;

template<size_t N>
vector<vector<uint8_t>> findShortestPaths(const array<array<uint8_t, 3>, N>& keypad, uint8_t from, uint8_t to) {
    //todo: write this function
    vector<vector<uint8_t>> paths;
    return paths;
}

template<size_t N>
uint64_t findShortestSequence(const vector<uint8_t> &s, const uint8_t depth, const bool highest) {
    uint8_t cursor = 'A';
    uint64_t result = 0;
    for (auto& c : s) {
        const void* keypad = highest ? static_cast<const void*>(&numeric) : static_cast<const void*>(&directional);
        vector<vector<uint8_t>> paths = findShortestPaths<N>(*static_cast<const array<array<uint8_t, 3>, N>*>(keypad), cursor, c);

        if (depth == 0) {
            result += paths[0].size();
        } else {
            vector<uint64_t> path_lengths(paths.size());
            transform(paths.begin(), paths.end(), path_lengths.begin(),
                [depth](const vector<uint8_t>& p) {
                    return findShortestSequence<2>(p, depth - 1, false);
                });
            result += *ranges::min_element(path_lengths);
        }

        cursor = c;
    }

    return result;
}

template vector<vector<uint8_t>> findShortestPaths<4>(const array<array<uint8_t, 3>, 4>& keypad, uint8_t from, uint8_t to);
template vector<vector<uint8_t>> findShortestPaths<2>(const array<array<uint8_t, 3>, 2>& keypad, uint8_t from, uint8_t to);
template uint64_t findShortestSequence<4>(const vector<uint8_t>& s, uint8_t depth, bool highest);
template uint64_t findShortestSequence<2>(const vector<uint8_t>& s, uint8_t depth, bool highest);