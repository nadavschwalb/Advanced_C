#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "search_str.h"


#define MAXBUFF 4096
int main(int argc, char** argv) {
	int option_flag = 0x0; //options flag -i-v-n-b-x-A-c
	int spacer_line_num = 0;
	char file_name[MAXBUFF]; 
	char line_buffer[MAXBUFF]; //holds line read from file
	char search_buffer[MAXBUFF]; // holds sub string argument to search for in line
	//TODO: get all command argumets
	for (int i = 1; i < argc; i++) {
		if (strchr(argv[i],'-') != NULL) { // option found
			switch (*(argv[i]+1))
			{
			case 'i':
				option_flag = option_flag | 0x1000000;
				break;
			case 'v':
				option_flag = option_flag | 0x0100000;
				break;
			case 'n':
				option_flag = option_flag | 0x0010000;
				break;
			case 'b':
				option_flag = option_flag | 0x0001000;
				break;
			case 'x':
				option_flag = option_flag | 0x0000100;
				break;
			case 'A':
				option_flag = option_flag | 0x0000010;
				spacer_line_num = atoi(argv[i + 1]);
				break;
			case 'c':
				option_flag = option_flag | 0x0000001;

			default:
				option_flag = option_flag | 0x0;
				break;
			}
		}

	}
	strcpy(search_buffer, argv[argc - 2]);
	strcpy(file_name, argv[argc - 1]);
	printf("option flags: 0x%x -i-v-n-b-x-A-c\nNUM = %d\nfilename: %s\n", option_flag,spacer_line_num,file_name);
	
	
	//TODO: if no file given get stdin

	//TODO: open input file
	FILE* p_input_file = fopen(file_name, "r");
	if (p_input_file == NULL) {
		printf("failed to open file %s\n", file_name);
		exit(-1);
	}
	//TODO: while get new line until EOF
	while (fgets(line_buffer, MAXBUFF, p_input_file) != NULL) {
		printf("input line : %s\ninput frase to search: %s\n", line_buffer,search_buffer);
		int t = search_str(line_buffer, search_buffer, option_flag);
		printf("%d\n", t);
	}
	

	//TODO: if found in 

	//TODO: get line number


	
	
	

	//TODO: byte number

	//TODO: cleanup
	close(p_input_file);
	return 0;
}