#include <stdio.h>
#include "Linked_List.h"
#include "Input_Decode.h"



int main(int argc, char** argv) {

	Node* head = creat_new_node(1);
	Linked_List* list = init_list(head);
	print_list(list);
	Node* new_node = creat_new_node(2);
	list = append_node(list, new_node);
	print_list(list);
	new_node = creat_new_node(3);
	list = append_node(list, new_node);
	print_list(list);
	new_node = creat_new_node(5);
	list = append_node(list, new_node);
	print_list(list);
	new_node = creat_new_node(19);
	list = push_node(list, new_node);
	print_list(list);
	new_node = creat_new_node(10);
	list = push_node(list, new_node);
	print_list(list);
	new_node = creat_new_node(16);
	list = append_node(list, new_node);
	print_list(list);
	new_node = creat_new_node(21);
	list = insert_after(list, 10, new_node);
	print_list(list);
	print_index(list, 16);
	print_index(list, 23);
	print_index(list, 10);
	print_list(list);
	remove_node(list, 0);
	print_list(list);
	remove_node(list, 6);
	print_list(list);
	remove_node(list, 4);
	print_list(list);
	remove_node(list, 6);
	print_list(list);

	if(linked_list_cleanup(list)) return 0;
	else return(-1);
}