#include "utils.h"

uint64_t deriveSecret(unsigned long long secret) {
    secret = (secret ^ secret << 6) & 0xFFFFFF;
    secret = (secret ^ secret >> 5) & 0xFFFFFF;
    secret = (secret ^ secret << 11) & 0xFFFFFF;
    return secret;
}
