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
        printf(YELLOW "Test %d\n" RESET, i + 1);
        printf("Original         : "); printHex(num); printf("\n");

        long long int resUnion = hton64(num);
        long long int resBitmask = LittleToBigEndian(num);
        long long int resPointer = htonll(num);

        // Print results
        printf("Union Method     : "); printHex(resUnion); printf("\n");
        printf("Bitmask Method   : "); printHex(resBitmask); printf("\n");
        printf("Pointer Method   : "); printHex(resPointer); printf("\n");

        // Check consistency
        int passUnionBitmask = (resUnion == resBitmask);
        int passUnionPointer = (resUnion == resPointer);
        int passBitmaskPointer = (resBitmask == resPointer);

        printf("Union vs Bitmask : %s%s%s\n", passUnionBitmask ? GREEN : RED, passUnionBitmask ? "[PASS]" : "[FAIL]", RESET);
        printf("Union vs Pointer : %s%s%s\n", passUnionPointer ? GREEN : RED, passUnionPointer ? "[PASS]" : "[FAIL]", RESET);
        printf("Bitmask vs Pointer : %s%s%s\n", passBitmaskPointer ? GREEN : RED, passBitmaskPointer ? "[PASS]" : "[FAIL]", RESET);

        printf("\n");
    }

    printf(YELLOW "All tests completed.\n" RESET);
    return 0;
}