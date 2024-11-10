#include "stdio.h"


int main(void) {
    int mas[5] = {0};
    int max = 0;

    for (int i = 0; i <5; i++) {
        scanf("%d", &mas[i]);
    }

    int min = mas[0];
    for (int i = 0; i <5; i++) {
        if (max < mas[i]) {
            max = mas[i];
        }

        if (min > mas[i]) {
            min = mas[i];
        }
    }

    printf("%d", max + min);

    return 0;
}