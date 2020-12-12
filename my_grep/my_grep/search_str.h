#ifndef SEARCH_STR_H
#define SEARCH_STR_H
#include "HardCodedData.h"
#include "Regex_Engine.h"
#include <stdbool.h>

typedef struct search_args {
  char line[MAX_BUFFER];
  char search_str[MAX_BUFFER];
  char regex_str[MAX_BUFFER];
} search_args;

bool search_str(char* new_line, char* search_phrase, regex_member** member_list, int mode_flag);
void regex_cleaner(char* dirtiy_str, char* delimiter);
#endif  // !SEARCH_STR_H
