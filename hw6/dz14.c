#include "stdio.h"

void func(void);


int main(void) {
    func();

    return 0;
}


void func(void) {
    int a, sum = 0;

    scanf("%d", &a);
    while (a != 0) {
        sum += a % 10;
        a = a / 10;
    }

    sum % 2 ? printf("NO") : printf("YES");
}