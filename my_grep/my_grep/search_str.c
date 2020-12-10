#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "search_str.h"
#include "HardCodedData.h"
#include "Regex_Engine.h"

void str_lowwer(char* str_to_modifie);
bool regex_strcmp(char* test_str, regex_member** member_list);
int resolve_parentheses(char* test_str, regex_member* member);
bool regex_strsrt(char* test_str, regex_member** member_list);


bool search_str(char* new_line, char* search_phrase, regex_member** member_list, int option_flag)
{
	int return_val;

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
		if (_E == (_E&option_flag)) {
			if (regex_strcmp(line_copy, member_list)) {
				//printf("compare true\n");
				return true;
			}
			else {
				//printf("compare false\n");
				return false;
			}
		}
		else {
			if (strcmp(line_copy, phrase_copy) == 0 ||
				strcmp(line_copy, strcat(phrase_copy, "\n")) == 0
				) return_val = true;
			else return_val = false;
		}
	}

	else {
		if (_E == (_E&option_flag)) {
			if (regex_strsrt(line_copy, member_list)) {
				//printf("compare true\n");
				return_val =  true;
			}
			else {
				//printf("compare false\n");
				return_val = false;
			}
		}
		else {
			if (strstr(line_copy, phrase_copy) == NULL) return_val = false;
			else return_val = true;
		}
	}
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

void regex_cleaner(char* dirtiy_str, char* delimiter) {
	char* tokens[MAX_BUFFER];
	int i = 1;
	tokens[0] = strtok(dirtiy_str, "\\");
	
	while (tokens[i-1] != NULL) {
		tokens[i] = strtok(NULL, "\\");
		i++;
	}
	
	sprintf(dirtiy_str, "%s%s", tokens[0], tokens[1]);
}

bool regex_strcmp(char* test_str, regex_member** member_list) {
	char* curser = test_str;
	char test_char;
	char regex_char;
	int i = 0;
	bool loop_condition = true;
	do
	{
		test_char = *(curser++);
		if (test_char == '\0' || test_char =='\n') {
			loop_condition = false;
		}
		else {
			switch (member_list[i]->type)
			{
			case regular_char:
				regex_char = member_list[i]->simple_char;
				if (regex_char == test_char) loop_condition = true;
				else return false;
				break;
			case dot:
				loop_condition = true;
				break;
			case bracket:
				if (test_char >= member_list[i]->p_square_bracket->start_char &&
					test_char <= member_list[i]->p_square_bracket->end_char) loop_condition = true;
				else return false;
				break;
			case paren:
				curser -= 1;
				int move_str = resolve_parentheses(curser, member_list[i]);
				if (move_str != 0) {
					curser += move_str;
					loop_condition = true;
				}
				else return false;
				break;
			case null_teminator:
				return false; //regex_str to short
				break;
			default:
				break;
			}
		}
		i++;
	} while (loop_condition);
	return true;
}

bool regex_strsrt(char* test_str, regex_member** member_list) {
	//const char* test_str_cpy = test_str;
	char test_char;
	char regex_char;
	bool loop_condition = true;
	int i = 0;
	while (*test_str != '\0') {
		i = 0;
		char* curser = test_str;
		do
		{
			test_char = *(curser++);
			if (test_char == '\n') {
				loop_condition = false;
			}
			else {
				switch (member_list[i]->type)
				{
				case regular_char:
					regex_char = member_list[i]->simple_char;
					if (regex_char == test_char) loop_condition = true;
					else loop_condition = false;
					break;
				case dot:
					loop_condition = true;
					break;
				case bracket:
					if (test_char >= member_list[i]->p_square_bracket->start_char &&
						test_char <= member_list[i]->p_square_bracket->end_char) loop_condition = true;
					else loop_condition = false;
					break;
				case paren:
					curser -= 1;
					int move_str = resolve_parentheses(curser, member_list[i]);
					if (move_str != 0) {
						curser += move_str;
						loop_condition = true;
					}
					else loop_condition = false;
					break;
				case null_teminator:
					return true;
					break;
				default:
					break;
				}
			}
			i++;
		} while (loop_condition);
		test_str += 1;
	}
	return false;
}

int resolve_parentheses(char* test_str, regex_member* member) {
	int ret_val;
	char* str_a = member->p_parentheses->str_a;
	char* str_b = member->p_parentheses->str_b;
	unsigned int len_a = strlen(str_a);
	unsigned int len_b = strlen(str_b);
	unsigned int safty_buffer = len_a + len_b + strlen(test_str);
	if (strlen(test_str) < len_a && strlen(test_str) < len_b) return 0; //test_str too short can't match
	char* sub_str_a = (char*)malloc(safty_buffer);
	char* sub_str_b = (char*)malloc(safty_buffer);
	strncpy(sub_str_a, test_str, safty_buffer);
	strncpy(sub_str_b, test_str, safty_buffer);
	sub_str_a[len_a] = '\0';
	sub_str_b[len_b] = '\0';
	if (strcmp(sub_str_a, str_a) == 0) {
		ret_val = strlen(str_a);
	} 
	else if (strcmp(sub_str_b, str_b) == 0) {
		ret_val = strlen(str_b);
	}
	else ret_val = 0;
	free(sub_str_a);
	free(sub_str_b);
	return ret_val;
}
