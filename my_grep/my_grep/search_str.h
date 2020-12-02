#ifndef SEARCH_STR_H
#define SEARCH_STR_H
#include <stdbool.h>
#include "HardCodedData.h"
typedef struct search_args {
	char line[MAX_BUFFER];
	char search_str[MAX_BUFFER];
	char regex_str[MAX_BUFFER];
}search_args;
bool search_str(char* new_line, char* search_phrase, int mode_flag);
#endif // !SEARCH_STR_H

void regex_cleaner(char* dirtiy_str, char* delimiter);

