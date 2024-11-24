#include "stdio.h"

#define SIZE 5

float sum_array(void);


int main(void) {
    printf("%.3f", sum_array());

    return 0;
}


float sum_array(void) {
    float sum = 0;
    int mas[SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &mas[i]);
    }

    for (int i = 0; i < SIZE; i++) {
        sum += (float) mas[i];
    }

    return sum / SIZE;
}