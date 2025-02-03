#include <stdio.h>


int main(void) {
    int n, num;
    unsigned int res = 0;
    scanf("%d", &n);

    while(n--) {
        scanf("%d", &num);
        res ^= num;
    }
    printf("%u", res);

    return 0;
}