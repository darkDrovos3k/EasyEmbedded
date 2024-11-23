#include "stdio.h"

int sum_number(int num);


int main(void) {
    int n;

    scanf("%d", &n);
    printf("%d", sum_number(n));

    return 0;
}


int sum_number(int num) {
    int sum = 0;

    for (int i = 0; i <= num; i++) {
        sum += i;
    }

    return sum;
}