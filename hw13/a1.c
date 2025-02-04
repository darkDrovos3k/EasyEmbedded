#include <stdio.h>
#include <limits.h>


int main(void) {
    int n, num, max = INT_MIN, count;
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &num);
        if (num > max) {
            max = num;
            count = 1;
        } else if (num == max ) {
            count++;
        }
    }

    printf("%d", count);
    return 0;
}