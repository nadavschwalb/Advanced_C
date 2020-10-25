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
Linked_List* init_list();
Linked_List* append_node(Linked_List* list, Node* end_node);
void print_list(Linked_List* list);
int linked_list_cleanup(Linked_List* list);
Linked_List* push_node(Linked_List* list, Node* push_node);
Linked_List* insert_after(Linked_List* list, int delimit_node, Node* insert_node);
void print_index(Linked_List* list, int node_data);
void remove_node(Linked_List* list, int remove_index);
int list_empty(Linked_List* list);