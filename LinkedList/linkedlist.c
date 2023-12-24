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

node_link *add_node_front(node_link *old_header, int new_value) {
    node_link *new_header;
    new_header = malloc(sizeof(node_link));
    new_header->value = new_value;
    new_header->next = old_header;
    return new_header;
}

void add_node_rear(node_link *old_header, int new_value) {
    node_link *temp_list = old_header;
    while (temp_list->next) {
        temp_list = temp_list->next;
    }
    node_link *new_node;
    new_node = malloc(sizeof(node_link));
    new_node->value = new_value;
    temp_list->next = new_node;
}

void remove_nth_item(node_link * old_header, int n) {
    if (n < 1) {
        fprintf(stderr, "index %d is not a valid value\n", n);
        return;
    }
    node_link *temp_list = old_header;
    for (int i = 1; i < n; i++) {
        if (temp_list->next) {
            temp_list = temp_list->next;
        } else {
            fprintf(stderr, "There is no element at position %d to remove.\n", n);
            return;
        }
    }
    node_link *buffer = temp_list->next;
    temp_list->next = buffer->next;
    free(buffer);
}