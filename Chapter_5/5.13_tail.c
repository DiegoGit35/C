/* write the program tail, which prints the last n lines of its input. By default, n
is set to 10, let us say, but it can be changed by an optional argument so that
    tail -n
prints the last n lnes. The program should behave rationally no matter how unreasonable the
input or the value n. Write the program so it makes the best use of available storage; lines
should be stored as in the sorting program of Section 5.6, not in a two-dimentional array of
fixed size*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFLINES 10 
#define LINES 100   
#define MAXLEN 100  

// int getLine(char [], int );
void error(char *);
int getLine(char *, int);

int main(int argc, char *argv[])
{
    char *p;
    char *buf;
    char *bufend;
    char line[MAXLEN];
    char *lineptr[LINES];
    int first, i, last, len, n, nlines;


    if (argc == 1)
        printf("error, not enough arguments");
    else if (*(++argv)[0] == '-' && argc == 3)
    {
        n = atoi(*++argv);
    }
    else
        n = DEFLINES;

    for (i = 0; i < LINES; i++)
        lineptr[i] = NULL;
    if ((p = buf = malloc(LINES * MAXLEN)) == NULL)
        error("fail: cannot allocate buf");
    bufend = buf + LINES * MAXLEN;
    last = 0;
    nlines = 0;
    while ((len = getLine(line, MAXLEN)) > 0)
    {
        if (p + len + 1 >= bufend)
            p = buf;
        lineptr[last] = p; 
        strcpy(lineptr[last], line); 
        if (++last >= LINES)
            last = 0;
        p += len + 1;
        nlines++;
    }
    if (n > nlines)
        n = nlines;
    first = last - n;
    if (first < 0)
        first += LINES;
    for (i = first; n-- > 0; i = (i + 1) % LINES)
        printf("%s", lineptr[i]);
    return 0;
}


/* cambiar array por puntero */
int getLine(char *s, int lim){
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void error(char *s)
{
    printf("%s\n", s);
    exit(1);
}
