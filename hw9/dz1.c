#include <stdio.h>

#define SIZE 5

void sort_array(int size, int a[]);
void print_array(int size, int a[]);
void scanf_array(int size, int a[]);


int main(void) {
    int a[SIZE] = {0};

    scanf_array(SIZE, a);
    sort_array(SIZE, a);

    return 0;
}

void sort_array(int size, int a[]) {
    for (int i = 0; i < size; i++) {
        for (int k = i; k < size; k++) {
            if (a[i] > a[k]) {
                int tmp = a[i];
                a[i] = a[k];
                a[k] = tmp;
            }
        }
    }

    print_array(SIZE, a);
}

void print_array(int size, int a[]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
}

void scanf_array(int size, int a[]) {
    for (int i = 0; i < size; i++) {
        int k;
        scanf("%d", &k);
        a[i] = k;
    }
}
