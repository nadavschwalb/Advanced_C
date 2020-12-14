#ifndef  PRINT_FORMAT_H
#define PRINT_FORMAT_H


typedef struct formating_args {
	int extra_lines_to_print;
	int extra_lines_count;
	int line_num;
	int byte_num;
	bool first_line_found;
	char seperating_char;
}formating_args;

void printer(FILE* input_file, 
		search_args* search_args,
		formating_args* format_args, 
		regex_member** member_list, 
		int options_flag);

#endif // ! PRINT_FORMAT_H
