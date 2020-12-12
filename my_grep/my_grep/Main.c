#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HardCodedData.h"
#include "Print_Formats.h"
#include "Regex_Engine.h"
#include "search_str.h"

void options_parser(int argc, char** argv, options_struct* options, search_args* str_search_args,
                    formating_args* print_format_args);
void options_parser(int argc, char** argv,
					options_struct* options,
					search_args* str_search_args, 
					formating_args* print_format_args){
	
  for (int i = 1; i < argc; i++) {
    if (strchr(argv[i], '-') != NULL) {
      switch (*(argv[i] + 1)) {
        case 'i':
          options->option_flag = options->option_flag | _i;
          options->option_count++;
          break;
        case 'v':
          options->option_flag = options->option_flag | _v;
          options->option_count++;
          break;
        case 'n':
          options->option_flag = options->option_flag | _n;
          options->option_count++;
          break;
        case 'b':
          options->option_flag = options->option_flag | _b;
          options->option_count++;
          break;
        case 'x':
          options->option_flag = options->option_flag | _x;
          options->option_count++;
          break;
        case 'A':
          options->option_flag = options->option_flag | _A;
          options->option_count += 2;
		  print_format_args->extra_lines_to_print = atoi(argv[i + 1]);
          break;
        case 'c':
          options->option_flag = options->option_flag | _c;
          options->option_count++;
          break;
        case 'E':
          options->option_flag = options->option_flag | _E;
          options->option_count += 1;
          strcpy(str_search_args->regex_str, argv[i + 1]);
          break;
        default:
          options->option_flag = options->option_flag | 0b0;
          break;
      }
    }
  }
}

int main(int argc, char** argv)
{
  char file_name[MAX_BUFFER];
  options_struct options = {0, 0};
  formating_args print_format_args = {0, 0, 1, 0, false, ':'};
  search_args str_search_args = {"", ""};
  FILE* p_input_file;
 
  options_parser(argc, argv, &options, &str_search_args, &print_format_args);
  if (argc - options.option_count > 2) {
    strcpy(str_search_args.search_str, argv[argc - 2]);
    strcpy(file_name, argv[argc - 1]);
    p_input_file = fopen(file_name, "r");
    if (p_input_file == NULL) {
      printf("failed to open file %s\n", file_name);
      exit(-1);
    }
  } else {
    strcpy(str_search_args.search_str, argv[argc - 1]);
    p_input_file = stdin;
  }
  if ((_E & options.option_flag) == _E) {
    strcpy(str_search_args.search_str, str_search_args.regex_str);
  }
  regex_member** member_list = (regex_member**)malloc(sizeof(regex_member*) * (strlen(str_search_args.regex_str) + 1));
  int member_list_len = 0;
  member_list = regex_parser(str_search_args.regex_str, member_list, &member_list_len);
  while (fgets(str_search_args.line, MAX_BUFFER, p_input_file) != NULL) {
    if ((_c & options.option_flag) == _c) {
      if (search_str(str_search_args.line, str_search_args.search_str, member_list, options.option_flag)) {
        print_format_args.line_num++;
      }
    } else {
      printer(p_input_file, &str_search_args, &print_format_args, member_list, options.option_flag);
      print_format_args.line_num++;
    }
  }
  if ((_c & options.option_flag) == _c)
    printf("%d\n", print_format_args.line_num - 1);
  fclose(p_input_file);
  free_regex_member_list(member_list);
  free(member_list);
  return 0;
}
