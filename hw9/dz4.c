#include <stdio.h>
#include <string.h>

#define SIZE_S 1000

void print_digit(char s[]);


int main(void) {
    char s[SIZE_S];

    scanf("%[^\n]", s);
    print_digit(s);

    return 0;
}

void print_digit(char s[]){
    int d;
    int arr[10] = {0};

    int len_s = strlen(s);
    for (int i = 0; i < len_s; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            d = s[i] - '0';
            arr[d]++;
        }
    }

    for (int k = 0; k < 10; k++) {
        if(arr[k])
            printf("%d %d\n", k, arr[k]);
    }
}