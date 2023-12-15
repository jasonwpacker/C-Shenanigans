#include <stdio.h>
#include "linkedlist.h"


int main() {
    node_link *head = NULL;
    head = add_node_front(head, 12);
    head = add_node_front(head, 7);
    add_node_rear(head, 1);
    print_list(head);
    remove_nth_item(head, 2);
    print_list(head);
}