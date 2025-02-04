#include <stdint.h>

typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

size_t totalMemoryUsage(list *head);


int main(void) {
    list n1 = {.address=(void *)140525067852320, .size=10, .next=NULL};
    list n2 = {.address=(void *)140525067852350, .size=30, .next=&n1};
    list n3 = {.address=(void *)140525067852900, .size=100, .next=&n2};

    totalMemoryUsage(&n3);
    return 0;
}

size_t totalMemoryUsage(list *head) {
    unsigned int total_memory = 0;

    while (head != NULL) {
        total_memory += head->size;
        head = head->next;
    }
    return total_memory;
}