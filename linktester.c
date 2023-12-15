#include <stdio.h>
#include "linkedlist.h"


int main() {
    node_link *head = NULL;
    print_list(head);
    head = add_node_front(head, 12);
    print_list(head);
    head = add_node_front(head, 7);
    print_list(head);
    add_node_rear(head, 1);
    print_list(head);
    remove_nth_item(head, 2);
    print_list(head);
}