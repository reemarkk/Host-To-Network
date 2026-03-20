#include <stdio.h>
#include "endian_union.h"
#include "endian_bitmask.h"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// ---------- Helpers ----------
void printHex64(long long int number) {
    printf("0x%016llX", number);
}

void printHex32(unsigned int number) {
    printf("0x%08X", number);
}


int main() {

    // ================= 64-bit tests =================
    long long int test64[] = {
        0x0102030405060708,
        0x123456789ABCDEF0,
        0x0000000000000001,
        0xFFFFFFFFFFFFFFFF,
        0x0A0B0C0D0E0F1011
    };
    int n64 = sizeof(test64)/sizeof(test64[0]);

    printf(YELLOW "Running 64-bit endian conversion tests...\n\n" RESET);

    for (int i = 0; i < n64; i++) {
        long long int num = test64[i];
        long long int u = hton64_union(num);         // union method
        long long int b = hton64_bitmask(num); // bitmask method
        long long int p = hton64_bitmask(num);         // pointer method

        printf(YELLOW "Test %d (64-bit)\n" RESET, i + 1);
        printf("Original         : "); printHex64(num); printf("\n");
        printf("Union Method     : "); printHex64(u); printf("\n");
        printf("Bitmask Method   : "); printHex64(b); printf("\n");
        printf("Pointer Method   : "); printHex64(p); printf("\n");

        // Compare results
        int passUB = (u == b);
        int passUP = (u == p);
        int passBP = (b == p);

        printf("Union vs Bitmask : %s%s%s\n", passUB ? GREEN : RED, passUB ? "[PASS]" : "[FAIL]", RESET);
        printf("Union vs Pointer : %s%s%s\n", passUP ? GREEN : RED, passUP ? "[PASS]" : "[FAIL]", RESET);
        printf("Bitmask vs Pointer : %s%s%s\n", passBP ? GREEN : RED, passBP ? "[PASS]" : "[FAIL]", RESET);

        printf("\n");
    }

    // ================= 32-bit tests =================
    unsigned int test32[] = {
        0x01020304,
        0x12345678,
        0x00000001,
        0xFFFFFFFF,
        0x0A0B0C0D
    };
    int n32 = sizeof(test32)/sizeof(test32[0]);

    printf(YELLOW "Running 32-bit endian conversion tests...\n\n" RESET);

    for (int i = 0; i < n32; i++) {
        unsigned int num = test32[i];
        unsigned int u = hton32_union(num);
        unsigned int b = hton32_bitmask(num);
        unsigned int p = hton32_ptr(num);

        printf(YELLOW "Test %d (32-bit)\n" RESET, i + 1);
        printf("Original         : "); printHex32(num); printf("\n");
        printf("Union Method     : "); printHex32(u); printf("\n");
        printf("Bitmask Method   : "); printHex32(b); printf("\n");
        printf("Pointer Method   : "); printHex32(p); printf("\n");

        // Compare results
        int passUB = (u == b);
        int passUP = (u == p);
        int passBP = (b == p);

        printf("Union vs Bitmask : %s%s%s\n", passUB ? GREEN : RED, passUB ? "[PASS]" : "[FAIL]", RESET);
        printf("Union vs Pointer : %s%s%s\n", passUP ? GREEN : RED, passUP ? "[PASS]" : "[FAIL]", RESET);
        printf("Bitmask vs Pointer : %s%s%s\n", passBP ? GREEN : RED, passBP ? "[PASS]" : "[FAIL]", RESET);

        printf("\n");
    }

    printf(YELLOW "All tests completed.\n" RESET);
    return 0;
}