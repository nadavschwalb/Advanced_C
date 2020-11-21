#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "search_str.h"
#include "HardCodedData.h"
#include "Colors.h"
#include "Print_Formats.h"


int main(int argc, char** argv) {
	int option_flag = 0b0; //options flag -i-v-n-b-x-A-c-E
	int options_count = 0;
	int spacer_line_num = 0;
	char file_name[MAXBUFF];
	char line_buffer[MAXBUFF]; //holds line read from file
	char search_buffer[MAXBUFF]; // holds sub string argument to search for in line
	FILE* p_input_file;
	for (int i = 1; i < argc; i++) {
		if (strchr(argv[i], '-') != NULL) { // option found
			switch (*(argv[i] + 1))
			{
			case 'i':
				option_flag = option_flag | _i;
				options_count++;
				break;
			case 'v':
				option_flag = option_flag | _v;
				options_count++;
				break;
			case 'n':
				option_flag = option_flag | _n;
				options_count++;
				break;
			case 'b':
				option_flag = option_flag | _b;
				options_count++;
				break;
			case 'x':
				option_flag = option_flag | _x;
				options_count++;
				break;
			case 'A':
				option_flag = option_flag | _A;
				options_count+=2;
				spacer_line_num = atoi(argv[i + 1]);
				break;
			case 'c':
				option_flag = option_flag | _c;
				options_count++;
			case 'E':
				option_flag = option_flag | _E;
				options_count++;

			default:
				option_flag = option_flag | 0b0;
				break;
			}
		}

	}
	if (argc - options_count > 2) { //file given
		strcpy(search_buffer, argv[argc - 2]);
		strcpy(file_name, argv[argc - 1]);
		p_input_file = fopen(file_name, "r");
		if (p_input_file == NULL) {
			printf("failed to open file %s\n", file_name);
			exit(-1);
		}
	}
	else {
		strcpy(search_buffer, argv[argc - 1]);
		p_input_file = stdin;
	}
	
	//TODO: if no file given get stdin

	//TODO: open input file


	//TODO: while get new line until EOF
	int line_num = 0;
 	while (fgets(line_buffer, MAXBUFF, p_input_file) != NULL) {
		if ( (_v & option_flag) == _v) {
			if (!search_str(line_buffer, search_buffer, option_flag)) {
				//set_text_color(green_text);
				print_formater(p_input_file, line_buffer, &line_num, option_flag);
				printf("%s",line_buffer);
				//set_text_color(reset_text);
			}
			else {
				//printf("%s", line_buffer);
			}
		}
		else {
			if (search_str(line_buffer, search_buffer, option_flag)) {
				//set_text_color(green_text);
				print_formater(p_input_file, line_buffer, &line_num, option_flag);
				printf("%s", line_buffer);
				//set_text_color(reset_text);
			}
			else {
				//printf("%s", line_buffer);
			}
		}
		line_num++;
	}



		//TODO: if found in 

		//TODO: get line number






		//TODO: byte number

		//TODO: cleanup
		fclose(p_input_file);
		return 0;

}
