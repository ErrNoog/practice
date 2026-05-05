#include <stdio.h>
#include <stdlib.h>


void *memcpyd(void *dst, const void *src, int size)
{
	char *d = (char*)dst;
	const char *s = (const char*)src;
	while(size--) {
        *d++ = *s++;
	}
	return dst;
}


void push_arr(void *a, int value, int size)
{
    int i;
    char *s = (char*)a;
	for(i = 0; i < size; i++) {
		s[i] = value;
	} 
}


void print_arr(void *a, char *name)
{
    printf("%s:", name);
    char *s = (char*)a;
    while(*s) {
		printf("%d ", *s++);
	}
	printf("\n");
}


int main()
{
	int *p = malloc(10*sizeof(int));
	int *q = malloc(10*sizeof(int));
	int *a = p;
	int *b = q;
	
	push_arr(a, 4, 10);
    print_arr(a, "a");    
	
    push_arr(b, 2, 5);
    print_arr(b, "b");    

	memcpyd(b, a, 10);
	printf("after used memcpyd\n");

    print_arr(a, "a");    
    print_arr(b, "b");    
	return 0;
}
