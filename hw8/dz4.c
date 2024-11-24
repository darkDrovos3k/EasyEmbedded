#include "stdio.h"
#include "limits.h"

#define SIZE 10

void two_max(int size_arr, const int arr[]);


int main(void) {
    int arr[SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    two_max(SIZE, arr);

    return 0;
}


void two_max(int size_arr, const int arr[]) {
    int max = arr[0];
    int max2 = INT_MIN;
    int index_max = 0;

    for (int i = 0; i < size_arr; i++) {
        if (max < arr[i]) {
            max = arr[i];
            index_max = i;
        }
    }

    for (int k = 0; k < size_arr; k++) {
        if (max2 < arr[k] && k != index_max) {
            max2 = arr[k];
        }
    }

    printf("%d\n", max + max2);
}
