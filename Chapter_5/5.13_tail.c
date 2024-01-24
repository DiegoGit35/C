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


#define     DEFLINES    10  /* default # of lines to print */
#define     LINES       100 /* max # of lines to print */
#define     MAXLEN      100 /* max lenght of an input line */

void error(char *);
int getLine(char *, int);


int main (int argc , char *argv[]){
    char *p;
    char *buf;
    char *bufend;
    char line[MAXLEN];
    char *lineptr[LINES];
    int first, i, last, len, n, nlines;

    if (argc == 1)
        printf("error, no hay suficientes argumentos\n");
    else if(*(++argv)[0] == '-')
}
