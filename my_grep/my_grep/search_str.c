#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "search_str.h"
#include "HardCodedData.h"

//declarations
void str_lowwer(char* str_to_modifie);



bool search_str(char* new_line, char* search_phrase, int option_flag) 
{
	int return_val;
	//empty line check
	if (*(new_line) == '\n') return 0;

	char* line_copy = (char*)malloc(strlen(new_line) + 1);
	if (line_copy == NULL) { printf("failed to allocate memory\n"); exit(-1); }
	char* phrase_copy = (char*)malloc(strlen(search_phrase) + 2);
	if (line_copy == NULL) { printf("failed to allocate memory\n"); exit(-1); }
	strcpy(line_copy, new_line);
	strcpy(phrase_copy, search_phrase);

	// -i mode , ignore case 
	if (_i == (_i & option_flag)) {
		str_lowwer(line_copy);
		str_lowwer(phrase_copy);
	}
	// -x phrase matches line exactly
	if (_x ==(_x & option_flag)) {
		//printf("%s%s\n", line_copy, phrase_copy);
		if (strcmp(line_copy, phrase_copy) == 0 || 
			strcmp(line_copy, strcat(phrase_copy, "\n")) == 0
			) return_val = true;
		else return_val= false;
	}
	//phrase is substring of line
	else {
		if (strstr(line_copy, phrase_copy) == NULL) return_val= false;
		else return_val= true;
	}
	
	//free all the memory used
	free(line_copy);
	free(phrase_copy);
	if ((_v & option_flag) == _v) return !return_val;
	else return return_val;
}



void str_lowwer(char* str_to_modifie) {
	char* marker = str_to_modifie;
	while (*(marker) != '\0')
	{
		*(marker) = tolower(*(marker));
		marker++;
	}
	return;
}
