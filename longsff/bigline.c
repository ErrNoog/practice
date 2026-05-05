#include <stdio.h>

#include "array.h"
#include "bigline.h"

    item* longest_line_in_file(item *first, item *second, item **slast) 
    {
        item *begf = first, *begs = second;
        while(first) {
            if(!second)
                break;
            else
                second = second->next;
            first = first->next;
        }
        if(first && !second) {
            first = begf;
            delete_arr(second);
            while(first) {
                create_arr(first->data, &second, slast);
                first = first->next;
            }
        } else
            second = begs;
        first = begf;
        delete_arr(first);
        return second;
    }    


    item* output_from_file(FILE *f) 
    {
        item *first_arr = NULL, *flast = NULL;
        item *second_arr = NULL, *slast = NULL;
        int c = 0;
        while(c != EOF) {
            item *b = first_arr;
            while((c = fgetc(f)) != '\n' && c != EOF)
                create_arr(c, &first_arr, &flast);
            if(c != EOF)
                create_arr(c, &first_arr, &flast);
            second_arr = longest_line_in_file(first_arr, second_arr, &slast);
            first_arr = b;
            delete_arr(first_arr);
        }
        return second_arr;
        delete_arr(second_arr);
    }


    item* make_arr_of_arr(char *argv, item* addr) 
    {
        static item *all_arr_f = NULL, *all_arr_l = NULL;
        long i = 0;
        while(argv[i]) { 
            create_arr(argv[i], &all_arr_f, &all_arr_l);
            i++;
        }
        create_arr(':', &all_arr_f, &all_arr_l);
        while(addr) {
            create_arr(addr->data, &all_arr_f, &all_arr_l);
            addr = addr->next;
        }
        return all_arr_f;
    }

    
    item* find_biggest_line(item* addr) 
    {
        item *first_arr = NULL, *flast = NULL;
        item *second_arr = NULL, *slast = NULL;
        while(addr) {
            item *b = first_arr;
            while(addr->data != ':') {
                addr = addr->next;
            }
            addr = addr->next;
            while(addr->data != '\n') {
                create_arr(addr->data, &first_arr, &flast);
                addr = addr->next;
            }
            create_arr(addr->data, &first_arr, &flast);
            second_arr = longest_line_in_file(first_arr, second_arr, &slast); 
            first_arr = b;
            delete_arr(first_arr);
            addr = addr->next;
        }
        return second_arr;
        delete_arr(second_arr);
    }


    item* show_arr_in_stdout(item* addr) 
    {
        while(addr->data != ':') {
            printf(NAME_OF_FILE, addr->data);
            addr = addr->next;
        }
        while(addr->data != '\n') {    
            printf("%c", addr->data);
            addr = addr->next;
        }
        return addr;
    }

    
    void print_all_line(item* all_arr, item* big_line) 
    {
        item *startb = big_line;
        while(all_arr) {
            item *bega = all_arr;
            big_line = startb;
            while(all_arr->data != ':' && big_line->data != ':') {
                all_arr = all_arr->next;
            }

            while(all_arr->data != '\n' && big_line) {
                if(all_arr->next->data == '\n' && !big_line->next) {
                    printf(MOST_BIG_LINE);
                }
                big_line = big_line->next;
                all_arr = all_arr->next;
            }
            
            all_arr = bega;
            all_arr = show_arr_in_stdout(all_arr); 
            printf("\n");
            all_arr = all_arr->next;
        }
    }
