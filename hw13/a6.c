#include <stdio.h>


int main() {
    unsigned int n;
    scanf("%u", &n);

    printf("%u", (((~n) >> 24) << 24) | (n & 0x00ffffff) );

    return 0;
}