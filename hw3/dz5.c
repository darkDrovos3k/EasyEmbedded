#include "stdio.h"


int main(void) {
    int a, b, c, input;

    scanf("%d", &input);
    a = (input % 1000) / 100;
    b = (input % 100) / 10;
    c = input % 10;

    printf("%d", a*b*c);

    return 0;
}