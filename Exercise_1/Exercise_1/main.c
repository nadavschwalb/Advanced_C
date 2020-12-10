#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "Linked_List.h"
#include "Input_Decode.h"

#define MAX_INPUT_LINE_SIZE 100

bool exit_condition = false;

int main(int argc, char** argv) {
	char line[MAX_INPUT_LINE_SIZE];
	char command[MAX_INPUT_LINE_SIZE];
	int i,j=0;
	Linked_List* list = init_list();
	while (!exit_condition) {
		fgets(line, MAX_INPUT_LINE_SIZE, stdin);
		sscanf(line, "%s %d %d \n", command, &i, &j);
		str_lower(command);
		command_executor(list, command, i, j);
	}
	return 0;
}