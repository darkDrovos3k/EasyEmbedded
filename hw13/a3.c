#include <stdio.h>


int main() {
    unsigned int n, k;
    scanf("%u %u", &n, &k);

    printf("%u\n", n & ((1 << k) -1));
    return 0;
}