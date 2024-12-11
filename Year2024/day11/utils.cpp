#include "utils.h"
#include <cmath>

unsigned GetNumberOfDigits(unsigned long i) {
    return i > 0 ? static_cast<int>(log10(static_cast<double>(i))) + 1 : 1;
}
