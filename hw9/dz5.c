#include <stdio.h>

#define SIZE 84

int find_max_array(int size, int a[]);
void scanf_array(int size, int a[]);


int main(void) {
    int a[SIZE];

    scanf_array(SIZE, a);
    printf("%d\n", find_max_array(SIZE, a));

    return 0;
}

int find_max_array(int size, int a[]) {
    int max = a[0];

    for (int i = 0; i < size; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }

    return max;
}

void scanf_array(int size, int a[]) {
    for (int i = 0; i < size; i++) {
        int k;
        scanf("%d", &k);
        a[i] = k;
    }
}