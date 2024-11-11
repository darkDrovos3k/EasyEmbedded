#include "stdio.h"
#include "stdlib.h"


int main(void) {
    int a;
    int b = 1;
    scanf("%d", &a);

    if (a < 0 || a > 100) {
        exit(1);
    }

    for (int i = 1; i <= a; i++) {
        printf("%d %d %d\n", b, b * b, b * b * b);
        b++;
    }

    return 0;
}