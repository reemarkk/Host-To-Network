#include "endian_union.h"

typedef union _endian_union64 {
    long long int value;
    unsigned char b[8];
} endian_union64;

typedef union _endian_union32{
    long int value;
    unsigned char b[4];
} endian_union32;

long long int hton64_union(long long int c) {
    endian_union64 u;
    u.value = c;
    for (int i = 0; i < 4; i++) {
        unsigned char tmp = u.b[i];
        u.b[i] = u.b[7 - i];
        u.b[7 - i] = tmp;
    }
    return u.value;
}

long long int hton64_ptr(long long int a){
    char *ptr1 = (char *) &a;
    long long int temp;
    char *ptr2 = (char *) &temp;

    for(int i = 0; i < 8; i++){
        *(ptr2 + i) = *(ptr1 + 7 - i);
    }

    return temp;
}

// 32-bit version of host to network byte order conversion using union and pointer methods
long int hton32_union(long int a){
    endian_union32 u;
    u.value = a;

    for(int i = 0; i < 2; i++){
        unsigned char tmp = u.b[i];
        u.b[i] = u.b[3 - i];
        u.b[3 - i] = tmp;
    }

    return u.value;
}

long int hton32_ptr(long int a){
    char* ptr1 = (char*) &a;
    long int temp;

    char* ptr2 = (char*) &temp;

    for(int i = 0; i < 4; i++){
        *(ptr2 + i) = *(ptr1 + 3 - i);
    }
    return temp;
}