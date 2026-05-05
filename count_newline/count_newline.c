#include <stdio.h>
#include <errno.h>

int main(int argc, char **argv) {
    FILE *f;
    char c;
    long count_newline_in_file = 0;
    if(argc < 2) {
        fprintf(stderr, "specify the file name\n");
        return 1;
    }
    f = fopen(argv[1], "r");
    if(!f) {
        perror(argv[1]);
        return 2;
    }
    while((c = fgetc(f)) != EOF) {
        if(c == '\n')
            count_newline_in_file++;
    }
    fclose(f);
    printf("%ld ", count_newline_in_file++);
    printf("%s\n", argv[1]);
    return 0;
}
