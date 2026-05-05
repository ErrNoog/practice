#include <stdio.h>
#include <stdlib.h>

#define LENGHT_STR int 

int count_symbols(const char *arr) { 
    LENGHT_STR str = 0;
    while(arr[str] != '\0') {
        str++;
    }
    return str;
}

int main() 
{
    char m[4096];
    LENGHT_STR l, c, i = 0;
    while((c = getchar()) != '\n') {
        m[i] = c;
        i++;
    }
    l = count_symbols(m);
    printf("%d\n", l);
    return 0;
}
