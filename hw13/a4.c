#include <stdio.h>


int main() {
    unsigned int n, k, num, max = 0;
    scanf("%u %u", &n, &k);
    unsigned int mask = (1 << k) - 1;

    for (int i = 0; i <= 32 - k; i++) {
        num = mask & (n >> i);

        if (num > max) {
            max = num;
        }
    }

    printf("%d", max);

    return 0;
}