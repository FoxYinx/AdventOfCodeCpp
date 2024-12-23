#include "utils.h"

bool contains(const vector<string>& vec, const string &value) {
    return ranges::find(vec, value) != vec.end();
}
