#include <stdio.h>

void *memsetd(void *memory, int value, int size)
{
    int i;
    unsigned char *p = memory;
    for(i = 0; i < size; i++) {
        value = value & 0xFF;
        p[i] = value;
    }
    memory = p;
    return memory;
}

int main()
{
    char a[] = "Every programmer should khow a function memset!";
    memsetd(a, '_', 12);
    printf("%s\n", a);
    return 0;
}
