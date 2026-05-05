#include <stdio.h>
#include <stdlib.h>

char *strncpyd(char *dest, const char *src, int size)
{
    int i = 0;
    while(i != size && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    if(i < size) {
        for(; i < size; i++)
            dest[i] = '\0';
    }

    return dest;
}


int main()
{
    char m[] = "This is test string:-)", d[30];
    int i = 0;
    strncpyd(d, m, sizeof(d) - 1);
    while(d[i]) {
        printf("%c", d[i]);
        i++;
    }
    printf("\n");
    return 0;
}
