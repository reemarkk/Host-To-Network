#include "endian_bitmask.h"

// 64-bit version of host to network byte order conversion using bitmask method
long long int hton64_bitmask(long long int number) {
    return 
        ((number & 0x00000000000000FFLL) << 56) |
        ((number & 0xFF00000000000000LL) >> 56) |
        ((number & 0x000000000000FF00LL) << 40) |
        ((number & 0x00FF000000000000LL) >> 40) |
        ((number & 0x0000000000FF0000LL) << 24) |
        ((number & 0x0000FF0000000000LL) >> 24) |
        ((number & 0x00000000FF000000LL) << 8)  |
        ((number & 0x000000FF00000000LL) >> 8);
}

// 32-bit version of host to network byte order conversion using bitmask method
long int hton32_bitmask(long int number) {
    return 
        ((number & 0x000000FF) << 24) |
        ((number & 0xFF000000) >> 24) |
        ((number & 0x0000FF00) << 8)  |
        ((number & 0x00FF0000) >> 8);
}