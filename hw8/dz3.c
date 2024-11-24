#include "stdio.h"

#define SIZE 10

void min(int size_arr, const int arr[]);
void max(int size_arr, const int arr[]);


int main(void) {
    int arr[SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    max(SIZE, arr);
    min(SIZE, arr);

    return 0;
}


void min(int size_arr, const int arr[]) {
    int min = arr[0];
    int index_min = 0;

    for (int i = 0; i < size_arr; i++) {
        if (min > arr[i]) {
            min = arr[i];
            index_min = i;
        }
    }

    printf("%d %d", index_min + 1, min);
}


void max(int size_arr, const int arr[]) {
    int max = arr[0];
    int index_max = 0;

    for (int i = 0; i < size_arr; i++) {
        if (max < arr[i]) {
            max = arr[i];
            index_max = i;
        }
    }

    printf("%d %d ", index_max + 1, max);
}