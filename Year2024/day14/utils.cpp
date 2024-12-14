#include "utils.h"

int positive_mod(const int a, const int b) {
    int result = a % b;
    if (result < 0) {
        result += b;
    }
    return result;
}