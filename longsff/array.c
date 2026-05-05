#include <stdio.h>
#include <stdlib.h>
#include "array.h"

#define MALLOCITEM malloc(sizeof(item)) 
    

void create_arr(int c, item **first, item **last) 
{
    item *tmp = NULL;
    tmp = MALLOCITEM;
    tmp->data = c;
    tmp->next = NULL;
    if(!(*first))
        *first = *last = tmp;
    else {
        (*last)->next = tmp;
        *last = (*last)->next;
    }
} 

    
void delete_arr(item *addr) 
{
    while(addr) {
        item *tmp = addr;
        addr = addr->next;
        free(tmp);
    }
}


void watch_list(item *addr) 
{
    item *look = addr;
    while(look) {
        printf("%c", look->data);
        look = look->next;
    }
}
