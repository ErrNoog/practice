#include <stdio.h>


char *strchrd(const char *s, int c)
{
    unsigned int i = 0;
    while(s[i]) {
        if(s[i] == c)
            return (char*)s + i;
        i++;
    }
    return NULL;
}


int main()
{
    char s[] = "This string for traning";
    char *res = strchrd(s, '9');
    if(res != NULL)
        printf("%s\n", res);
    else
        printf("NULL\n");
    return 0;
}
