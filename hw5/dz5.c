#include <stdio.h>


int main(void) {
    int a, sum = 0;

    scanf("%d", &a);
    while (a != 0) {
        sum += a % 10;
        a = a / 10;
    }

    printf("%d\n", sum);
    return 0;
}
