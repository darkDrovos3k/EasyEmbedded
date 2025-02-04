#include <stdint.h>

typedef struct list {
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

uint64_t findMaxBlock(list *head);


int main(void) {
    list n1 = {.address=140525067852320, .size=10, .next=NULL};
    list n2 = {.address=140525067852350, .size=30, .next=&n1};
    list n3 = {.address=140525067852900, .size=100, .next=&n2};

    findMaxBlock(&n3);
    return 0;
}

uint64_t findMaxBlock(list *head) {
    unsigned int max_memory = 0;
    uint64_t address = 0;

    while (head != NULL) {
        if (head->size > max_memory) {
            max_memory = head->size;
            address = head->address;
        }
        head = head->next;
    }
    return address;
}