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

void print_formater(FILE* input_file, char* line_buffer, formating_args* args, int options_flag);
void printer(FILE* input_file, search_args* search_args, formating_args* format_args, int options_flag);

#endif // ! PRINT_FORMAT_H