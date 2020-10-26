#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LINE_SIZE 100

//int main(int argc, char** argv) {
//	bool ex = false;
//	char line[MAX_INPUT_LINE_SIZE];
//	char command[MAX_INPUT_LINE_SIZE];
//	int i,j=0;
//	while (!ex) {
//		printf("Enter command: \n");
//		fgets(line, MAX_INPUT_LINE_SIZE, stdin);
//		printf(line);
//		sscanf(line, "%s %d %d \n", command, &i, &j);
//		printf("\n string: %s \n num1: %d \n num2: %d \n", command, i, j);
//		strlwr(command);
//		printf("\n string low: %s \n", command);
//	}
//	return 0;
//}