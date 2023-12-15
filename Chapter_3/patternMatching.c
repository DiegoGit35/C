#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
#define PATTERN "ould"

void readLine(char line[]);
void printIfFindedPattern(char line[]);


void main(){
    char line[MAXLINE];

    printf("PATTERN value: %ld\n\n", strlen(PATTERN));

    readLine(line);
    printIfFindedPattern(line);
}


void readLine(char line[]){
    char c;
    for (int i = 0; (c = getchar()) != EOF; i++)
    {
        line[i] = c;   
    }
}

void printIfFindedPattern(char line[]){
    char aux[] = "";
    int counter, ban;
    counter = ban = 0;
    for (int j = 0; j < strlen(PATTERN); j++){
        for (int i = 0; line[i] != '\0'; i++)
        {
            aux[i] = line[i];
            if (line[i] == PATTERN[counter] && ban == 1){
                ban = 1;
                counter++;
            }
            else if(line[i] == PATTERN[counter]){
                ban = 0;
                counter = 0;
            }
        }
        if(counter == strlen(PATTERN))
            printf("%s\n", aux);
    }
}