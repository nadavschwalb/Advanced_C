#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include "search_str.h"

#define MAXBUFF 4096
int search_str(char* new_line, char* search_phrase, int mode_flag) 
{
	int return_val;
	//empty line check
	if (*(new_line) == '\n') return 0;

	char* line_copy = (char*)malloc(strlen(new_line) + 1);
	char* phrase_copy = (char*)malloc(strlen(search_phrase) + 10);
	strcpy(line_copy, new_line);
	strcpy(phrase_copy, search_phrase);
	// -i mode , ignore big/small letters
	if (0x01000000 == (0x01000000 & mode_flag)) {
		str_lowwer(line_copy);
		str_lowwer(phrase_copy);
	}
	//only frase in the kine -x
	if (0x00000100 ==(0x00000100 & mode_flag)) {
		if (strcmp(line_copy, strcat(phrase_copy, "\n")) == 0) {
			return_val= 1;
		}
		else {
			return_val= 0;
		}
	}
	//not only the frase in line
	else {
		if (strstr(line_copy, phrase_copy) == NULL) {
			return_val= 0;
		}
		else {
			return_val= 1;
		}
	}
	//printf_s("%s\n", new_line);
	//printf_s("%s\n", line_copy);	
	//printf_s("%s\n",search_frase );
	//printf_s("%s\n", frase_copy);
	
	//free all the memory used
	free(line_copy);
	free(phrase_copy);
	return return_val;
}
		//TODO str_lowwer()


void str_lowwer(char* str_to_modifie) {
	char* marker = str_to_modifie;
	while (*(marker) != '\0')
	{
		*(marker) = tolower(*(marker));
		marker++;
	}
	return;
}


 /*char* copy_line_to_lowwer(char* original_line) {
	char* low_line=(char*)malloc(MAXBUFF+1);
	int count=0;
	strcpy(low_line, original_line);
	while (*(low_line+count) != '\0') 
	{
		*(low_line+count) = tolower(*(low_line+count));
		count = count + sizeof(char);
	}
	return low_line;
}

 char* coppy_search_str_to_lowwer(char* frase) {
	 int count = 0;
	 char* low_frase_copy = (char*)malloc(MAXBUFF + 1);
	 strcpy(low_frase_copy, frase);
	 while (*(low_frase_copy + count) != '\0') {
		 *(low_frase_copy+count) = tolower(*(low_frase_copy + count));
		 count = count + sizeof(char);
	 }
	 return low_frase_copy;
 }


 */