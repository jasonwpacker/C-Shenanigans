#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    void* next;
} node_link;

void print_list (node_link *link_head) {
    node_link *cursor = link_head;
    while (link_head) {
        printf("->%d", link_head->value);
        link_head = link_head->next;
    }
    printf("\n");
}

int main() {
    node_link *head = NULL;
    print_list(head);
}
