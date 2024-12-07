#include <stdio.h>

#define SIZE 101

int is_two_same(int size, int a[]);
void scanf_array(int size, int a[]);


int main(void) {
    int a[SIZE] = {0};

    scanf_array(SIZE, a);
    is_two_same(SIZE, a);

    return 0;
}

int is_two_same(int size, int a[]) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            if (a[i] == a[k]) {
                count++;
            }
        }
        if (count >= 2) {
            return 1;
        }
        count = 0;
    }
    return 0;
}

void scanf_array(int size, int a[]) {
    for (int i = 0; i < size; i++) {
        int k;
        scanf("%d", &k);
        a[i] = k;
    }
}