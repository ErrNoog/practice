#include <stdio.h>

char *strcpyd(char *dest, const char *source)
{
   int i = 0;
   while(source[i] != '\0') {
       dest[i] = source[i];
       i++;
   }
   return dest;
}


int main()
{
    char s[] = "Hello, World!", d[sizeof(s)]; 
    int i = 0;
    strcpyd(d, s);
    while(d[i] != '\0') {
        printf("%c", d[i]);
        i++;
    }
    printf("\n");
    return 0;
}
