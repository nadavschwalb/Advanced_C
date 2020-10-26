#include "Input_Decode.h"
#include "Linked_List.h"
#include <string.h>


//TODO: input parser , Not case sensative 


void command_exeutor(Linked_List* list, char* input_command, int i, int j) {
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
		return 0;
	}
	else if (0 == strcmp(input_command, "del")) {
		remove_node(list, i);
	}
	else if (0 == strcmp(input_command, "print")) {
		print_list(list);
	}
	else if (0 == strcmp(input_command, "exit")) {
		linked_list_cleanup(list);
	}
	else {
		printf("Error: Non valid command");
	}
}
//TODO: exit sequence

