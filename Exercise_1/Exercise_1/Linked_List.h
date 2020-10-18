#pragma once
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
}Node;

typedef struct Linked_List
{
	struct Node* head;
	struct Node* tail;

}Linked_List;

Node* creat_new_node(int data);
Linked_List* init_list(Node* head);
Linked_List* append_node(Linked_List* list, Node* end_node);
void print_list(Linked_List* list);
int linked_list_cleanup(Linked_List* list);