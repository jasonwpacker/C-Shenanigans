#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct node {
    int value;
    void* next;
} node_link;

void print_list (node_link *link_head);
node_link *add_node_front(node_link *old_header, int new_value);
void add_node_rear(node_link *old_header, int new_value);
void remove_nth_item(node_link * old_header, int n);

#endif