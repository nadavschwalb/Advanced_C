#ifndef REGEX_ENGINE_H
#define REGEX_ENGINE_H
#include"HardCodedData.h"
typedef struct square_bracket {
	char start_char; 
	char end_char;
}square_bracket;

typedef struct parentheses {
	char* str_a;
	char* str_b;
}parentheses;

enum {
	dot,
	regular_char,
	backslash,
	paren,
	bracket,
	undefined,
	null_teminator
};
typedef struct regex_member {
	int type;
	union {
		char simple_char;
		parentheses* p_parentheses;
		square_bracket* p_square_bracket;
	};
	

}regex_member;

regex_member** regex_parser(char* search_str, regex_member** member_list, int* member_list_len);
int get_list_len(regex_member** member_list);
void free_regex_member_list(regex_member** member_list);
#endif // !REGEX_ENGINE_H


