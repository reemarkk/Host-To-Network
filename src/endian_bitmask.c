#include "endian_bitmask.h"

long long int LittleToBigEndian(long long int number) {
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