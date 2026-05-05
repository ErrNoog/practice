#include <stdio.h>
#include <stdlib.h>


struct item {
    int data;
    struct item *prev, *next;
};


struct item* car(char c, struct item *addr) 
{
	struct item *tmp;
	tmp = malloc(sizeof(*tmp));
	tmp->data = c;
	tmp->next = addr;
	addr = tmp;
	return addr;
}


void watch_list(struct item *addr) {
	while(addr) {
		printf("%c", addr->data);
		addr = addr->next;
	}	
}


struct item* delete_arr(struct item* addr) {
    while(addr) {
	    struct item *tmp = addr;
        addr = addr->prev;
	    free(tmp);
    }
	return addr;
}


void rev_s(struct item *addr) {
	struct item *rev = NULL, **last = &addr;
    while(*last) {
        while(addr->data != ' ') {
            rev = car(addr->data, rev);
            addr = addr->next;
        }
        addr = addr->next;
        watch_list(rev);
		printf(" ");
	    rev = delete_arr(rev);
        last = &addr;
    }
    printf("\n");
}


int main () {
	struct item *del = NULL, *first = NULL;
	int c;
	c = ' ';
	first = car(c, first);
    while(c != EOF) {  
        c = ' ';
	    first = car(c, first);
        del = first;
        while((c = getchar()) != '\n') {
            if(c == EOF) { break; }
		    first = car(c, first);
        }
        if(c == EOF) { break; }
	    rev_s(first);
	    first = delete_arr(del);
    }
	return 0;
}
