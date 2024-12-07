#include <stdio.h>
#include <string.h>

#define SIZE_STR 1000
#define SIZE 10

void print_pos_integer(void);


int main(void) {
    print_pos_integer();

    return 0;
}

void print_pos_integer(void){
    int arr[SIZE] = {0};
    char str[SIZE_STR];
    int d;

    scanf("%s", str);
    int len_str = strlen(str);

    for (int i = 0; i < len_str; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            d = str[i] - '0';
            arr[d]++;
        }
    }

    for (int k = 0; k < SIZE; k++) {
        if(arr[k])
            printf("%d %d\n", k, arr[k]);
    }
}
