#include <stdio.h>


int main() {
    unsigned int n, k, res, res1, res2;
    scanf("%u %u", &n, &k);

    res1 = n >> k;
    res2 = n << (32 - k);
    res = res1 | res2;
    printf("%u\n", res);

    return 0;
}
