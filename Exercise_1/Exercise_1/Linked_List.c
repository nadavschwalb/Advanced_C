#include "Linked_List.h"
#include <stdlib.h>


Linked_List* init_list(Node* head) {
	Linked_List* new_list = (Linked_List*)malloc(sizeof(Linked_List));
	new_list->head = head;
	new_list->tail = NULL;
	return new_list;
}

Node* creat_new_node(int data){
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}


Linked_List* append_node(Linked_List* list, Node* end_node) {
	if (list->tail == NULL) {
		list->head->next = end_node;
		list->tail = end_node;
		end_node->prev = list->head;
		
	}
	else {
		end_node->prev = list->tail;
		list->tail->next = end_node;
		list->tail = end_node;
	}
	return list;
}

//TODO: insert node at begining of list
 
//TODO: insert node after first occurrence of j

//TODO: print the first index where node i is found -1 if not found, index starts at 0

//TODO: remove node at index i, if index is out of bound print error and exit

//UNDONE: print entire list as array []

void print_list(Linked_List* list) {
	Node* curser = list->head;
	printf("list: [");
	while (curser != NULL)
	{
		printf("%d, ", curser->data);
		curser = curser->next;
	}
	printf(" ]\n");
}


int linked_list_cleanup(Linked_List* list) {
	while (list->head != NULL) {
		Node* free_node = list->head;
		list->head = list->head->next;
		free(free_node);
	}
	if (list->tail == NULL) {
		free(list);
		return 0;
	}
	else return -1;
	
	
	
}