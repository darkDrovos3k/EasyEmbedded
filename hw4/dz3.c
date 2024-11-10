#include "stdio.h"


int main(void) {
    int a, b, c, input;

    scanf("%d", &input);
    a = (input % 1000) / 100;
    b = (input % 100) / 10;
    c = input % 10;

    if (a > b && a > c) {
        printf("%d", a);
    }
    else if (b > a && b > c) {
        printf("%d", b);
    }
    else {
        printf("%d", c);
    }

    return 0;
}