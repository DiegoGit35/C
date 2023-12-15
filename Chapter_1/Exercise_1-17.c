#include <stdio.h>
#define MAXLENGTH 1000
/* Write a program to print all input lines that are longer than 80 characters*/

int getLength(char line[], int maxline);

// leer input
int main(int argc, char const *argv[])
{
    int length;
    char line[MAXLENGTH]; 

    while ((length = getLength(line, MAXLENGTH)) > 0)
    {
        if(length > 80)
            printf("%s", line);
            
    }

    return 0;
}

int getLength(char line[], int maxlength){
    int c, i;

    for (i = 0; i < maxlength && (c = getchar()) != EOF && c != '\n'; i++)
    {
        line[i] = c;
    }
    if(c == '\n'){
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return i;
}
    