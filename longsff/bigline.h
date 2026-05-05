#ifndef BIGLINE_H_SENTRY
#define BIGLINE_H_SENTRY

#define MOST_BIG_LINE "\033[33m*\033[0m" 
#define NAME_OF_FILE "\033[35m%c\033[0m"

item* longest_line_in_file(item *first, item *second, item **slast);

item* output_from_file(FILE *f);

item* make_arr_of_arr(char *argv, item* addr);

item* find_biggest_line(item* addr);

item* show_arr_in_stdout(item* addr);

void print_all_line(item* all_arr, item* big_line);

#endif
