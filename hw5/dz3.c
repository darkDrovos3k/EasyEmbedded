#include "stdio.h"


int main(void) {
    int a, b, c;
    long long int sum = 0;

    scanf("%d%d", &a, &b);

    for (; a <= b; ) {
        c = a * a;
        sum += c;
        a++;
    }

    printf("%lld", sum);

    return 0;
}