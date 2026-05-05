#include <stdio.h>

char *strstrd(const char *haystack, const char *needle)
{
    int i = 0;
    while(haystack[i]) {
        if(haystack[i] == *needle) {
            int n = 0, mem = i;
            while(needle[n]) {
                if(needle[n] != haystack[i])
                    break;
                n++;
                i++;
            }
            if(needle[n] == '\0')
                return (char*)haystack + mem;
        }
        i++;
    }
    return NULL;
}

int main()
{
    char s[] = "abrakadabra";
    char *p = NULL;
    p = strstrd(s, "abraka");
    if(p != NULL)
        printf("%s\n", p);
    return 0;
}
