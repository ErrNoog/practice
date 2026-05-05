#include <stdio.h>
#include <stdlib.h>

char *strdupd(const char *s)
{
    char *ptr = NULL;
    int i = 0;
    while(s[i])
        i++;

    ptr = malloc(i*sizeof(char));
    i = 0;
    while(s[i]) {
        ptr[i] = s[i];
        i++;
    }
    return ptr;
}


int main()
{
    char *k = NULL;
    char m[] = "This text for testing program: strdupd!";
    int i = 0;
    k = strdupd(m);
    while(k[i]) {
        printf("%c", k[i]);
        i++;
    }
    free(k);
    printf("\n");
    return 0;
}
