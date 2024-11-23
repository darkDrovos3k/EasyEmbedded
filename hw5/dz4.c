#include "stdio.h"


int main(void) {
    int a, b, c;

    scanf("%d", &a);
    b = a / 1000;
    c = (a % 1000) / 100;
    (!b && c) ? printf("YES") : printf("NO");

    return 0;
}