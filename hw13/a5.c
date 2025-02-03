#include <stdio.h>


int main(void) {
    int count = 0;
    unsigned int n;

    scanf("%d", &n);

    while (n) {
        if (n & 0x1) {
            count++;
        }
        n >>= 1;
    }
    printf("%d", count);

    return 0;
}