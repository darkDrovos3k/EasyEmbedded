#include "stdio.h"

#define SIZE 10

int sum(int size_arr, const int arr[]);


int main(void) {
    int arr[SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d", sum(SIZE, arr));
    return 0;
}


int sum(int size_arr, const int arr[]) {
    int sum = 0;

    for (int i = 0; i < size_arr; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }

    return sum;
}