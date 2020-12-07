#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "search_str.h"
#include "HardCodedData.h"
#include "Print_Formats.h"
#include "Regex_Engine.h"

void print_formater(FILE* input_file, char* line_buffer, formating_args* args, int options_flag) {
	char* formated_line = (char*)malloc(MAX_BUFFER);
	if (formated_line == NULL) { printf("failed to allocate memory\n"); exit(-1); }
	if ((_b & options_flag) == _b && (_n & options_flag) == _n) {
		sprintf(formated_line, "%d%c%d%c%s", args->line_num,
											args->seperating_char,
											args->byte_num,
											args->seperating_char,
											line_buffer);
	} 
	else if ((_n & options_flag) == _n) {
		sprintf(formated_line, "%d%c%s", args->line_num, args->seperating_char, line_buffer);
	}
	else if ((_b & options_flag) == _b) {
		sprintf(formated_line, "%d%c%s", args->byte_num, args->seperating_char, line_buffer);
	}
	else {
		free(formated_line);
		return;
	}
	args->byte_num += strlen(line_buffer);
	strcpy(line_buffer, formated_line);
	free(formated_line);
	return;
	
}


void printer(FILE* input_file, search_args* search_args, formating_args* format_args, regex_member** member_list, int options_flag) {
	
	if ((_A & options_flag) == _A && format_args->first_line_found == true) { 
		if (search_str(search_args->line, search_args->search_str,member_list ,options_flag)) { 
			if (format_args->extra_lines_count >= format_args->extra_lines_to_print+1) {
				format_args->seperating_char = ':';
				format_args->extra_lines_count = 0;
				print_formater(input_file, search_args->line, format_args, options_flag);
				printf("--\n");
				printf("%s", search_args->line);
				return;
			}
			else {																	
				format_args->seperating_char = ':';
				format_args->extra_lines_count = 0;
				print_formater(input_file, search_args->line, format_args, options_flag);
				printf("%s", search_args->line);
				return;
			}
		}
		else { 
			if (format_args->extra_lines_count < format_args->extra_lines_to_print) {
				format_args->seperating_char = '-';
				format_args->extra_lines_count++;
				print_formater(input_file, search_args->line, format_args, options_flag);
				printf("%s", search_args->line);
				return;
			}
			else {
				format_args->extra_lines_count++;
				format_args->byte_num += strlen(search_args->line);
				return;
			}
		}
	}
	else {
		if (search_str(search_args->line, search_args->search_str, member_list,options_flag)) { 
			print_formater(input_file, search_args->line, format_args, options_flag);
			printf("%s", search_args->line);
			format_args->first_line_found = true;
			return;
		}
		else{
			format_args->byte_num += strlen(search_args->line); 
			return;
		}
	}
}


