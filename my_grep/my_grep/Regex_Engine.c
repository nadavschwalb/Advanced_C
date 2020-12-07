#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Regex_Engine.h"

char* handle_parentheses(char* input_string, regex_member* member);
char* handle_square_brackets(char* input_string, regex_member* member);

regex_member** regex_parser(char* search_str,regex_member** member_list, int* member_list_len) {
	 
	int member_count = 0;
	int regex_state = -1;

	while (*search_str != '\0') {
		member_list[member_count] = (regex_member*)malloc(sizeof(regex_member));
		switch (*search_str)
		{
		case '(':
			search_str = handle_parentheses((search_str+1), member_list[member_count]);
			break;
		case '[':
			search_str = handle_square_brackets(search_str + 1, member_list[member_count]);
			break;
		case'.':
			member_list[member_count] = (regex_member*)malloc(sizeof(regex_member));
			member_list[member_count]->simple_char = *search_str;
			member_list[member_count]->type = dot;
			break;
		case '\\':
			member_list[member_count] = (regex_member*)malloc(sizeof(regex_member));
			//member_list[member_count]->simple_char = *(search_str++); choose this option if bug apears on nova
			member_list[member_count]->simple_char = *(search_str+=1);
			member_list[member_count]->type = regular_char;
			break;
		default:
			member_list[member_count] = (regex_member*)malloc(sizeof(regex_member));
			member_list[member_count]->simple_char = *search_str;
			member_list[member_count]->type = regular_char;
			break;
		}
		search_str++;
		member_count++;
	}
	*member_list_len = member_count;
	return member_list;
}

char* handle_parentheses(char* input_string, regex_member* member) {
	member->p_parentheses = (parentheses*)malloc(sizeof(parentheses));
	member->p_parentheses->str_a = (char*)malloc(strlen(input_string));
	member->p_parentheses->str_b = (char*)malloc(strlen(input_string));
	member->type = paren;
	int i = 0;
	int j = 0;
	while (*input_string != '|') {
		member->p_parentheses->str_a[i] = *input_string;
		i++;
		input_string++;
		
	}
	member->p_parentheses->str_a[i] = '\0';
	i = 0;
	input_string++;
	while (*input_string != ')') {
		member->p_parentheses->str_b[i] = *input_string;
		i++;
		input_string++;
	}
	member->p_parentheses->str_b[i] = '\0';
	return input_string;
	
}

char* handle_square_brackets(char* input_string, regex_member* member) {
	member->p_square_bracket = (square_bracket*)malloc(sizeof(square_bracket));
	member->type = bracket;
	member->p_square_bracket->start_char = *input_string;
	input_string += 2;
	member->p_square_bracket->end_char = *input_string;
	input_string += 2;
	return input_string;
}

void print_members(regex_member** member_list, int list_size) {
	int i = 0;
	for(i=0; i<list_size; i++) {
		if (member_list[i]->type == regular_char) {
			printf("member type: regular char\nchar: %c\n", member_list[i]->simple_char);
		}
		else if (member_list[i]->type == paren) {
			printf("member type: parentheses\nstr_a: %s\nstr_b: %s\n",
				member_list[i]->p_parentheses->str_a,
				member_list[i]->p_parentheses->str_b);
		}
		else if (member_list[i]->type == bracket) {
			printf("member type: square bracket\nstart char: %c\nend char: %c\n",
				member_list[i]->p_square_bracket->start_char,
				member_list[i]->p_square_bracket->end_char);
		}
		else if (member_list[i]->type == dot) {
			printf("member type: dot char\nchar: %c\n", member_list[i]->simple_char);
		}
		else if (member_list[i]->type == backslash) {
			printf("member type: backslash char\nchar: %c\n", member_list[i]->simple_char);
		}
	}
}