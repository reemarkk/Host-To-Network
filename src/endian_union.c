#include "endian_union.h"

typedef union byte64 {
    long long int value;
    unsigned char b[8];
} byte64;

long long int hton64(long long int c) {
    byte64 u;
    u.value = c;
    for (int i = 0; i < 4; i++) {
        unsigned char tmp = u.b[i];
        u.b[i] = u.b[7 - i];
        u.b[7 - i] = tmp;
    }
    return u.value;
}

long long int htonll(long long int a){
    char *ptr1 = (char *) &a;
    long long int temp;
    char *ptr2 = (char *) &temp;

    for(int i = 0; i < 8; i++){
        *(ptr2 + i) = *(ptr1 + 7 - i);
    }

    return temp;
}