#include "stdio.h"

int power(int n, int p);


int main(void) {
    int n, p;

    scanf("%d%d", &n, &p);
    printf("%d", power(n, p));

    return 0;
}


int power(int n, int p) {
    int num = n;

    if (p > 0) {
        for (int i = 1; i < p; i++) {
            num *= n;
        }
    }
    else if (!p) {
        num = 1;
    }

    return num;
}