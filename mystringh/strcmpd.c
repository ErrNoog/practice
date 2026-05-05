#include <stdio.h>


int strcmpd(const char *s1, const char *s2)
{
    unsigned int i = 0;
    for(;;i++) {
        if(s1[i] != s2[i]) {
            if(s1[i] < s2[i] && s2[i]) {
                return -1;
            }
            else if(s1[i] > s2[i] && s1[i])
                return 1;
        }
        if(!s1[i] && !s2[i])
            return 0;
    }
}


int main()
{
    int res;
    char s1[] = "Zhis is string number xne";
    char s2[] = "Zhis is string number xne";
    res = strcmpd(s1, s2);
    if(res == 1)
        printf("%s\n", s1);
    else if(res == -1)
        printf("%s\n", s2);
    if(!strcmpd(s1, s2))
        printf("Equal!\n");
    return 0;
}
