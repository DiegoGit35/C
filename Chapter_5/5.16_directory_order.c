/* Add the -d ("directory order") option, which makes comparisons only on
letters, numbers and blanks. Make sure it works in conjunction with -f. */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 200
#define NUMERIC 1
#define REVERSE 2
#define FOLD 4
#define DIRECTORY 8

char *lineptr[MAXLINES];
static char option = 0;

int getLine(char s[], int lim);
int readLines(char *lineptr[], int nlines);
void writeLines(char *lineptr[], int nlines);
void Qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *, const char *);
int Mystrcmp(const char *, const char *);
void Rev(void *lineptr[], int nlines);

int main(int argc, char const *argv[])
{
    char c;
    int nlines;

    if ((*++argv)[0] == '-' && argc > 1)
        while (c = *++argv[0])
        {
            switch (c)
            {
            case 'n':
                option += NUMERIC;
                break;
            case 'r':
                option += REVERSE;
                break;
            case 'f':
                option += FOLD;
                break;
            case 'd':
                option += DIRECTORY;
                break;
            default:
                printf("illegal option %c\n", c);
                argc = 1;
                break;
            }
        }

    if ((nlines = readLines(lineptr, MAXLINES)) >= 0)
    {
        Qsort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(option & NUMERIC ? numcmp : Mystrcmp));
        if (option & REVERSE)
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

int isAlfaNum(char s)
{
    return (64 < s && s < 91 || 97 <= s && s < 122 || s == ' ');
}

int toLowerCase(char s)
{
    char aux;
    aux = s;
    if (64 < s && s < 91)
    {
        aux += 32;
    }
    return aux;
}

int Mystrcmp(const char *s1, const char *s2)
{
    char aux1, aux2;
    int dirOrder = option & DIRECTORY;
    int foldOrder = option & FOLD;
    do
    {
        // aux1 = s1[i];
        // aux2 = s2[i];
        if (dirOrder)
        {
            while (!isAlfaNum(*s1) && *s1 != ' ' && *s1 != '\0')
                s1++;
            while (!isAlfaNum(*s2) && *s2 != ' ' && *s2 != '\0')
                s2++;
        }
        aux1 = foldOrder ? toLowerCase(*s1) : *s1;
        s1++;
        aux2 = foldOrder ? toLowerCase(*s2) : *s2;
        s2++;

        if (aux1 == aux2 && aux1 == '\0')
            return 0;
    } while (aux1 == aux2);
    return aux1 - aux2;
}

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
