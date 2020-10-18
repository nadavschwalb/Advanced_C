#include <stdio.h>
#include "Linked_List.h"
#include "Input_Decode.h"



int main(int argc, char** argv) {

	Node* head = creat_new_node(1);
	Linked_List* list = init_list(head);
	Node* new_node = creat_new_node(2);
	list = append_node(list, new_node);
	new_node = creat_new_node(3);
	list = append_node(list, new_node);
	new_node = creat_new_node(5);
	list = append_node(list, new_node);
	print_list(list);

	if(linked_list_cleanup(list)) return 0;
	else return(-1);
}