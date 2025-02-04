#include <stdio.h>
#include <stdint.h>

#define SIZE 32

struct pack_array {
    uint32_t array; // поле для хранения упакованного массива из 0 и 1
    uint32_t count0: 8; // счетчик нулей в array
    uint32_t count1: 8; // счетчик единиц в array
};

void array2struct(int [], struct pack_array *);
void scanf_array(int size, int arr[]);


int main(void) {
    int arr[SIZE];
    struct pack_array res;

    scanf_array(SIZE, arr);
    array2struct(arr, &res);

    return 0;
}

void array2struct(int arr[], struct pack_array *res) {
    res->array = 0;
    res->count0 = 0;
    res->count1 = 0;

    for (int i = 0; i < 32; i++) {
        if (arr[i] == 1) {
            res->array |= 1 << (31 - i);
            res->count1++;
        } else if (arr[i] == 0) {
            res->count0++;
        }
    }

    printf("%u %d %d\n", res->array, res->count0, res->count1);
}

void scanf_array(int size, int arr[]) {
    for (int i = 0; i < size; i++) {
        int k;
        scanf("%d", &k);
        arr[i] = k;
    }
}