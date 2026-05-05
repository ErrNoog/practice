#include <stdio.h>


int strncmpd(const char *s1, const char *s2, int n)
{
    unsigned int i;
    for(i = 0; i < n; i++) {
        if(s1[i] != s2[i]) {
            if(s1[i] < s2[i] && s2[i]) {
                return -1;
            }
            else if(s1[i] > s2[i] && s1[i])
                return 1;
        }
        if(!s1[i] && !s2[i])
            break;
    }
    return 0;
}


int main()
{
    char s1[] = "xest string";
    char s2[] = "zest string";
    int res;
    res = strncmpd(s1, s2, 5);
    if(res == 1)
        printf("%s\n", s1);
    else if(res == -1)
        printf("%s\n", s2);
    if(!strncmpd(s1, s2, 5))
        printf("Equal!\n");
    return 0;

}
