#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "array.h"
#include "bigline.h"

int main(int argc, char **argv) 
{
    item* line_from_file = NULL;
    item* array_arr = NULL;
    item* biggest_arr = NULL;
    FILE *f;
    long i;
    if(argc < 2) {
        fprintf(stderr, "Too few arguments\n");
        return 1;
    }
    for(i = 1; i < argc; i++) {
        f = fopen(argv[i], "r");
        if(!f) {
            perror(argv[i]);
            exit(1);
        } 
        line_from_file = output_from_file(f);
        if(line_from_file) {
            array_arr = make_arr_of_arr(argv[i], line_from_file);
        }
    }
    biggest_arr = find_biggest_line(array_arr);
    if(argc < 3) { 
        array_arr = show_arr_in_stdout(array_arr);
        printf("\n");
    } else
        print_all_line(array_arr, biggest_arr);
    return 0;
}
