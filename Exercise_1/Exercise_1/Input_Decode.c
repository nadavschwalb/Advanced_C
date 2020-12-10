
#include <string.h>
#include <stdbool.h>
#include<ctype.h>
#include <stdio.h>
#include "Linked_List.h"


void command_executor(Linked_List* list, char* input_command, int i, int j) {
	extern bool exit_condition;
	if (0 == strcmp(input_command, "add_end")) {
		append_node(list,creat_new_node(i));
	}
	else if (0 == strcmp(input_command, "add_start")) {
		push_node(list, creat_new_node(i));
	}
	else if (0 == strcmp(input_command, "add_after")) {
		insert_after(list, j, creat_new_node(i));
	}
	else if (0 == strcmp(input_command, "index")) {
		print_index(list, i);
	}
	else if (0 == strcmp(input_command, "del")) {
		remove_node(list, i);
	}
	else if (0 == strcmp(input_command, "print")) {
		print_list(list);
	}
	else if (0 == strcmp(input_command, "exit")) {
		linked_list_cleanup(list);
		exit_condition = true;
	}
	else {
		printf("Error: Non valid command");
	}
}



char *str_lower(char *str)
{
	unsigned char *p_temp = (unsigned char *)str;

	while (*p_temp) {
		*p_temp = tolower((unsigned char)*p_temp);
		p_temp++;
	}

	return str;
}
