#include "stdio.h"

void grow_up(int n);


int main(void) {
    int n;

    scanf("%d", &n);
    grow_up(n);

    return 0;
}


void grow_up(int n) {
    int a = n % 10;
    int b;

    n = n / 10;
    while (n != 0) {
        b = n % 10;
        if (a <= b ) {
            printf("NO");
            return;
        }
        a = b;
        n = n / 10;
    }
    printf("YES");
}