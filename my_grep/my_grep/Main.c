#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXBUFF 4096
int main(int argc, char** argv) {
	int option_flag = 0x0; //options flag -i-v-n-b-x-A
	int spacer_line_num = 0;
	char file_name[MAXBUFF];
	//TODO: get all command argumets
	for (int i = 1; i < argc; i++) {
		if (strchr(argv[i],'-') != NULL) { // option found
			switch (*(argv[i]+1))
			{
			case 'i':
				option_flag = option_flag | 0x100000;
				break;
			case 'v':
				option_flag = option_flag | 0x010000;
				break;
			case 'n':
				option_flag = option_flag | 0x001000;
				break;
			case 'b':
				option_flag = option_flag | 0x000100;
				break;
			case 'x':
				option_flag = option_flag | 0x000010;
				break;
			case 'A':
				option_flag = option_flag | 0x000001;
				spacer_line_num = atoi(argv[i + 1]);
				break;
			default:
				option_flag = option_flag | 0x0;
				break;
			}
		}

	}
	strcpy(file_name, argv[argc - 1]);
	printf("option flags: 0x%x -i-v-n-b-x-A\nNUM = %d\nfilename: %s\n", option_flag,spacer_line_num,file_name);
	
	
	//TODO: if no file given get stdin

	//TODO: open input file
	FILE* p_input_file = fopen(file_name, "r");
	if (p_input_file == NULL) {
		printf("failed to open file %s\n", file_name);
		exit(-1);
	}
	//TODO: get new line

	//TODO: search for string in new line

	//TODO: if found in 


	//TODO: cleanup
	close(p_input_file);
	return 0;
}