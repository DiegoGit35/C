/* Modify the sort program to handle a -r flag, which indicates sorting in reverse
(decreasing) order. Be sure that -r works with -n */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int getLine(char s[], int lim);
int readLines(char *lineptr[], int nlines);
void writeLines(char *lineptr[], int nlines);
void Qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *, const char *);
void Rev(void *lineptr[], int nlines);

int main(int argc, char const *argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;

    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-n") == 0)
        {
            numeric = 1;
            continue;
        }
        if (strcmp(argv[i], "-r") == 0)
        {
            reverse = 1;
            continue;
        }
    }

    if ((nlines = readLines(lineptr, MAXLINES)) >= 0)
    {
        Qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        if (reverse == 1)
            Rev((void **)lineptr, nlines);
        writeLines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}

#include <stdlib.h>
int numcmp(const char *s1, const char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

#define MAXLEN 1000
void swap(void *v[], int, int);

int readLines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getLine(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writeLines(char *lineptr[], int nlines)
{
    int i;

    printf("\t\t");
    for (i = 0; i < nlines; i++)
    {
        printf(" %s ", lineptr[i]);
    }
    printf("\n");
}

void Qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;

    if (left >= right)
    {

        return;
    }
    swap(v, left, (left + right) / 2);

    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    Qsort(v, left, last - 1, comp);
    Qsort(v, last + 1, right, comp);
}

void Rev(void *v[], int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        swap(v, i, len - i - 1);
    }
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
