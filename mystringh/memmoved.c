#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *memmoved( void *dst,
			    const void *src,
			    int size )
{
	int i;
	char *pd = (char*)dst;
	char *ps = (char*)src;
	if(dst < src) {
		for(i = 0; i < size; i++) {
			pd[i] = ps[i];
		}
	} else if(dst > src) {
		int ds = size - 1;
		for(i = 0; i < size; i++, ds--) {
			pd[ds] = ps[ds];
		}
	}
	return dst;
}


int main()
{
	printf("memmove:\n");
	char str[] = "abcedfgrhjop";
    char *p = malloc(12*sizeof(char));
	printf("str1:%s\n", str);
	memmove(p, str, 12);
	printf("str2:%s\n", p);
	
	printf("memmoved:\n");
	char ttt[] = "abcedfgrhjop";
    char *q = malloc(12*sizeof(char));
	printf("ttt1:%s\n", ttt);
	memmoved(q, ttt, 12);
	printf("ttt2:%s\n", q);
	return 0;
}
