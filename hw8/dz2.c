#include "stdio.h"

#define SIZE 5

int min(int size_arr, const int arr[]);


int main(void) {
    int arr[SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d", min(SIZE, arr));
    return 0;
}


int min(int size_arr, const int arr[]) {
    int min = arr[0];

    for (int i = 0; i < size_arr; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }

    return min;
}
