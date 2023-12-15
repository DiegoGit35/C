#include <stdio.h>
#define MAXLENGTH 1000

int readLine(char line[], int maxlegth);
void reverse(char line[], int maxlength);

int main(){
    int i;
    char line[MAXLENGTH];

    i = readLine(line, MAXLENGTH);
    reverse(line, i);
    printf("%s\n", line);
    return 0;
}

int readLine(char line[], int maxlength){
    int c, i;

    for (i = 0; i < maxlength && (c = getchar()) != EOF; i++)
    {
        line[i] = c;
    }
    line[i+1] = '\0'; 
    // printf("%s", line);
    return i;
}

void reverse(char line[], int length){
    char aux[length];
    int i;

    for (i = 0; i <= length && (line[i] != '\0'); i++)
    {
        // printf("%d\n", i);
        // printf("%c", line[length-i-1]);
        aux[i] = line[length-i-1];
    }
    // aux[length] = '\0';
    // printf("%d\n\n", i);
    for (i = 0; i < length && (aux[i] != '\0'); i++)
    {
        if(aux[i] != '\n')
            line[i] = aux[i];
    }
    line[length] = '\0';
    printf("\n");
    // printf("%s", line);
}