#include "stdio.h"


int main(void) {
    int a, b;

    scanf("%d%d", &a, &b);

    for (; a <= b; ) {
        printf("%d ", a * a);
        a++;
    }
}
