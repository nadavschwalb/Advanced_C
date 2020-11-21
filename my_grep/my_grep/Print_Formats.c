#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "search_str.h"

#include "HardCodedData.h"
void print_formater(FILE* input_file, char* line_buffer, int* p_line_num, int options_flag) {
	char* formated_line = (char*)malloc(MAXBUFF);
	if (formated_line == NULL) { printf("failed to allocate memory\n"); exit(-1); }
	if ((_b & options_flag) == _b && (_n & options_flag) == _n) {
		sprintf(formated_line, "%lu : %d : %s", ftell(input_file), *p_line_num, line_buffer);
	} 
	else if ((_n & options_flag) == _n) {
		sprintf(formated_line, "%d : %s", *p_line_num, line_buffer);
	}
	else if ((_b & options_flag) == _b) {
		sprintf(formated_line, "%lu : %s", ftell(input_file), line_buffer);
	}
	else {
		free(formated_line);
		return;
	}
	
	strcpy(line_buffer, formated_line);
	free(formated_line);
	return;
	
}
