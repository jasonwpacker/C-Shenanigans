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
    node_link *temp_list = old_header;
    for (int i = 1; i < n-1; i++) {
        temp_list = temp_list->next;
    }
    node_link *buffer = temp_list->next;
    temp_list->next = buffer->next;
    free(buffer);
}


int main() {
    node_link *head = NULL;
    head = add_node_front(head, 12);
    head = add_node_front(head, 7);
    add_node_rear(head, 1);
    print_list(head);
    remove_nth_item(head, 2);
    print_list(head);
}
