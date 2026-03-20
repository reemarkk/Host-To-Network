#include <stdio.h>
#include "endian_union.h"
#include "endian_bitmask.h"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

void printHex(long long int number) {
    printf("0x%016llX", number);
}

int main() {
    long long int testNumbers[] = {
        0x0102030405060708,
        0x123456789ABCDEF0,
        0x0000000000000001,
        0xFFFFFFFFFFFFFFFF,
        0x0A0B0C0D0E0F1011
    };

    int nTests = sizeof(testNumbers) / sizeof(testNumbers[0]);

    printf(YELLOW "Running 64-bit endian conversion tests...\n\n" RESET);

    for (int i = 0; i < nTests; i++) {
        long long int num = testNumbers[i];
        printf("Test %d:\n", i + 1);
        printf("Original         : "); printHex(num); printf("\n");

        long long int resUnion = Hton64(num);
        long long int resBitmask = LittleToBigEndian(num);

        printf("Union Method     : "); printHex(resUnion);
        printf("  "); 
        if (resUnion == resBitmask) printf(GREEN "[PASS]\n" RESET);
        else printf(RED "[FAIL]\n" RESET);

        printf("Bitmask Method   : "); printHex(resBitmask);
        printf("  "); 
        if (resBitmask == resUnion) printf(GREEN "[PASS]\n" RESET);
        else printf(RED "[FAIL]\n" RESET);

        printf("\n");
    }

    printf(YELLOW "All tests completed.\n" RESET);
    return 0;
}