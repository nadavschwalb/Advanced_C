#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "search_str.h"
#include "HardCodedData.h"
#include "Print_Formats.h"


int main(int argc, char** argv) {
	int option_flag = 0b0; //options flag -i-v-n-b-x-A-c-E
	int options_count = 0;
	char file_name[MAX_BUFFER];
	formating_args print_format_args = { 0, 0, 1, 0, false, ':'};
	search_args search_args = {"",""};
	FILE* p_input_file;

	for (int i = 1; i < argc; i++) {
		if (strchr(argv[i], '-') != NULL) { 
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
				print_format_args.extra_lines_to_print = atoi(argv[i + 1]);
				break;
			case 'c':
				option_flag = option_flag | _c;
				options_count++;
			case 'E':
				option_flag = option_flag | _E;
				options_count+=1;
				strcpy(search_args.regex_str, argv[i + 1]);

			default:
				option_flag = option_flag | 0b0;
				break;
			}
		}

	}
	if (argc - options_count > 2) { 
		strcpy(search_args.search_str, argv[argc - 2]);
		strcpy(file_name, argv[argc - 1]);
		p_input_file = fopen(file_name, "r");
		if (p_input_file == NULL) {
			printf("failed to open file %s\n", file_name);
			exit(-1);
		}
	}
	else {
		strcpy(search_args.search_str, argv[argc - 1]);
		p_input_file = stdin;
	}
	if ((_E & option_flag) == _E) {
		strncpy(search_args.search_str, &search_args.regex_str[1],strlen(search_args.regex_str)-2);
	}
	

 	while (fgets(search_args.line, MAX_BUFFER, p_input_file) != NULL) {
		printer(p_input_file, &search_args, &print_format_args, option_flag);
		print_format_args.line_num++;

	}

	//TODO: -A NUM - print NUM rows after each found row
	//TODO: -n -print line number in file
	//TODO: -b - print bytes before each line
	//TODO: -E regex
		fclose(p_input_file);
		return 0;

}
