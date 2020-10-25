#include "Input_Decode.h"
#include <stdlib.h>


Linked_List* init_list() {
	Linked_List* new_list = (Linked_List*)malloc(sizeof(Linked_List));
	new_list->head = NULL;
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
	if (list_empty(list)) return push_node(list, end_node);
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


Linked_List* push_node(Linked_List* list, Node* push_node) {
	if (list_empty(list)) {
		list->head = push_node;
		return list;
	}
	else{
		push_node->next = list->head;
		list->head->prev = push_node;
		list->head = push_node;
		return list;
	}

 }

Linked_List* insert_after(Linked_List* list, int delimit_node, Node* insert_node) {
	if (list_empty(list)) {
		printf("AccessError: %d not found in list\n", delimit_node);
		exit(-1);
	}
	Node* curser = list->head;
	while (curser->next != NULL)
	{
		if (curser->data == delimit_node) {
			curser->next->prev = insert_node;
			insert_node->next = curser->next;
			curser->next = insert_node;
			insert_node->prev = curser;
			return list;
		}
		curser = curser->next;
	}
	printf("AccessError: %d not found in list\n", delimit_node);
	exit(-1);
}

void print_index(Linked_List* list, int node_data) {
	if (list_empty(list)) {
		printf("ErrorCode :-1 element not found\n");
		return;
	}
	Node* curser = list->head;
	int index = 0;
	while (curser != NULL) {
		if (curser->data == node_data) {
			printf("element %d found at index %d\n", node_data, index);
			return;
		}
		index++;
		curser = curser->next;
	}
	printf("ErrorCode :-1 element not found\n");
	return;
}


void remove_node(Linked_List* list, int remove_index) {
	if (list_empty(list)) {
		printf("AccessError: list is empty\n");
		exit(-1);
	}
	Node* curser = list->head;
	int index = 0;
	if (remove_index == 0) {
		list->head = list->head->next;
		if (list->head == NULL) list->tail = NULL;
		printf("element %d removed at index %d\n", curser->data, remove_index);
		free(curser);
		return;
	}

	while (curser->next != NULL){
		if (index == remove_index) {
			curser->next->prev = curser->prev;
			curser->prev->next = curser->next;
			printf("element %d removed at index %d\n", curser->data, index);
			free(curser);
			return;
		}
		curser = curser->next;
		index++;
	}
	if (index == remove_index) { //remove last node in list
		curser->prev->next = NULL;
		printf("element %d removed at index %d\n", curser->data, index);
		return;
	}
	else {
		printf("AccessError: index given {%d} is out of bounds\n",remove_index);
		exit(-1);
	}

}



void print_list(Linked_List* list) {
	
	if (list_empty(list)) {
		printf("[]\n");
		return;
	}
	Node* curser = list->head;
	printf("list: [");
	while (curser->next != NULL)
	{
		printf("%d, ", curser->data);
		curser = curser->next;
	}
	printf("%d]\n",curser->data);
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

int list_empty(Linked_List* list) {
	if (list->head == NULL && list->tail == NULL) return 1;
	else return 0;
}