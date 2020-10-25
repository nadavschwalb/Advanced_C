#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "Linked_List.h"
#include "Input_Decode.h"

#define MAX_INPUT_LINE_SIZE 100

bool exit_condition = false;

int main(int argc, char** argv) {
	char line[MAX_INPUT_LINE_SIZE];
	char command[MAX_INPUT_LINE_SIZE];
	int i, j = 0;
	Linked_List* list = init_list();
	printf("list initiated \n");
	while (!exit_condition) {
		printf("Enter command: \n");
		fgets(line, MAX_INPUT_LINE_SIZE, stdin);
		sscanf(line, "%s %d %d \n", command, &i, &j);
		strlwr(command);
		command_exeutor(list, command, i, j);
	}
	return 0;
}