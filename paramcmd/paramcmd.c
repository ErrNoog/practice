#include <stdio.h>

/*-------------SUBPROGRAMME--------------*/
void concid(int i, int argc, char **argv) {
	int s, n, r, c;
    c = r = s = 0;
    for(n = 2; n < argc; n++) {	
        while((argv[i])[s] != '\0') {
			if((argv[i])[s] == (argv[n])[s])
				r++;	
			s++;
		}
		if(r == s && (argv[n])[s] == '\0') {
			c++;
			if(c > 1)
				argv[n] = "";
			else {
				if((argv[i])[0] == '\0')
					printf("%s", argv[i]);
				else
					printf("%s ", argv[i]);
			}
		}
		r = s = 0;
	}
}



/*--------------------G)--------------------*/
void common(int argc, char **argv) {
	int i, n, r, s, f, w, d;
	char c;
	d = w = f = r = s = n = 0;
	while((argv[2])[n]) { w++; n++; }
	n = 0;
	for(i = 2; i < argc; i++) {
		while((argv[2])[n]) {
			if((argv[2])[n] == (argv[i])[n])
				r++;
			n++;
		}
		if(r == n && (argv[i])[n] == '\0') {
			if(d == 0) {
				printf("%s ", argv[i]);
				d = 1; 
			} else
				argv[i] = "";
		} n = r = 0;
	}
	while((argv[2])[n]) {
		c = (argv[2])[n];
		for(i = 3; i < argc; i++) {
			while((argv[i])[s] != '\0') {
				if(c == (argv[i])[s])
					r++;
				s++;
			} if(r == s && s == w) {
				if(f == 0) {
					concid(i, argc, argv);
					f = 1;
				}
				argv[i] = "";
			} if(r > 0) {
				concid(i, argc, argv);
				argv[i] = "";
			} r = s = 0;
		} n++; 
    }
	printf("\n");	
}


/*--------------------F)--------------------*/
void latin(int argc, char **argv) {
	int i, n, r;
	char c;
	n = r = 0;
	for(i = 2; i < argc; i++) {
		while((argv[i])[n]) {
			c = (argv[i])[n];
			if((c >= 'A' && c <= 'Z') || 
			   (c >= 'a' && c <= 'z'))
				r++;
			n++;
		}
		if(r > 0)
			concid(i, argc, argv);
		n = r = 0;
	}
	printf("\n");
}

/*--------------------E)--------------------*/
void samelett(int argc, char **argv) {
	int i, n, t, f, r;
	r = f = n = t = 0;
	for(i = 2; i < argc; i++) {
		while((argv[i])[n]) {
			while((argv[i])[t]) {
				if((argv[i])[t] == (argv[i])[n])
					r++;
				t++;
			} if(r == t)
				f = 1;
			t = r = 0;
			n++;
		} if(f == 1)
			concid(i, argc, argv);
		f = n = 0;
	}
	printf("\n");
}

/*--------------------D)--------------------*/
void digit(int argc, char **argv) {
	int i, s, r;
	r = s = i = 0;
	for(i = 2; i < argc; i++) {
		while((argv[i])[s] != '\0') {
			if((argv[i])[s] >= 48 && (argv[i])[s] <= 57)
				r++;
			s++;
		}
		if(r == s)
			concid(i, argc, argv);	
		r = s = 0;
	}
	printf("\n");
}


/*--------------------C)---------------------*/
void dotandat(int argc, char **argv) {
	int i, n, t, at, dot;
	n = t = at = dot = 0; 
	for(i = 2; i < argc; i++) {
		while((argv[i])[n] != '\0') {
			if((argv[i])[n] == '@')
				at++;
			else if((argv[i])[n] == '.')
				dot++;
			n++;
		}
		if(at == 1 && dot >= 1) {
            concid(i, argc, argv);
        }
		at = dot = n = 0;
	}
	printf("\n");
}


/*--------------------B)---------------------*/
void repeatlett(int argc, char **argv) {
    int i, n, r, t, f;
    f = t = n = r = 0;
    for(i = 2; i < argc; i++) {
        while((argv[i])[n] != '\0') {
            while((argv[i])[t] != '\0') {
                if((argv[i])[t] == (argv[i])[n])
                    r++;
                t++;
            }
            if(r > 1)
                f = 1;
            t = r = 0;
            n++;
        }
        if(f != 1)
            concid(i, argc, argv);
        f = n = 0;
    }
    printf("\n");
}


/*--------------------A)---------------------*/
void longestparam(int argc, char **argv) {
    int i, n, r;
    char *av;
    r = n = 0;
    for(i = 2; i < argc; i++) {
        while((argv[i])[n] != '\0') {
            n++;
            if(r < n) {
                r = n;
                av = argv[i];
            }
        }
        n = 0;
    }
    printf("%s %d\n", av, r);
}



/*============MAIN=============*/
int main(int argc, char **argv) {
    if(argc > 1) {
        if((argv[1])[0] == '-' && (argv[1])[1] == 'b')
            repeatlett(argc, argv);
        else if((argv[1])[0] == '-' && (argv[1])[1] == 'a')
            longestparam(argc, argv);
        else if((argv[1])[0] == '-' && (argv[1])[1] == 'c')
            dotandat(argc, argv);
        else if((argv[1])[0] == '-' && (argv[1])[1] == 'd')
            digit(argc, argv);
        else if((argv[1])[0] == '-' && (argv[1])[1] == 'e')
            samelett(argc, argv);
        else if((argv[1])[0] == '-' && (argv[1])[1] == 'f')
            latin(argc, argv);
        else if((argv[1])[0] == '-' && (argv[1])[1] == 'g')
            common(argc, argv);
        else if((argv[1])[0] == '-' && (argv[1])[1] == 'h') {
            printf("usage: ./paramcmd [PARAMETER] [WORDS]...\n");
            printf("    -a: the longest argument;\n");
            printf("    -b: arguments without duplicate letters;\n");
            printf("    -c: arguments with the ""@"" and at least one ""."";\n");
            printf("    -d: arguments with only numbers;\n");
            printf("    -e: arguments consisting of one character;\n");
            printf("    -f: arguments that contain at least one Latin letter;\n");
            printf("    -g: arguments that contain at least one common\n");
            printf("                    letter with the first argument;\n");
        }
        else
            printf("paramdcm: enter ""-h"" for help\n");
    } 
    return 0;
}
